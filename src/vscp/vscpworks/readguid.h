/////////////////////////////////////////////////////////////////////////////
// Name:        readguid.h
// Purpose:     
// Author:      Ake Hedman
// Modified by: 
// Created:     21/12/2007 17:17:18
// RCS-ID:      
// Copyright:   (C) 2007-2014 
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

#ifndef _READGUID_H_
#define _READGUID_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "readguid.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "readguid_symbols.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define SYMBOL_READGUID_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_READGUID_TITLE _("Read GUID")
#define SYMBOL_READGUID_IDNAME ID_READGUID
#define SYMBOL_READGUID_SIZE wxSize(400, 300)
#define SYMBOL_READGUID_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * ReadGUID class declaration
 */

class ReadGUID: public wxDialog
{    
  DECLARE_DYNAMIC_CLASS( ReadGUID )
  DECLARE_EVENT_TABLE()

public:
  /// Constructors
  ReadGUID();
  ReadGUID( wxWindow* parent, wxWindowID id = SYMBOL_READGUID_IDNAME, const wxString& caption = SYMBOL_READGUID_TITLE, const wxPoint& pos = SYMBOL_READGUID_POSITION, const wxSize& size = SYMBOL_READGUID_SIZE, long style = SYMBOL_READGUID_STYLE );

  /// Creation
  bool Create( wxWindow* parent, wxWindowID id = SYMBOL_READGUID_IDNAME, const wxString& caption = SYMBOL_READGUID_TITLE, const wxPoint& pos = SYMBOL_READGUID_POSITION, const wxSize& size = SYMBOL_READGUID_SIZE, long style = SYMBOL_READGUID_STYLE );

  /// Destructor
  ~ReadGUID();

  /// Initialises member variables
  void Init();

  /// Creates the controls and sizers
  void CreateControls();

////@begin ReadGUID event handler declarations

////@end ReadGUID event handler declarations

////@begin ReadGUID member function declarations

  /// Retrieves bitmap resources
  wxBitmap GetBitmapResource( const wxString& name );

  /// Retrieves icon resources
  wxIcon GetIconResource( const wxString& name );
////@end ReadGUID member function declarations

  /// Should we show tooltips?
  static bool ShowToolTips();

////@begin ReadGUID member variables
  /// Control identifiers
  enum {
    ID_READGUID = 24000
  };
////@end ReadGUID member variables
};

#endif
  // _READGUID_H_
