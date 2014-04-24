// FILE: vscphelper.h
//
// Copyright (C) 2002-2014 Ake Hedman akhe@grodansparadis.com
//
// This software is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the
// Free Software Foundation, Inc., 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.
//

// HISTORY:
//    021107 - AKHE Started this file
//

/*!
    \file vscphelper.h
    \brief	The vscphelper file contains often used functionality when working with VSCP.
    \details vscphealper have common used functionality to do things in the VSCP world. 
    It can be seens as the main toolbox for the VSCP programmer.
 */


#if !defined(VSCPHELPER_H__C2A773AD_8886_40F0_96C4_4DCA663402B2__INCLUDED_)
#define VSCPHELPER_H__C2A773AD_8886_40F0_96C4_4DCA663402B2__INCLUDED_

#ifdef VSCP_QT

#include <QString>
#include <QStringList>
#include <QtEndian>
#else


#include <wx/wx.h>
#include <wx/hashmap.h>
#ifndef WIN32
#include <sys/times.h>
#endif

#endif

#include "vscp.h"
#include "vscp_class.h"
#include "vscp_type.h"
#include "canal.h"
#include "../../common/crc.h"

// Forward declaration
class CMDF;

#ifdef __cplusplus
extern "C" {
#endif

    //@{

    /*! 
      \union vscp_value
      \brief VSCP Data coding declaration
     */
    union vscp_value {
        /// float value
        double float_value;
        /// Integer and long value and 
        long long_value;
        /// Integer value
        int int_value;
        /// Byte value
        unsigned char byte_value;
    };
    //@}

    
    /*!
        Fetch datacoding byte from measurement events
        \param pEvent Pointer to VSCP event
        \return Measurement datacoding byte or zero if its not an 
            event with a datacoding.
     */
    uint8_t getMeasurementDataCoding(const vscpEvent *pEvent);

    /*!
      Get bitarray from coded event data
      \param pNorm Pointer to normalized integer.
      \param length Number of bytes it consist of including
      the first normalize byte.
      \return Bitarray as a unsigned 64-bit integer.
     */
    uint32_t getDataCodingBitArray(const unsigned char *pNorm, const unsigned char length);

    /*!
      Get normalised integer from coded event data
      \param pNorm Pointer to normalised integer.
      \param length Number of bytes it consist of including
      the first normalise byte.
      \return returns value as a double.
     */
    double getDataCodingNormalizedInteger(const unsigned char *pNorm, const unsigned char length);

    /*!
      Get the string from coded event data
      \param pString Pointer to normalised integer.
      \param length Number of bytes it consist of including
      the first normalise byte.
      \return Returns unicode UTF-8 string of event data
     */
#ifdef VSCP_QT	
	QString& getDataCodingString(const unsigned char *pString, const unsigned char length);
#else	 
    wxString& getDataCodingString(const unsigned char *pString, const unsigned char length);
#endif	

    /*!
      Get data in the VSCP data coding format to a string. Works for
	  CLASS1.MEAUREMENT, CLASS2_LEVEL1.MEASUREMENT
      \param pEvent Pointer to VSCP event.
      \param str String that holds the result
      \return true on success, false on failure.
     */
#ifdef VSCP_QT	
	bool getVSCPMeasurementAsString(const vscpEvent *pEvent, QString& str);
#else	 
    bool getVSCPMeasurementAsString(const vscpEvent *pEvent, wxString& str);
#endif	
    
    /*!
      Get data in the VSCP data coding format as a double. Works for
	  CLASS1.MEAUREMENT, CLASS2_LEVEL1.MEASUREMENT, 
      VSCP_CLASS1_MEASUREZONE, VSCP_CLASS1_SETVALUEZONE
      \param pEvent Pointer to VSCP event.
      \param pvalue Pointer to double that holds the result
      \return true on success, false on failure.
     */
    bool getVSCPMeasurementAsDouble(const vscpEvent *pEvent, double *pvalue);
	
	/*!
      Get data in the VSCP data coding format to a string. Works for
	  CLASS1.MEASUREMENT64, CLASS2_LEVEL1.MEASUREMENT64
      \param pEvent Pointer to VSCP event.
      \param str String that holds the result
      \return true on success, false on failure.
     */
#ifdef VSCP_QT	
	bool getVSCPMeasurementFloat64AsString(const vscpEvent *pEvent, QString& str);
#else	 
    bool getVSCPMeasurementFloat64AsString(const vscpEvent *pEvent, wxString& str);
#endif	
	
	/*!
	  Convert a floating point measurement value into VSCP data with the
	  first byte being the normalizer byte
	  CLASS1.MEASUREMENT, CLASS2_LEVEL1.MEASUREMENT
      \param value Floating point value to convert.
      \param pdata Pointer to beginning of VSCP returned event data.
	  \param psize Pointer to size for returned data.
	  \param unit Untit for the data. Zero is default.
	  \param sensoridx Sensor index 0-7. Zero is default.
      \return true on success, false on failure.
     */
	bool convertFloatToNormalizedEventData( double value, 
												uint8_t *pdata,
												uint16_t *psize,
												uint8_t unit=0,
												uint8_t sensoridx=0 );
	
	/*!
      Get data in the VSCP data coding format to a string. Works for
	  CLASS1.MEASUREZONE and CLASS1.SETVALUEZONE,CLASS2_LEVEL1.MEASUREZONE
	  CLASS2_LEVEL1.SETVALUEZONE
      \param pEvent Pointer to VSCP event.
      \param str String that holds the result
      \return true on success, false on failure.
     */
#ifdef VSCP_QT	
	bool getVSCPMeasurementZoneAsString(const vscpEvent *pEvent, QString& str);
#else	 
    bool getVSCPMeasurementZoneAsString(const vscpEvent *pEvent, wxString& str);
#endif	

    /*!
      Get data in the VSCP data coding format to a float
      \param pNorm Pointer to VSCP event.
      \param length Number of bytes it consist of including datacoding byte
      \return value as float
     */
    float getMeasurementAsFloat(const unsigned char *pNorm, const unsigned char length);

    /*!
      Replace backshlashes in a string with forward slashes
      \param strval String that should be handled.
      \return Fixed string.
     */
#ifdef VSCP_QT	
    QString& replaceBackslash(QString& strval);
#else	 
    wxString& replaceBackslash(wxString& strval);
#endif	

    /*!
      Read a numerical value from a string
      The string value can be set as a hex or a decimal value.
      \param strval wxString containing value to be converted
      \return Unsigned long containing value
     */
#ifdef VSCP_QT	
	uint32_t readStringValue(const QString& strval);
#else	 
    uint32_t readStringValue(const wxString& strval);
#endif	

    /*!
      Get VSCP priority
      \param pEvent Pointer to VSCP event to set priority for.
      \return Priority (0-7) for event.
     */
    unsigned char getVscpPriority(const vscpEvent *pEvent);

    /*!
      Get VSCP priority
      \param pEvent Pointer to VSCP event to set priority for.
      \return Priority (0-7) for event.
     */
    unsigned char getVscpPriorityEx(const vscpEventEx *pEvent);

    /*!
      Set VSCP priority
      \param pEvent Pointer to VSCP event to set priority for.
      \param priority Priority (0-7) to set.
     */
    void setVscpPriority(vscpEvent *pEvent, unsigned char priority);
    
     /*!
      Set VSCP priority Ex
      \param pEvent Pointer to VSCP event to set priority for.
      \param priority Priority (0-7) to set.
     */
    void setVscpPriorityEx(vscpEventEx *pEvent, unsigned char priority);

    /*!
      Get VSCP head from CAN id
      \param id CAN id
      \return VSCP head
     */
    unsigned char getVSCPheadFromCANid(const uint32_t id);

    /*!
     Get VSCP class from CAN id
      \param id CAN id
      \return VSCP class
     */
    uint16_t getVSCPclassFromCANid(const uint32_t id);

    /*!
      Get VSCP type from CAN id
      \param id CAN id
     \return VSCP type
     */
    uint16_t getVSCPtypeFromCANid(const uint32_t id);

    /*!
     Get VSCP nide nickname from CAN id
      \param id CAN id
      \return VSCP node nickname
     */
    uint16_t getVSCPnicknameFromCANid(const uint32_t id);

    /*!
      Get CAN id from VSCP info
      \param priority VSCP priority
      \param vscp_class VSCP class
      \param vscp_type VSCP type
      \return CAN id with nickname == 0
     */
    uint32_t getCANidFromVSCPdata(const unsigned char priority,
            const uint16_t vscp_class,
            const uint16_t vscp_type);

    /*!
      Get CAN id from VSCP event
      \param pEvent Pointer to VSCP event
      \return CAN id with nickname == 0
     */
    uint32_t getCANidFromVSCPevent(const vscpEvent *pEvent);

    /*!
      Get CAN id from VSCP event
      \param pEvent Pointer to VSCP event
      \return CAN id with nickname == 0
     */
    uint32_t getCANidFromVSCPeventEx(const vscpEventEx *pEvent);

    /*!
      Calculate CRC for VSCP event
     */
    unsigned short vscp_calc_crc(vscpEvent *pEvent, short bSet);



    // Helpers

    /*!
      Get GUID from string

      \param pEvent Pointer to VSCP event
      \param strGUID String with GUID (xx:yy:zz....)
      \return True on success, false on failure.
     */
#ifdef VSCP_QT	
	bool getGuidFromString(vscpEvent *pEvent, const QString& strGUID);
#else	 
    bool getGuidFromString(vscpEvent *pEvent, const wxString& strGUID);
#endif	
    
        /*!
      Get GUID from string

      \param pEvent Pointer to VSCP event
      \param strGUID String with GUID (xx:yy:zz....)
      \return True on success, false on failure.
     */
#ifdef VSCP_QT	
	bool getGuidFromStringEx(vscpEventEx *pEventEx, const QString& strGUID);
#else	 
    bool getGuidFromStringEx(vscpEventEx *pEventEx, const wxString& strGUID);
#endif	

    /*!
      Fill event GUID from a string
     */
#ifdef VSCP_QT	
	bool getGuidFromStringToArray(unsigned char *pGUID, const QString& strGUID);
#else	 
    bool getGuidFromStringToArray(unsigned char *pGUID, const wxString& strGUID);
#endif	
	
	/*!
      Write out GUID to string

      \param pGUID Pointer to VSCP GUID array.
      \param strGUID Reference to string for written GUID
      \return True on success, false on failure.
    */
#ifdef VSCP_QT	
	bool writeGuidArrayToString(const unsigned char *pGUID, QString& strGUID);
#else	
    bool writeGuidArrayToString(const unsigned char *pGUID, wxString& strGUID);
#endif	

    /*!
      Write out GUID to string

      \param pEvent Pointer to VSCP event
      \param strGUID Reference to string for written GUID
      \return True on success, false on failure.
     */
#ifdef VSCP_QT	
	bool writeGuidToString(const vscpEvent *pEvent, QString& strGUID);
#else	 
    bool writeGuidToString(const vscpEvent *pEvent, wxString& strGUID);
#endif	
    
        /*!
      Write out GUID to string

      \param pEvent Pointer to VSCP event
      \param strGUID Reference to string for written GUID
      \return True on success, false on failure.
     */
#ifdef VSCP_QT	
	bool writeGuidToStringEx(const vscpEventEx *pEvent, QString& strGUID);
#else	 
    bool writeGuidToStringEx(const vscpEventEx *pEvent, wxString& strGUID);
#endif	

    /*!
      Write out GUID to string as four rows

      \param pEvent Pointer to VSCP event
      \param strGUID Reference to string for written GUID
      \return True on success, false on failure.
     */
#ifdef VSCP_QT	
	bool writeGuidToString4Rows(const vscpEvent *pEvent, QString& strGUID);
#else	 
    bool writeGuidToString4Rows(const vscpEvent *pEvent, wxString& strGUID);
#endif	
    
        /*!
      Write out GUID to string as four rows

      \param pEvent Pointer to VSCP event
      \param strGUID Reference to string for written GUID
      \return True on success, false on failure.
     */
#ifdef VSCP_QT	
	bool writeGuidToString4RowsEx(const vscpEventEx *pEvent, QString& strGUID);
#else	 
    bool writeGuidToString4RowsEx(const vscpEventEx *pEvent, wxString& strGUID);
#endif	


    /*!
      Check if GUID is all null
      \param pGUID pointer to GUID to check
      \return tru of empty, false if not.
     */
    bool isGUIDEmpty(const unsigned char *pGUID);

    /*!
      Compare two GUID's
      \param pGUID1 First GUID to compare
      \param pGUID2 Second GUID to compare
      \return True if the two GUID's are equal. False otherwise.
     */
    bool isSameGUID(const unsigned char *pGUID1, const unsigned char *pGUID2);

    /*!
        Recerse GUID
        \param pGUID Pointer to GUID to reverse.
        \return true if OK.
     */
    bool reverseGUID(unsigned char *pGUID);

    /*!
      Convert a standard VSCP event to the Ex version
     */
    bool convertVSCPtoEx(vscpEventEx *pEventEx, const vscpEvent *pEvent);

    /*!
      Convert an Ex event to a standard VSCP event
     */
    bool convertVSCPfromEx(vscpEvent *pEvent, const vscpEventEx *pEventEx);

    /*!
      Delete a standard VSCP event
     */
    void deleteVSCPevent(vscpEvent *pEvent);

    /*!
      Delete an Ex event
     */
    void deleteVSCPeventEx(vscpEventEx *pEventEx);

    /*!
      Clear VSCP filter so it will allow all events to go through
      \param pFilter Pointer to VSCP filter.
     */
    void clearVSCPFilter(vscpEventFilter *pFilter);

    /*!
      Check filter/mask to check if filter should be delivered

      filter ^ bit    mask    out
      ============================
           0           0       1    filter == bit, mask = don't care result = true
           0           1       1    filter == bit, mask = valid, result = true
           1           0       1    filter != bit, mask = don't care, result = true
           1           1       0    filter != bit, mask = valid, result = false

      Mask tells *which* bits that are of interest means
      it always returns true if bit set to zero (0=don't care).

      Filter tells the value fo valid bits. If filter bit is == 1 the bits
      must be equal to get a true filter return.

      So a nill mask will let everything through
      \return true if message should be delivered false if not.
     */
    bool doLevel2Filter(const vscpEvent *pEvent,
            const vscpEventFilter *pFilter);

    bool doLevel2FilterEx(const vscpEventEx *pEventEx,
            const vscpEventFilter *pFilter);

    /*!
        Read a filter from a string
        \param pFilter Filter structure to write filter to.
        \param strFilter Filter in string form 
                filter-priority, filter-class, filter-type, filter-GUID
        \return true on success, fals eon failure.
     */
#ifdef VSCP_QT	
	bool readFilterFromString(vscpEventFilter *pFilter, QString& strFilter);
#else	 
    bool readFilterFromString(vscpEventFilter *pFilter, wxString& strFilter);
#endif	

    /*!
        Read a mask from a string
        \param pFilter Filter structure to write mask to.
        \param strMask Mask in string form 
                mask-priority, mask-class, mask-type, mask-GUID
        \return true on success, fals eon failure.
     */
#ifdef VSCP_QT	
	bool readMaskFromString(vscpEventFilter *pFilter, QString& strMask);
#else	 
    bool readMaskFromString(vscpEventFilter *pFilter, wxString& strMask);
#endif	

    /*!
      Convert an Event from a CANAL message
     */
    bool convertCanalToEvent(vscpEvent *pvscpEvent,
            const canalMsg *pcanalMsg,
            unsigned char *pGUID,
            bool bCAN = false);
    
    /*!
      Convert an Event from a CANAL message
     */
    bool convertCanalToEventEx(vscpEventEx *pvscpEvent,
            const canalMsg *pcanalMsg,
            unsigned char *pGUID,
            bool bCAN = false);

    /*!
      Covert VSCP event to CANAL message
     */
    bool convertEventToCanal(canalMsg *pcanalMsg,
            const vscpEvent *pvscpEvent);
    
    /*!
      Covert VSCP event to CANAL message
    */
    bool convertEventExToCanal(canalMsg *pcanalMsg,
            const vscpEventEx *pvscpEvent);


    /*!
      Make a timestamp for events etc 
      \return Event timestamp as an unigned long
     */
    unsigned long makeTimeStamp(void);


    /*!
      Copy a VSCP event to another

      \param pEventTo Pointer to event to copy to.
      \param pEventFrom Pointer to event to copy from.
      \return True on success.
     */
    bool copyVSCPEvent(vscpEvent *pEventTo, const vscpEvent *pEventFrom);
    

    /*!
      Write VSCP data to string
      \param pEvent Pointer to event where data is fetched from
      \param str String that receive result.
      \param bUseHtmlBreak Set to true to use <br> instead of \\n as
      line break 
      \return True on success false on failure.
     */
#ifdef VSCP_QT	
	bool writeVscpDataToString(const vscpEvent *pEvent, 
								QString& str, 
								bool bUseHtmlBreak = false);
#else	 
    bool writeVscpDataToString(const vscpEvent *pEvent, 
								wxString& str, 
								bool bUseHtmlBreak = false);
#endif								

    /*!
      Write VSCP data to string
      \param sizeData Number of databytes.
      \param pData Pointer to datastructure.
       \param str String that receive result.
      \param bUseHtmlBreak Set to true to use <br> instead of \\n as
      line break 
      \return True on success false on failure.
     */
#ifdef VSCP_QT	
	bool writeVscpDataWithSizeToString(const uint16_t sizeData,
										const unsigned char *pData,
										QString& str,
										bool bUseHtmlBreak = false);
#else	 
    bool writeVscpDataWithSizeToString(const uint16_t sizeData,
										const unsigned char *pData,
										wxString& str,
										bool bUseHtmlBreak = false);
#endif										

    /*!
      Get VSCP data from a string
      \param pEvent Ponter to a VSCP event to write parsed data to.
      \param str A string with comma or whitespace separated data in decimal
      or hexadecimal form. Data can span multiple lines.
      \return true on success, false on failure.
     */
#ifdef VSCP_QT	
	bool getVscpDataFromString(vscpEvent *pEvent, const QString& str);
#else	 
    bool getVscpDataFromString(vscpEvent *pEvent, const wxString& str);
#endif	

    /*!
      Get VSCP data from a string
      \param pData Pointer to a unsigned byte array to write parsed data to.
      \param psizeData Number of data bytes. 
      \param str A string with comma or whitespace separated data in decimal
      or hexadecimal form. Data can span multiple lines.
      \return true on success, false on failure.
     */
#ifdef VSCP_QT	
	bool getVscpDataArrayFromString( uint8_t *pData, 
										uint16_t *psizeData, 
										const QString& str);
#else	 
    bool getVscpDataArrayFromString( uint8_t *pData, 
										uint16_t *psizeData, 
										const wxString& str);
#endif										

    /*!
      Write event to string.
      priority,class,type,guid,data
      \param pEvent Event that should be presented
      \param str String that receive the result
      \return true on success, false on failure.
     */
#ifdef VSCP_QT	
	bool writeVscpEventToString(vscpEvent *pEvent, QString& str);
#else	 
    bool writeVscpEventToString(vscpEvent *pEvent, wxString& str);
#endif	

    /*!
      Write event to string.
      priority,class,type,guid,data
      \param pEvent Event that should be presented
      \param str String that receive the result
      \return true on success, false on failure.
     */
#ifdef VSCP_QT	
	bool writeVscpEventExToString(vscpEventEx *pEvent, QString& str);
#else	 
    bool writeVscpEventExToString(vscpEventEx *pEvent, wxString& str);
#endif	


    /*!
      Get event data from string format
      Format: head,class,type,obid,timestamp,GUID,data1,data2,data3....
      \param pEvent Event that will get data
      \param str String that contain the event on string form
      \return true on success, false on failure.
     */
#ifdef VSCP_QT	
	bool getVscpEventFromString(vscpEvent *pEvent, const QString& str);
#else	 
    bool getVscpEventFromString(vscpEvent *pEvent, const wxString& str);
#endif	

    /*!
      Get event data from string format
      Format: head,class,type,obid,timestamp,GUID,data1,data2,data3....
      \param pEventEx Pointer to VSCP event that will get the parsed data
      \param str String that contain the event on string form
      \return true on success, false on failure.
     */
#ifdef VSCP_QT	
	bool getVscpEventExFromString(vscpEventEx *pEventEx, const QString& str);
#else	 
    bool getVscpEventExFromString(vscpEventEx *pEventEx, const wxString& str);
#endif	

    /*!
      Get Data in real text.
      This for meaurement class events that can be describes in real text
      in a deterministic way. Temperature event is typical which can be returned
      in clear text as "Temperature = 22.5 C".
      \param pEvent Event that should be presented
      \return Text data representation of the event data or an empty string 
      if the class/type pair is not supported..
     */
#ifdef VSCP_QT	
	QString& getRealTextData(vscpEvent *pEvent);
#else	 
    wxString& getRealTextData(vscpEvent *pEvent);
#endif	

    /*!
      This function makes a HTML string from a standard string. LF is replaced
      with a '<BR>'.
      \param str String that should be HTML coded.
     */
#ifdef VSCP_QT	
	void makeHtml(QString& str);
#else	 
    void makeHtml(wxString& str);
#endif	

	/*
		Get device HTML status from device
		@param registers Aray with all 256 registers for the device
	    @param pmdf Optional pointer to CMDF class which gives more info
				about the device if it is supplied.
	 */
#ifdef VSCP_QT	
	QString& getDeviceHtmlStatusInfo( const uint8_t *registers, CMDF *pmdf );
#else	 
	wxString& getDeviceHtmlStatusInfo( const uint8_t *registers, CMDF *pmdf );
#endif	


#ifdef __cplusplus
}
#endif

#endif // #if !defined(AFX_VSCPHELPER_H__C2A773AD_8886_40F0_96C4_4DCA663402B2__INCLUDED_)

