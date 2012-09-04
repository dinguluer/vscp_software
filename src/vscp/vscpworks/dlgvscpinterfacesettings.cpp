/////////////////////////////////////////////////////////////////////////////
// Name:        dlgvscpinterfacesettings.cpp
// Purpose:     
// Author:      Ake Hedman
// Modified by: 
// Created:     Fri 26 Oct 2007 11:57:04 CEST
// RCS-ID:      
// Copyright:   (C) 2007-2011 Ake Hedman, Grodans Paradis AB, <akhe@grodansparadis.com>
// Licence:     
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version
// 2 of the License, or (at your option) any later version.
// 
// This file is part of the VSCP (http://www.vscp.org) 
//
// Copyright (C) 2000-2011 Ake Hedman, Grodans Paradis AB, <akhe@grodansparadis.com>
// 
// This file is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this file see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330,
//  Boston, MA 02111-1307, USA.
// 
//  As a special exception, if other files instantiate templates or use macros
//  or inline functions from this file, or you compile this file and link it
//  with other works to produce a work based on this file, this file does not
//  by itself cause the resulting work to be covered by the GNU General Public
//  License. However the source code for this file must still be made available
//  in accordance with section (3) of the GNU General Public License.
// 
//  This exception does not invalidate any other reasons why a work based on
//  this file might be covered by the GNU General Public License.
// 
//  Alternative licenses for VSCP & Friends may be arranged by contacting 
//  Grodans Paradis AB at info@Grodans Paradis AB.se, http://www.grodansparadis.com
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "dlgvscpinterfacesettings.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "wx/bookctrl.h"
////@end includes

#include <wx/tokenzr.h>
#include <wx/progdlg.h>

#include "dlgvscpinterfacesettings.h"
#include "dlgselectdaemoninterface.h"
#include "dlgvscpfilter.h"
#include "../common/vscptcpif.h"

////@begin XPM images
////@end XPM images


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// dlgVscpInterfaceSettings type definition
//

IMPLEMENT_DYNAMIC_CLASS( dlgVscpInterfaceSettings, wxPropertySheetDialog )


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// dlgVscpInterfaceSettings event table definition
//

BEGIN_EVENT_TABLE( dlgVscpInterfaceSettings, wxPropertySheetDialog )

////@begin dlgVscpInterfaceSettings event table entries
  EVT_BUTTON( ID_BUTTON_VSCP_DRIVER_SET_PATH, dlgVscpInterfaceSettings::OnButtonVscpDriverSetPathClick )

  EVT_BUTTON( ID_BUTTON_VSCP_SET_CONFIGURATION, dlgVscpInterfaceSettings::OnButtonVscpSetConfigurationClick )

  EVT_BUTTON( ID_BUTTON_SET_FILTER, dlgVscpInterfaceSettings::OnButtonSetFilterClick )

  EVT_BUTTON( ID_BUTTON_TEST_INTERFACE, dlgVscpInterfaceSettings::OnButtonTestInterfaceClick )

  EVT_BUTTON( ID_BUTTON, dlgVscpInterfaceSettings::OnButtonGetInterfacesClick )

////@end dlgVscpInterfaceSettings event table entries

END_EVENT_TABLE()


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// dlgVscpInterfaceSettings constructors
//

dlgVscpInterfaceSettings::dlgVscpInterfaceSettings()
{
  Init();
}

dlgVscpInterfaceSettings::dlgVscpInterfaceSettings( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
  Init();
  Create(parent, id, caption, pos, size, style);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// dlgVscpInterfaceSettings creator
//

bool dlgVscpInterfaceSettings::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin dlgVscpInterfaceSettings creation
  SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
  SetSheetStyle(wxPROPSHEET_DEFAULT);
  wxPropertySheetDialog::Create( parent, id, caption, pos, size, style );

  CreateButtons(wxOK|wxCANCEL|wxHELP);
  CreateControls();
  SetIcon(GetIconResource(wxT("../../../docs/vscp/logo/fatbee_v2.ico")));
  LayoutDialog();
  Centre();
////@end dlgVscpInterfaceSettings creation
  return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// dlgVscpInterfaceSettings destructor
//

dlgVscpInterfaceSettings::~dlgVscpInterfaceSettings()
{
////@begin dlgVscpInterfaceSettings destruction
////@end dlgVscpInterfaceSettings destruction
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Member initialisation
//

void dlgVscpInterfaceSettings::Init()
{
////@begin dlgVscpInterfaceSettings member initialisation
  m_panelCanal = NULL;
  m_DriverDescription = NULL;
  m_PathToDriver = NULL;
  m_DriverConfigurationString = NULL;
  m_DriverFlags = NULL;
  m_panelServer = NULL;
  m_RemoteServerDescription = NULL;
  m_RemoteServerURL = NULL;
  m_RemoteServerPort = NULL;
  m_RemoteServerUsername = NULL;
  m_RemoteServerPassword = NULL;
  m_GUID15 = NULL;
  m_GUID14 = NULL;
  m_GUID13 = NULL;
  m_GUID12 = NULL;
  m_GUID11 = NULL;
  m_GUID10 = NULL;
  m_GUID9 = NULL;
  m_GUID8 = NULL;
  m_GUID7 = NULL;
  m_GUID6 = NULL;
  m_GUID5 = NULL;
  m_GUID4 = NULL;
  m_GUID3 = NULL;
  m_GUID2 = NULL;
  m_GUID1 = NULL;
  m_GUID0 = NULL;
  m_btnTestConnection = NULL;
  m_btnGetInterfaces = NULL;
////@end dlgVscpInterfaceSettings member initialisation

	// Init filter
	clearVSCPFilter( &m_vscpfilter );

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Control creation for dlgVscpInterfaceSettings
//

void dlgVscpInterfaceSettings::CreateControls()
{    
////@begin dlgVscpInterfaceSettings content construction
  dlgVscpInterfaceSettings* itemPropertySheetDialog1 = this;

  m_panelCanal = new wxPanel;
  m_panelCanal->Create( GetBookCtrl(), ID_PANEL_INTERFACE_DRIVER, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
  m_panelCanal->SetHelpText(_("For a CANAL driver enter or edit the description below and press OK"));
  if (dlgVscpInterfaceSettings::ShowToolTips())
    m_panelCanal->SetToolTip(_("For a CANAL driver enter or edit the description below and press OK"));
  m_panelCanal->SetName(_T("canal"));
  wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
  m_panelCanal->SetSizer(itemBoxSizer3);

  wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
  itemBoxSizer3->Add(itemBoxSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

  wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer3->Add(itemBoxSizer5, 0, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText6 = new wxStaticText;
  itemStaticText6->Create( m_panelCanal, wxID_STATIC, _("Description :"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer5->Add(itemStaticText6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_DriverDescription = new wxTextCtrl;
  m_DriverDescription->Create( m_panelCanal, ID_DriverDescription, wxEmptyString, wxDefaultPosition, wxSize(300, -1), 0 );
  itemBoxSizer5->Add(m_DriverDescription, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer5->Add(52, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer3->Add(itemBoxSizer9, 0, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText10 = new wxStaticText;
  itemStaticText10->Create( m_panelCanal, wxID_STATIC, _("Path to driver :"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer9->Add(itemStaticText10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_PathToDriver = new wxTextCtrl;
  m_PathToDriver->Create( m_panelCanal, ID_PathToDriver, wxEmptyString, wxDefaultPosition, wxSize(300, -1), 0 );
  itemBoxSizer9->Add(m_PathToDriver, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxButton* itemButton12 = new wxButton;
  itemButton12->Create( m_panelCanal, ID_BUTTON_VSCP_DRIVER_SET_PATH, _("..."), wxDefaultPosition, wxSize(30, -1), 0 );
  itemBoxSizer9->Add(itemButton12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer9->Add(20, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxBoxSizer* itemBoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer3->Add(itemBoxSizer14, 0, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText15 = new wxStaticText;
  itemStaticText15->Create( m_panelCanal, wxID_STATIC, _("Device configuration string :"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer14->Add(itemStaticText15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_DriverConfigurationString = new wxTextCtrl;
  m_DriverConfigurationString->Create( m_panelCanal, ID_DriverConfigurationString, wxEmptyString, wxDefaultPosition, wxSize(300, -1), 0 );
  itemBoxSizer14->Add(m_DriverConfigurationString, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxButton* itemButton17 = new wxButton;
  itemButton17->Create( m_panelCanal, ID_BUTTON_VSCP_SET_CONFIGURATION, _("..."), wxDefaultPosition, wxSize(30, -1), 0 );
  itemBoxSizer14->Add(itemButton17, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer14->Add(20, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxBoxSizer* itemBoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer3->Add(itemBoxSizer19, 0, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText20 = new wxStaticText;
  itemStaticText20->Create( m_panelCanal, wxID_STATIC, _("Flags :"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer19->Add(itemStaticText20, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_DriverFlags = new wxTextCtrl;
  m_DriverFlags->Create( m_panelCanal, ID_DriverFlags, wxEmptyString, wxDefaultPosition, wxSize(50, -1), 0 );
  itemBoxSizer19->Add(m_DriverFlags, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer19->Add(302, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  GetBookCtrl()->AddPage(m_panelCanal, _("CANAL Driver"));

  m_panelServer = new wxPanel;
  m_panelServer->Create( GetBookCtrl(), ID_PANEL_INTERFACE_REMOTE, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
  m_panelServer->SetName(_T("server"));
  wxBoxSizer* itemBoxSizer24 = new wxBoxSizer(wxVERTICAL);
  m_panelServer->SetSizer(itemBoxSizer24);

  wxBoxSizer* itemBoxSizer25 = new wxBoxSizer(wxVERTICAL);
  itemBoxSizer24->Add(itemBoxSizer25, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

  wxBoxSizer* itemBoxSizer26 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer24->Add(itemBoxSizer26, 0, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText27 = new wxStaticText;
  itemStaticText27->Create( m_panelServer, wxID_STATIC, _("Description:"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer26->Add(itemStaticText27, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_RemoteServerDescription = new wxTextCtrl;
  m_RemoteServerDescription->Create( m_panelServer, ID_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxSize(400, -1), 0 );
  itemBoxSizer26->Add(m_RemoteServerDescription, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxBoxSizer* itemBoxSizer29 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer24->Add(itemBoxSizer29, 0, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText30 = new wxStaticText;
  itemStaticText30->Create( m_panelServer, wxID_STATIC, _("Server URL:"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer29->Add(itemStaticText30, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_RemoteServerURL = new wxTextCtrl;
  m_RemoteServerURL->Create( m_panelServer, ID_RemoteServerURL, _("localhost"), wxDefaultPosition, wxSize(400, -1), 0 );
  itemBoxSizer29->Add(m_RemoteServerURL, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxBoxSizer* itemBoxSizer32 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer24->Add(itemBoxSizer32, 0, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText33 = new wxStaticText;
  itemStaticText33->Create( m_panelServer, wxID_STATIC, _("Server port:"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer32->Add(itemStaticText33, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_RemoteServerPort = new wxTextCtrl;
  m_RemoteServerPort->Create( m_panelServer, ID_RemoteServerPort, _("9598"), wxDefaultPosition, wxSize(50, -1), 0 );
  itemBoxSizer32->Add(m_RemoteServerPort, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer32->Add(348, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxBoxSizer* itemBoxSizer36 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer24->Add(itemBoxSizer36, 0, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText37 = new wxStaticText;
  itemStaticText37->Create( m_panelServer, wxID_STATIC, _("Username:"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer36->Add(itemStaticText37, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_RemoteServerUsername = new wxTextCtrl;
  m_RemoteServerUsername->Create( m_panelServer, ID_RemoteServerUsername, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0 );
  itemBoxSizer36->Add(m_RemoteServerUsername, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer36->Add(200, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxBoxSizer* itemBoxSizer40 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer24->Add(itemBoxSizer40, 0, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText41 = new wxStaticText;
  itemStaticText41->Create( m_panelServer, wxID_STATIC, _("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer40->Add(itemStaticText41, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_RemoteServerPassword = new wxTextCtrl;
  m_RemoteServerPassword->Create( m_panelServer, ID_RemoteServerPassword, wxEmptyString, wxDefaultPosition, wxSize(200, -1), wxTE_PASSWORD );
  itemBoxSizer40->Add(m_RemoteServerPassword, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer40->Add(200, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxBoxSizer* itemBoxSizer44 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer24->Add(itemBoxSizer44, 0, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText45 = new wxStaticText;
  itemStaticText45->Create( m_panelServer, wxID_STATIC, _("Interface to use on server (use all null's for all interfaces)"), wxDefaultPosition, wxDefaultSize, 0 );
  itemStaticText45->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
  itemBoxSizer44->Add(itemStaticText45, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  itemBoxSizer44->Add(160, 1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxBoxSizer* itemBoxSizer47 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer24->Add(itemBoxSizer47, 1, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText48 = new wxStaticText;
  itemStaticText48->Create( m_panelServer, wxID_STATIC, _("GUID  (15-8):"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer47->Add(itemStaticText48, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID15 = new wxTextCtrl;
  m_GUID15->Create( m_panelServer, ID_GUID15, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID15->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer47->Add(m_GUID15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID14 = new wxTextCtrl;
  m_GUID14->Create( m_panelServer, ID_GUID14, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID14->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer47->Add(m_GUID14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID13 = new wxTextCtrl;
  m_GUID13->Create( m_panelServer, ID_GUID13, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID13->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer47->Add(m_GUID13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID12 = new wxTextCtrl;
  m_GUID12->Create( m_panelServer, ID_GUID12, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID12->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer47->Add(m_GUID12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID11 = new wxTextCtrl;
  m_GUID11->Create( m_panelServer, ID_GUID11, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID11->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer47->Add(m_GUID11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID10 = new wxTextCtrl;
  m_GUID10->Create( m_panelServer, ID_GUID10, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID10->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer47->Add(m_GUID10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID9 = new wxTextCtrl;
  m_GUID9->Create( m_panelServer, ID_GUID9, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID9->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer47->Add(m_GUID9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID8 = new wxTextCtrl;
  m_GUID8->Create( m_panelServer, ID_GUID8, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID8->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer47->Add(m_GUID8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer47->Add(65, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxBoxSizer* itemBoxSizer58 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer24->Add(itemBoxSizer58, 1, wxALIGN_RIGHT|wxALL, 1);
  wxStaticText* itemStaticText59 = new wxStaticText;
  itemStaticText59->Create( m_panelServer, wxID_STATIC, _("GUID  (7-0):"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer58->Add(itemStaticText59, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID7 = new wxTextCtrl;
  m_GUID7->Create( m_panelServer, ID_GUID7, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID7->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer58->Add(m_GUID7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID6 = new wxTextCtrl;
  m_GUID6->Create( m_panelServer, ID_GUID6, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID6->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer58->Add(m_GUID6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID5 = new wxTextCtrl;
  m_GUID5->Create( m_panelServer, ID_GUID5, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID5->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer58->Add(m_GUID5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID4 = new wxTextCtrl;
  m_GUID4->Create( m_panelServer, ID_GUID4, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID4->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer58->Add(m_GUID4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID3 = new wxTextCtrl;
  m_GUID3->Create( m_panelServer, ID_GUID3, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID3->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer58->Add(m_GUID3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID2 = new wxTextCtrl;
  m_GUID2->Create( m_panelServer, ID_GUID2, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID2->SetBackgroundColour(wxColour(255, 192, 203));
  itemBoxSizer58->Add(m_GUID2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID1 = new wxTextCtrl;
  m_GUID1->Create( m_panelServer, ID_GUID1, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
  m_GUID1->SetForegroundColour(wxColour(0, 0, 0));
  m_GUID1->SetBackgroundColour(wxColour(0, 0, 0));
  itemBoxSizer58->Add(m_GUID1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  m_GUID0 = new wxTextCtrl;
  m_GUID0->Create( m_panelServer, ID_GUID0, _("0x00"), wxDefaultPosition, wxSize(40, -1), wxTE_READONLY|wxTE_RIGHT );
  m_GUID0->SetBackgroundColour(wxColour(0, 0, 0));
  itemBoxSizer58->Add(m_GUID0, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer58->Add(65, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  wxBoxSizer* itemBoxSizer69 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer24->Add(itemBoxSizer69, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 15);
  wxButton* itemButton70 = new wxButton;
  itemButton70->Create( m_panelServer, ID_BUTTON_SET_FILTER, _("Set Filter"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer69->Add(itemButton70, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer69->Add(1, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  m_btnTestConnection = new wxButton;
  m_btnTestConnection->Create( m_panelServer, ID_BUTTON_TEST_INTERFACE, _("Test connection"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer69->Add(m_btnTestConnection, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer69->Add(1, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  m_btnGetInterfaces = new wxButton;
  m_btnGetInterfaces->Create( m_panelServer, ID_BUTTON, _("Get interfaces"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer69->Add(m_btnGetInterfaces, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  itemBoxSizer69->Add(30, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

  GetBookCtrl()->AddPage(m_panelServer, _("Remote VSCP server"));

////@end dlgVscpInterfaceSettings content construction


}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Should we show tooltips?
//

bool dlgVscpInterfaceSettings::ShowToolTips()
{
  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Get bitmap resources
//

wxBitmap dlgVscpInterfaceSettings::GetBitmapResource( const wxString& name )
{
  // Bitmap retrieval
////@begin dlgVscpInterfaceSettings bitmap retrieval
  wxUnusedVar(name);
  return wxNullBitmap;
////@end dlgVscpInterfaceSettings bitmap retrieval
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Get icon resources
//

wxIcon dlgVscpInterfaceSettings::GetIconResource( const wxString& name )
{
  // Icon retrieval
////@begin dlgVscpInterfaceSettings icon retrieval
  wxUnusedVar(name);
  return wxNullIcon;
////@end dlgVscpInterfaceSettings icon retrieval
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OnButtonVscpDriverSetPathClick
//

void dlgVscpInterfaceSettings::OnButtonVscpDriverSetPathClick( wxCommandEvent& event )
{
  wxString filename = wxFileSelector(_("Choose a CANAL driver"));
  if ( !filename.empty() ) {
    m_PathToDriver->SetValue( filename );
  }
  
  event.Skip();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OnButtonVscpSetConfigurationClick
//

void dlgVscpInterfaceSettings::OnButtonVscpSetConfigurationClick( wxCommandEvent& event )
{
  wxMessageBox(_("Sorry! This driver does not have a stored description of its configuration."));
  event.Skip(); 
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OnButtonTestInterfaceClick
//

void dlgVscpInterfaceSettings::OnButtonTestInterfaceClick( wxCommandEvent& event )
{
  VscpTcpIf tcpif;
  wxString wxstr;
  
	

  m_btnTestConnection->Enable( false );
  
  wxProgressDialog *pProgressDlg = 
                        new wxProgressDialog( _("TCP/IP session"),
                                                _("Connecting to server..."),
                                                100, 
                                                this,
                                                wxPD_AUTO_HIDE | wxPD_APP_MODAL );
  pProgressDlg->Update(80 );
  
  // If server username is given and no password is entered we ask for it.
  if ( m_RemoteServerPassword->GetValue().IsEmpty() && !m_RemoteServerUsername->GetValue().IsEmpty() ) {
    wxstr = ::wxGetTextFromUser( _("Please enter passeword"), 
                                  _("Connection Test") );
  }
  else {
    wxstr = m_RemoteServerPassword->GetValue();
  }
  
  wxBusyCursor busy;

  unsigned long val;
  m_RemoteServerPort->GetValue().ToULong( &val );
  long rv = tcpif.doCmdOpen( m_RemoteServerURL->GetValue(),
                                  val,
                                  m_RemoteServerUsername->GetValue(),
                                  wxstr );
  if ( rv ) {
    rv = tcpif.doCmdNOOP();
    tcpif.doCmdClose();
    if ( CANAL_ERROR_SUCCESS == rv ) {
      wxMessageBox(_("Successfull connect to server."), _("Connection Test"), wxICON_INFORMATION );
    }
    else {
      wxMessageBox(_("Failed do command on server (connected OK)."), _("Connection Test"), wxICON_STOP );
    }
  }
  else {
    wxMessageBox(_("Failed to connect to server."), _("Connection Test"), wxICON_STOP );
  }
  
  m_btnTestConnection->Enable( true );
  pProgressDlg->Update( 100 );
  
  event.Skip();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OnButtonGetInterfacesClick
//

void dlgVscpInterfaceSettings::OnButtonGetInterfacesClick( wxCommandEvent& event )
{
  VscpTcpIf tcpif;
  wxString wxstr;
  
  m_btnGetInterfaces->Enable( false );
  
  // If server username is given and no password is entered we ask for it.
  if ( m_RemoteServerPassword->GetValue().IsEmpty() && 
        !m_RemoteServerUsername->GetValue().IsEmpty() ) {
    wxstr = ::wxGetTextFromUser( _("Please enter passeword"), 
                                  _("Connection Test") );
  }
  else {
    wxstr = m_RemoteServerPassword->GetValue();
  }
  
  wxProgressDialog *pProgressDlg = 
                        new wxProgressDialog( _("TCP/IP session"),
                                                _("Connecting to server..."),
                                                100, 
                                                this,
                                                wxPD_AUTO_HIDE | wxPD_APP_MODAL );
  pProgressDlg->Update( 80 );
  
  wxBusyCursor busy;

  unsigned long val;
  m_RemoteServerPort->GetValue().ToULong( &val );
  long rv = tcpif.doCmdOpen( m_RemoteServerURL->GetValue(),
                                  val,
                                  m_RemoteServerUsername->GetValue(),
                                  wxstr );
                                  
  pProgressDlg->Update( 100 );
  
  if ( rv ) {
    
		// Get the interface list
		wxArrayString array;
		tcpif.doCmdInterfaceList( array );
	
		// Close the channel
    tcpif.doCmdClose();

    if ( array.Count() ) {
      
      dlgSelectDaemonInterface dlg( this );
      for ( unsigned int i=0; i<array.Count(); i++ ) {
        wxStringTokenizer tkz( array[i], _(",") );
        wxString strOrdinal = tkz.GetNextToken();
        wxString strType = tkz.GetNextToken();
        wxString strGUID = tkz.GetNextToken();
        wxString strDescription = tkz.GetNextToken();
        wxString strLine = strGUID;
        strLine += _(" ");
        strLine += _(" Type = ");
        strLine +=  strType;
        strLine += _(" - ");
        strLine += strDescription;
        
        dlg.m_ctrlListInterfaces->Append( strLine );
      }
      if ( wxID_OK == dlg.ShowModal() ) {
        int selidx;
        if ( wxNOT_FOUND != ( selidx = dlg.m_ctrlListInterfaces->GetSelection() ) ) {
          wxStringTokenizer tkz( array[selidx], _(",") );
          wxString strOrdinal = tkz.GetNextToken();
          wxString strType = tkz.GetNextToken();
          wxString strGUID = tkz.GetNextToken();
          unsigned char GUID[16];
          getGuidFromStringToArray( GUID, strGUID );
          m_GUID0->SetValue( wxString::Format(_("0x%02x"),GUID[0]) );
          m_GUID1->SetValue( wxString::Format(_("0x%02x"),GUID[1]) );
          m_GUID2->SetValue( wxString::Format(_("0x%02x"),GUID[2]) );
          m_GUID3->SetValue( wxString::Format(_("0x%02x"),GUID[3]) );
          m_GUID4->SetValue( wxString::Format(_("0x%02x"),GUID[4]) );
          m_GUID5->SetValue( wxString::Format(_("0x%02x"),GUID[5]) );
          m_GUID6->SetValue( wxString::Format(_("0x%02x"),GUID[6]) );
          m_GUID7->SetValue( wxString::Format(_("0x%02x"),GUID[7]) );
          m_GUID8->SetValue( wxString::Format(_("0x%02x"),GUID[8]) );
          m_GUID9->SetValue( wxString::Format(_("0x%02x"),GUID[9]) );
          m_GUID10->SetValue( wxString::Format(_("0x%02x"),GUID[10]) );
          m_GUID11->SetValue( wxString::Format(_("0x%02x"),GUID[11]) );
          m_GUID12->SetValue( wxString::Format(_("0x%02x"),GUID[12]) );
          m_GUID13->SetValue( wxString::Format(_("0x%02x"),GUID[13]) );
          m_GUID14->SetValue( wxString::Format(_("0x%02x"),GUID[14]) );
          m_GUID15->SetValue( wxString::Format(_("0x%02x"),GUID[15]) );
        }
      }

    }
    else {
      wxMessageBox(_("No interfaces found!"));
    }

  }
  else {
    wxMessageBox(_("Failed to connect to server."), _("Get daemon interfaces"), wxICON_STOP );
  }
  
  m_btnGetInterfaces->Enable( true );
  
  event.Skip( false );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SET_FILTER
//

void dlgVscpInterfaceSettings::OnButtonSetFilterClick( wxCommandEvent& event )
{
	dlgVSCPFilter dlg( this );
	
	dlg.setFilter( &m_vscpfilter );
	if ( wxID_OK == dlg.ShowModal() ) {
		dlg.getFilter( &m_vscpfilter );
	}
	
	event.Skip(); 
}




