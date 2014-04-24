// mqtt.cpp: implementation of the CMQTT class.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version
// 2 of the License, or (at your option) any later version.
// 
// This file is part of the VSCP Project (http://www.vscp.org) 
//
// Copyright (C) 2000-2014 Ake Hedman, 
// Grodans Paradis AB, <akhe@grodansparadis.com>
// 
// This file is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this file see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.
//

#include <stdio.h>
#include "unistd.h"
#include "stdlib.h"
#include <string.h>
#include "limits.h"
#include "syslog.h"
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <signal.h>
#include <ctype.h>
#include <libgen.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/uio.h>
#include <net/if.h>

#include "wx/wxprec.h"
#include "wx/wx.h"
#include "wx/defs.h"
#include "wx/app.h"
#include <wx/xml/xml.h>
#include <wx/listimpl.cpp>
#include <wx/thread.h>
#include <wx/tokenzr.h>
#include <wx/datetime.h>

#include "../../../../common/vscphelper.h"
#include "../../../../common/vscptcpif.h"
#include "../../../../common/vscp_type.h"
#include "../../../../common/vscp_class.h"
#include "mqtt.h"

//////////////////////////////////////////////////////////////////////
//								Subscriber
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// mqtt_subscribe - Constructor
//

mqtt_subscribe::mqtt_subscribe( const char *id,
                                    const char *topic,
                                    const char *host,
                                    int port,
                                    int keepalive ) : mosquittopp(id)
{
    connect(host, port, keepalive);
}

//////////////////////////////////////////////////////////////////////
// mqtt_subscribe Destructor
//

mqtt_subscribe::~mqtt_subscribe()
{
    ;
}

//////////////////////////////////////////////////////////////////////
// on_connect
//

void mqtt_subscribe::on_connect(int rc)
{
	if (0 == rc) {
		// Only attempt to subscribe on a successful connect. 
		subscribe(NULL, m_pObj->m_topic.ToAscii() );
	}
}

//////////////////////////////////////////////////////////////////////
// on_message
//

void mqtt_subscribe::on_message(const struct mosquitto_message *message)
{
	vscpEventEx eventEx;

	if ( !strcmp( message->topic, m_pObj->m_topic.ToAscii() ) ) {
        
		wxString str = wxString::FromAscii((const char *) message->payload);
		if (getVscpEventExFromString(&eventEx, str)) {
            
            vscpEvent *pEvent = new vscpEvent;
            if (NULL != pEvent) {
                
                pEvent->sizeData = 0;
                pEvent->pdata = NULL;
                
                if ( doLevel2FilterEx( &eventEx, &m_pObj->m_vscpfilter ) ) {
                    
                    if ( convertVSCPfromEx( pEvent, &eventEx ) ) {
                        m_pObj->m_mutexReceiveQueue.Lock();
                        m_pObj->m_receiveList.push_back(pEvent);
                        m_pObj->m_semReceiveQueue.Post();
                        m_pObj->m_mutexReceiveQueue.Unlock();
                    }
                    else {
                        
                    }
                }
                else {
                    deleteVSCPevent(pEvent);
                }
            }
		}
	}
}

//////////////////////////////////////////////////////////////////////
// on_subscribe
//

void mqtt_subscribe::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
	;
}


//////////////////////////////////////////////////////////////////////
//								Publisher
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// mqtt_publish - Constructor
//

mqtt_publish::mqtt_publish( const char *id,
                            const char *topic,
                            const char *host,
                            int port,
                            int keepalive ) : mosquittopp(id)
{
    connect(host, port, keepalive);
}

//////////////////////////////////////////////////////////////////////
// mqtt_subscribe Destructor
//

mqtt_publish::~mqtt_publish()
{
	;
}

//////////////////////////////////////////////////////////////////////
// on_connect
//

void mqtt_publish::on_connect(int rc)
{
	//printf("Connected with code %d.\n", rc);
	if (rc == 0) {
		// Only attempt to subscribe on a successful connect. 
		//subscribe( NULL, m_pObj->m_topic.ToAscii() );
	}
}

//////////////////////////////////////////////////////////////////////
// on_message
//

void mqtt_publish::on_message(const struct mosquitto_message *message)
{
    /*
	double temp_celsius, temp_farenheit;
	char buf[51];

	if (!strcmp(message->topic, "temperature/celsius")) {
		memset(buf, 0, 51 * sizeof(char));
		// Copy N-1 bytes to ensure always 0 terminated. 
		memcpy(buf, message->payload, 50 * sizeof(char));
		temp_celsius = atof(buf);
		temp_farenheit = temp_celsius * 9.0 / 5.0 + 32.0;
		snprintf(buf, 50, "%f", temp_farenheit);
		publish(NULL, "temperature/farenheit", strlen(buf), buf);
	}
    */
    
}

//////////////////////////////////////////////////////////////////////
// on_subscribe
//

void mqtt_publish::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
	printf("Subscription succeeded.\n");
}

//////////////////////////////////////////////////////////////////////
// Cmqtt
//

Cmqtt::Cmqtt()
{
	m_bQuit = false;
	m_pthreadWork = NULL;
	m_bSubscribe = true;
    m_bSimplify = false;
    m_simple_class = 0;
    m_simple_type = 0;
    m_simple_coding = 0;
    m_simple_zone = 0;
    m_simple_subzone = 0;
    
	clearVSCPFilter(&m_vscpfilter); // Accept all events
	::wxInitialize();
}

//////////////////////////////////////////////////////////////////////
// ~Cmqtt
//

Cmqtt::~Cmqtt()
{
	close();
	::wxUninitialize();
}


//////////////////////////////////////////////////////////////////////
// open
//
//

bool
Cmqtt::open(const char *pUsername,
                const char *pPassword,
                const char *pHost,
                short port,
                const char *pPrefix,
                const char *pConfig)
{
	bool rv = true;
	wxString str;
	wxString wxstr = wxString::FromAscii(pConfig);

	m_username = wxString::FromAscii(pUsername);
	m_password = wxString::FromAscii(pPassword);
	m_host = wxString::FromAscii(pHost);
	m_port = port;
	m_prefix = wxString::FromAscii(pPrefix);

	// Parse the configuration string. It should
	// have the following form
	// path
	// 
	wxStringTokenizer tkz(wxString::FromAscii(pConfig), _(";\n"));

	// Check if we should publish or subscribe
	if (tkz.HasMoreTokens()) {
		// Check for subscribe/publish
		str = tkz.GetNextToken();
		str.Trim();
		str.Trim(false);
		str.MakeUpper();
		if (wxNOT_FOUND != str.Find(_("PUBLISH"))) {
			m_bSubscribe = false;
		}
	}

	// Get topic from configuration string
	if (tkz.HasMoreTokens()) {
		m_topic = tkz.GetNextToken();
	}

	// Get MQTT host from configuration string
	if (tkz.HasMoreTokens()) {
		m_hostMQTT = tkz.GetNextToken();
	}

	// Get MQTT host port from configuration string
	if (tkz.HasMoreTokens()) {
		m_portMQTT = readStringValue(tkz.GetNextToken());
	}

	// Get MQTT user from configuration string
	if (tkz.HasMoreTokens()) {
		m_usernameMQTT = tkz.GetNextToken();
	}

	// Get MQTT password from configuration string
	if (tkz.HasMoreTokens()) {
		m_passwordMQTT = tkz.GetNextToken();
	}

	// Get MQTT keepalive from configuration string
	if (tkz.HasMoreTokens()) {
		m_keepalive = readStringValue(tkz.GetNextToken());
	}

	// First log on to the host and get configuration 
	// variables

	if (m_srv.doCmdOpen(m_host,
			m_port,
			m_username,
			m_password) <= 0) {
		syslog(LOG_ERR,
				"%s",
				(const char *) "Unable to connect to VSCP TCP/IP interface. Terminating!");
		return false;
	}

	// Find the channel id
	uint32_t ChannelID;
	m_srv.doCmdGetChannelID(&ChannelID);

	// The server should hold configuration data for each sensor
	// we want to monitor.
	// 
	// We look for 
	//
	//	 _type	- “subscribe” to subscribe to a MQTT topic. ”publish” to 
	//				publish events to a MQTT topic. Defaults to “subscribe”.
	//
	//	 _topic	- This is a text string identifying the topic. It is 
	//				recommended that this string starts with “vscp/”. 
	//						Defaults to “vscp”
	//
	//	 _host	- IP address or a DNS resolvable address to the remote host. 
	//				Mandatory and must be declared either in the configuration 
	//				string or in this variable. Defaults to “localhost”
	//
	//	 _port - The port to use on the remote host. Default is 1883.
	//
	//	 _user - Username used to log in on the remote sever. 
	//				Defaults to empty. 
	//
	//	 _password - Password used to login on the remote server. 
	//				Defaults to empty.
	//
	//	 _keepalive - Keepalive value for channel. Defaults to 60.
	//
	//   _filter - Standard VSCP filter in string form. 
	//				   1,0x0000,0x0006,
	//				   ff:ff:ff:ff:ff:ff:ff:01:00:00:00:00:00:00:00:00
	//				as priority,class,type,GUID
	//				Used to filter what events that is received from 
	//				the mqtt interface. If not give all events 
	//				are received.
	//	 _mask - Standard VSCP mask in string form.
	//				   1,0x0000,0x0006,
	//				   ff:ff:ff:ff:ff:ff:ff:01:00:00:00:00:00:00:00:00
	//				as priority,class,type,GUID
	//				Used to filter what events that is received from 
	//				the mqtt interface. If not give all events 
	//				are received. 
	//

	wxString strName = m_prefix +
			wxString::FromAscii("_type");
	m_srv.getVariableString(strName, &str);

	// Check for subscribe/publish
	str = tkz.GetNextToken();
	str.Trim();
	str.Trim(false);
	str.MakeUpper();
	if (wxNOT_FOUND != str.Find(_("PUBLISH"))) {
		m_bSubscribe = false;
	}

	strName = m_prefix +
			wxString::FromAscii("_topic");
	m_srv.getVariableString(strName, &m_topic);

	strName = m_prefix +
			wxString::FromAscii("_host");
	m_srv.getVariableString(strName, &m_hostMQTT);

	strName = m_prefix +
			wxString::FromAscii("_port");
	m_srv.getVariableInt(strName, &m_portMQTT);

	strName = m_prefix +
			wxString::FromAscii("_username");
	m_srv.getVariableString(strName, &m_usernameMQTT);

	strName = m_prefix +
			wxString::FromAscii("_password");
	m_srv.getVariableString(strName, &m_passwordMQTT);

	strName = m_prefix +
			wxString::FromAscii("_keepalive");
	m_srv.getVariableInt(strName, &m_keepalive);

	strName = m_prefix +
			wxString::FromAscii("_filter");
	if (m_srv.getVariableString(strName, &str)) {
		readFilterFromString(&m_vscpfilter, str);
	}

	strName = m_prefix +
			wxString::FromAscii("_mask");
	if (m_srv.getVariableString(strName, &str)) {
		readMaskFromString(&m_vscpfilter, str);
	}
    
    strName = m_prefix +
			wxString::FromAscii("_simplify");
	m_srv.getVariableString(strName, &m_simplify);
    
    if ( m_simplify.Length() ) {
        
        m_bSimplify = true; 
        
        wxStringTokenizer tkzSimple( m_simplify, _(",\n"));
        
        // simple class
        if (tkzSimple.HasMoreTokens()) {
            m_simple_class = readStringValue(tkzSimple.GetNextToken());
        }
        
        // simple type
        if (tkzSimple.HasMoreTokens()) {
            m_simple_type = readStringValue(tkzSimple.GetNextToken());
        }
        
        // simple coding
        if (tkzSimple.HasMoreTokens()) {
            m_simple_coding = readStringValue(tkzSimple.GetNextToken());
        }
        
        // simple zone
        if (tkzSimple.HasMoreTokens()) {
            m_simple_zone = readStringValue(tkzSimple.GetNextToken());
        }
        
        // simple subzone
        if (tkzSimple.HasMoreTokens()) {
            m_simple_subzone = readStringValue(tkzSimple.GetNextToken());
        }
        
    }
    else {
        m_bSimplify = false;
    }
    
    
	// Close the channel
	m_srv.doCmdClose();


	// start the workerthread
	m_pthreadWork = new CWrkThread();
	if (NULL != m_pthreadWork) {
		m_pthreadWork->m_pObj = this;
		m_pthreadWork->Create();
		m_pthreadWork->Run();
	} else {
		rv = false;
	}

	return rv;
}


//////////////////////////////////////////////////////////////////////
// close
//

void
Cmqtt::close(void)
{
	// Do nothing if already terminated
	if (m_bQuit) return;

	m_bQuit = true; // terminate the thread
	wxSleep(1); // Give the thread some time to terminate

}

//////////////////////////////////////////////////////////////////////
// addEvent2SendQueue
//

bool 
Cmqtt::addEvent2SendQueue(const vscpEvent *pEvent)
{
    m_mutexSendQueue.Lock();
	//m_sendQueue.Append((vscpEvent *)pEvent);
    m_sendList.push_back((vscpEvent *)pEvent);
	m_semSendQueue.Post();
	m_mutexSendQueue.Unlock();
    return true;
}

//////////////////////////////////////////////////////////////////////
//                Workerthread - CWrkThread
//////////////////////////////////////////////////////////////////////

CWrkThread::CWrkThread()
{
    m_pObj = NULL;
}

CWrkThread::~CWrkThread()
{
    ;
}


//////////////////////////////////////////////////////////////////////
// Entry
//

void *
CWrkThread::Entry()
{
    bool bActivity;
    wxString str;
    int rv;

    mosqpp::lib_init();

    if (m_pObj->m_bSubscribe) {

        // S u b s c r i b e
        mqtt_subscribe *pSubscribe = 
                new mqtt_subscribe( "vscpdriver",
                                        m_pObj->m_topic.ToAscii(),
                                        m_pObj->m_hostMQTT.ToAscii(),
                                        m_pObj->m_portMQTT,
                                        m_pObj->m_keepalive);
        
        // Save the object class
        pSubscribe->m_pObj = m_pObj;

        while (!TestDestroy() && !m_pObj->m_bQuit) {
           
            rv = pSubscribe->loop();

            if (rv) {
                pSubscribe->reconnect();
            }

            ::wxMilliSleep(50);

        }
    }
    else {
       
        // P u b l i s h
        mqtt_publish *pPublish = 
                new mqtt_publish( "vscpdriver",
                                        m_pObj->m_topic.ToAscii(),
                                        m_pObj->m_hostMQTT.ToAscii(),
                                        m_pObj->m_portMQTT,
                                        m_pObj->m_keepalive);

        // Save the object class
        pPublish->m_pObj = m_pObj;
        
        while (!TestDestroy() && !m_pObj->m_bQuit) {

            if (wxSEMA_TIMEOUT == m_pObj->m_semSendQueue.WaitTimeout(300)) continue;

            if (m_pObj->m_sendList.size()) {

                m_pObj->m_mutexSendQueue.Lock();
                vscpEvent *pEvent = m_pObj->m_sendList.front();
                m_pObj->m_sendList.pop_front();
                m_pObj->m_mutexSendQueue.Unlock();
                if (NULL == pEvent) continue;
                if (m_pObj->m_bSimplify) {
                    
                }
                else {
                    writeVscpEventToString( pEvent, str );
                    pPublish->publish( NULL, 
                                        m_pObj->m_topic.ToAscii(), 
                                        strlen( str.mb_str() ), 
                                        str.mb_str() );
                }
                
                // We are done with the event - remove data if any
                if (NULL != pEvent->pdata) {
                    delete [] pEvent->pdata;
                    pEvent->pdata = NULL;
                }

            } // Event received

            rv = pPublish->loop();

            if (rv) {
                pPublish->reconnect();
            }

            ::wxMilliSleep(50);

        }
        
        mosqpp::lib_cleanup();
        delete pPublish;
    
    }

    return NULL;

}

//////////////////////////////////////////////////////////////////////
// OnExit
//

void
CWrkThread::OnExit()
{
    ;
}

