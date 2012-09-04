/////////////////////////////////////////////////////////////////////////////
// Name:        vscpdaemoninterface.h
// Purpose:     
// Author:      CanMsgDlg
// Modified by: 
// Created:     20/07/2006 19:21:05
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 20/07/2006 19:21:05

#ifndef _VSCPDAEMONINTERFACE_H_
#define _VSCPDAEMONINTERFACE_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "vscpdaemoninterface.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/mdi.h"
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
#define ID_FRAME 10001
#define SYMBOL_VSCPDAEMONINTERFACE_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_VSCPDAEMONINTERFACE_TITLE _("VSCP Level II event window")
#define SYMBOL_VSCPDAEMONINTERFACE_IDNAME ID_FRAME
#define SYMBOL_VSCPDAEMONINTERFACE_SIZE wxSize(400, 300)
#define SYMBOL_VSCPDAEMONINTERFACE_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * VSCPDaemonInterface class declaration
 */

class VSCPDaemonInterface: public wxMDIChildFrame
{    
    DECLARE_CLASS( VSCPDaemonInterface )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    VSCPDaemonInterface( );
    VSCPDaemonInterface( wxMDIParentFrame* parent, wxWindowID id = SYMBOL_VSCPDAEMONINTERFACE_IDNAME, const wxString& caption = SYMBOL_VSCPDAEMONINTERFACE_TITLE, const wxPoint& pos = SYMBOL_VSCPDAEMONINTERFACE_POSITION, const wxSize& size = SYMBOL_VSCPDAEMONINTERFACE_SIZE, long style = SYMBOL_VSCPDAEMONINTERFACE_STYLE );

    bool Create( wxMDIParentFrame* parent, wxWindowID id = SYMBOL_VSCPDAEMONINTERFACE_IDNAME, const wxString& caption = SYMBOL_VSCPDAEMONINTERFACE_TITLE, const wxPoint& pos = SYMBOL_VSCPDAEMONINTERFACE_POSITION, const wxSize& size = SYMBOL_VSCPDAEMONINTERFACE_SIZE, long style = SYMBOL_VSCPDAEMONINTERFACE_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin VSCPDaemonInterface event handler declarations

////@end VSCPDaemonInterface event handler declarations

////@begin VSCPDaemonInterface member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end VSCPDaemonInterface member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin VSCPDaemonInterface member variables
////@end VSCPDaemonInterface member variables
};

#endif
    // _VSCPDAEMONINTERFACE_H_
