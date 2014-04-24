/////////////////////////////////////////////////////////////////////////////
// Name:        bootdevice.h
// Purpose:     
// Author:      Ake Hedman
// Modified by: 
// Created:     16/12/2009 22:26:09
// RCS-ID:      
// Copyright:   (C) 2012-2014 
// Ake Hedman, Grodans Paradis AB, <akhe@grodansparadis.com>
// Licence:     
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version
// 2 of the License, or (at your option) any later version.
// 
// This file is part of the VSCP (http://www.vscp.org) 
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
//  Grodans Paradis AB at info@grodansparadis.com, http://www.grodansparadis.com
/////////////////////////////////////////////////////////////////////////////

#pragma once

/*!
    This is the base class for the VSCP Works wizard 
    firmware load functionality. The code relies on code 
    in the VSCP main file to read/write to a remote  device.
*/

#include "../common/canalsuperwrapper.h"
#include "../common/mdf.h"
#include "../common/guid.h"

#include "vscpworks.h"

// Forward references
class wxHtmlWindow;

// Timeout for response
#define BOOT_COMMAND_DEFAULT_RESPONSE_TIMEOUT	5000

// Hexfiles type
#define HEXFILE_TYPE_INTEL_HEX8     0
#define HEXFILE_TYPE_INTEL_HEX16    1
#define HEXFILE_TYPE_INTEL_HEX32    2
#define HEXFILE_TYPE_INTEL_SRECORD  3


class CBootDevice
{
public:

    /*! 
        Constructor

        @param pcsw Pointer to Canalsuper wrapper
        @param guid GUID for device
            depending on if the device sits on a Level I or 
            a Level II link this is a nickname (in LSB) or
            a full GUID.
    */
    CBootDevice( CCanalSuperWrapper *pcsw, cguid &guid );

    /*!
        Destructor
    */
     virtual ~CBootDevice(void);

    /*!
		Load a binary file to the image

        This is typically an Intel HEX file that contains the memory
        image of the device.

		@param path Path to file
        @param typecode A typecode for the file to load. Typical
            Intel HEX8, HEX6, HEX32, SRECORD etc
		@return true on success 
	*/
	virtual bool loadBinaryFile( const wxString& path, uint16_t type ) = 0;

    /*!
        Show info for hex file
        @param Pointer to HTML window that will receive information.
    */
    virtual void showInfo( wxHtmlWindow *phtmlWnd ) = 0;

    /*!
		Set a device in bootmode

        @return true on success.
	*/
	virtual bool setDeviceInBootMode( void ) = 0;

    /*!
        Perform the actual boot process
        @return true on success.
    */
    virtual bool doFirmwareLoad( void ) = 0;

    /*!
        Set response timeout in milliseconds
    */
    void setResponseTimeout( uint16_t timeout ) { m_responseTimeout = timeout; };

    /*!
        Get response timeout in milliseconds
    */
    uint16_t getResponseTimeout( void ) { return m_responseTimeout; };



public:

    /*!
        GUID or nickname
            Nickname is in lsb
    */
    cguid m_guid;

protected:


    /*!
        Communication interface to use. 
    */
    CCanalSuperWrapper *m_pCanalSuperWrapper;

    /// Checksum for firmware
    uint32_t m_checksum;

    /// Response timeout in milliseconds
    uint32_t m_responseTimeout;

    

     /*!
		Flag for flash memory programming or not	
	*/
	bool m_bFlashMemory;

	/*!
		Flag for config memory programming or not		
	*/
	bool m_bConfigMemory;

	/*!
		Flag for EEPROM memory programming or not		
	*/
	bool m_bEEPROMMemory;






    /// Program memory buffer
	uint8_t *m_pbufPrg;

	/// Config memory buffer
	uint8_t *m_pbufCfg;

	/// EEPROM memory buffer
	uint8_t *m_pbufEEPROM;






	/// True if there is at least one program data byte
	bool m_bPrgData;

	/// True if there is at least one config data byte
	bool m_bConfigData;

	/// True if there is at least one EEPROM data byte
	bool m_bEEPROMData;

	
    
    
    
    /// Lowest flash address
	unsigned long m_minFlashAddr;

	/// Highest flash address
	unsigned long m_maxFlashAddr;





	/// Lowest config address
	unsigned long m_minConfigAddr;

    /// Highest config address
	unsigned long m_maxConfigAddr;





	/// Lowest EEPROM address
	unsigned long m_minEEPROMAddr;

	/// Highest EEPROM address
	unsigned long m_maxEEPROMAddr;



    
    /// # data bytes in file
	unsigned long m_totalCntData;

};
