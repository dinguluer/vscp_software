/////////////////////////////////////////////////////////////////////////////
// Name:        configuration.cpp
// Purpose:     
// Author:      Ake Hedman
// Modified by: 
// Created:     25/01/2009 15:17:59
// RCS-ID:      
// Copyright:   Copyright (C) 2007 D of Scandinavia 
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 25/01/2009 15:17:59

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

#include "configuration.h"

////@begin XPM images
////@end XPM images


/*!
 * Configuration type definition
 */

IMPLEMENT_DYNAMIC_CLASS( Configuration, wxPropertySheetDialog )


/*!
 * Configuration event table definition
 */

BEGIN_EVENT_TABLE( Configuration, wxPropertySheetDialog )

////@begin Configuration event table entries
////@end Configuration event table entries

END_EVENT_TABLE()


/*!
 * Configuration constructors
 */

Configuration::Configuration()
{
    Init();
}

Configuration::Configuration( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * Configuration creator
 */

bool Configuration::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin Configuration creation
    SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY|wxWS_EX_BLOCK_EVENTS);
    SetSheetStyle(wxPROPSHEET_DEFAULT);
    wxPropertySheetDialog::Create( parent, id, caption, pos, size, style );

    CreateButtons(wxOK|wxCANCEL|wxHELP);
    CreateControls();
    LayoutDialog();
    Centre();
////@end Configuration creation
    return true;
}


/*!
 * Configuration destructor
 */

Configuration::~Configuration()
{
////@begin Configuration destruction
////@end Configuration destruction
}


/*!
 * Member initialisation
 */

void Configuration::Init()
{
////@begin Configuration member initialisation
    m_RemoteServerDescription = NULL;
    m_RemoteServerURL = NULL;
    m_RemoteServerPort = NULL;
    m_RemoteServerUsername = NULL;
    m_RemoteServerPassword = NULL;
    m_strVscpClass = NULL;
    m_strVscpType = NULL;
    m_wxChoicePriority = NULL;
    m_strGUID15 = NULL;
    m_wxStrGUID14 = NULL;
    m_wxStrGUID13 = NULL;
    m_wxStrGUID12 = NULL;
    m_wxStrGUID11 = NULL;
    m_wxStrGUID10 = NULL;
    m_wxStrGUID9 = NULL;
    m_wxStrGUID8 = NULL;
    m_wxStrGUID7 = NULL;
    m_wxStrGUID6 = NULL;
    m_wxStrGUID5 = NULL;
    m_wxStrGUID4 = NULL;
    m_wxStrGUID3 = NULL;
    m_wxStrGUID2 = NULL;
    m_wxStrGUID1 = NULL;
    m_wxStrGUID0 = NULL;
    m_strVscpData = NULL;
    m_strNote = NULL;
////@end Configuration member initialisation
}


/*!
 * Control creation for Configuration
 */

void Configuration::CreateControls()
{    
////@begin Configuration content construction
    // Generated by DialogBlocks, 25/01/2009 16:53:46 (unregistered)

    Configuration* itemPropertySheetDialog1 = this;

    wxPanel* itemPanel2 = new wxPanel;
    itemPanel2->Create( GetBookCtrl(), ID_PANEL_HOST_SETTINGS, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    itemPanel2->SetSizer(itemBoxSizer3);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer3->Add(itemBoxSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer5, 0, wxALIGN_RIGHT|wxALL, 1);
    wxStaticText* itemStaticText6 = new wxStaticText;
    itemStaticText6->Create( itemPanel2, wxID_STATIC, _("Description:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemStaticText6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_RemoteServerDescription = new wxTextCtrl;
    m_RemoteServerDescription->Create( itemPanel2, ID_TEXTCTRL18, _T(""), wxDefaultPosition, wxSize(400, -1), 0 );
    itemBoxSizer5->Add(m_RemoteServerDescription, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer8, 0, wxALIGN_RIGHT|wxALL, 1);
    wxStaticText* itemStaticText9 = new wxStaticText;
    itemStaticText9->Create( itemPanel2, wxID_STATIC, _("Server URL:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(itemStaticText9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_RemoteServerURL = new wxTextCtrl;
    m_RemoteServerURL->Create( itemPanel2, ID_TEXTCTRL19, _("localhost"), wxDefaultPosition, wxSize(400, -1), 0 );
    itemBoxSizer8->Add(m_RemoteServerURL, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxBoxSizer* itemBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer11, 0, wxALIGN_RIGHT|wxALL, 1);
    wxStaticText* itemStaticText12 = new wxStaticText;
    itemStaticText12->Create( itemPanel2, wxID_STATIC, _("Server port:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer11->Add(itemStaticText12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_RemoteServerPort = new wxTextCtrl;
    m_RemoteServerPort->Create( itemPanel2, ID_TEXTCTRL20, _("9598"), wxDefaultPosition, wxSize(50, -1), 0 );
    itemBoxSizer11->Add(m_RemoteServerPort, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    itemBoxSizer11->Add(348, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxBoxSizer* itemBoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer15, 0, wxALIGN_RIGHT|wxALL, 1);
    wxStaticText* itemStaticText16 = new wxStaticText;
    itemStaticText16->Create( itemPanel2, wxID_STATIC, _("Username:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer15->Add(itemStaticText16, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_RemoteServerUsername = new wxTextCtrl;
    m_RemoteServerUsername->Create( itemPanel2, ID_TEXTCTRL21, _T(""), wxDefaultPosition, wxSize(200, -1), 0 );
    itemBoxSizer15->Add(m_RemoteServerUsername, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    itemBoxSizer15->Add(200, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxBoxSizer* itemBoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer19, 0, wxALIGN_RIGHT|wxALL, 1);
    wxStaticText* itemStaticText20 = new wxStaticText;
    itemStaticText20->Create( itemPanel2, wxID_STATIC, _("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer19->Add(itemStaticText20, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_RemoteServerPassword = new wxTextCtrl;
    m_RemoteServerPassword->Create( itemPanel2, ID_TEXTCTRL22, _T(""), wxDefaultPosition, wxSize(200, -1), wxTE_PASSWORD );
    itemBoxSizer19->Add(m_RemoteServerPassword, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    itemBoxSizer19->Add(200, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxBoxSizer* itemBoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer23, 0, wxALIGN_RIGHT|wxALL, 5);

    wxBoxSizer* itemBoxSizer24 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer24, 0, wxALIGN_RIGHT|wxALL, 5);
    wxButton* itemButton25 = new wxButton;
    itemButton25->Create( itemPanel2, ID_BUTTON, _("Test connection"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer24->Add(itemButton25, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    itemBoxSizer24->Add(285, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    GetBookCtrl()->AddPage(itemPanel2, _("Host"));

    wxPanel* itemPanel27 = new wxPanel;
    itemPanel27->Create( GetBookCtrl(), ID_PANEL_EVENT_SETTINGS, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer28 = new wxBoxSizer(wxHORIZONTAL);
    itemPanel27->SetSizer(itemBoxSizer28);

    wxBoxSizer* itemBoxSizer29 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer28->Add(itemBoxSizer29, 0, wxALIGN_TOP|wxALL, 5);
    itemBoxSizer29->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer31 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer28->Add(itemBoxSizer31, 0, wxALIGN_TOP|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer32 = new wxFlexGridSizer(2, 2, 0, 0);
    itemBoxSizer31->Add(itemFlexGridSizer32, 1, wxALIGN_TOP|wxALL, 1);
    wxStaticText* itemStaticText33 = new wxStaticText;
    itemStaticText33->Create( itemPanel27, wxID_STATIC, _("Class :"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText33->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemFlexGridSizer32->Add(itemStaticText33, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxArrayString m_strVscpClassStrings;
    m_strVscpClass = new wxComboBox;
    m_strVscpClass->Create( itemPanel27, ID_COMBOBOX, _T(""), wxDefaultPosition, wxSize(200, -1), m_strVscpClassStrings, wxCB_DROPDOWN );
    itemFlexGridSizer32->Add(m_strVscpClass, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxStaticText* itemStaticText35 = new wxStaticText;
    itemStaticText35->Create( itemPanel27, wxID_STATIC, _("Type :"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText35->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemFlexGridSizer32->Add(itemStaticText35, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxArrayString m_strVscpTypeStrings;
    m_strVscpType = new wxComboBox;
    m_strVscpType->Create( itemPanel27, ID_COMBOBOX1, _T(""), wxDefaultPosition, wxSize(200, -1), m_strVscpTypeStrings, wxCB_DROPDOWN );
    itemFlexGridSizer32->Add(m_strVscpType, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxStaticText* itemStaticText37 = new wxStaticText;
    itemStaticText37->Create( itemPanel27, wxID_STATIC, _("Priority :"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText37->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemFlexGridSizer32->Add(itemStaticText37, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxArrayString m_wxChoicePriorityStrings;
    m_wxChoicePriorityStrings.Add(_("0 - Highest"));
    m_wxChoicePriorityStrings.Add(_("1 - Even higher"));
    m_wxChoicePriorityStrings.Add(_("2 - Higher"));
    m_wxChoicePriorityStrings.Add(_("3 - Normal high"));
    m_wxChoicePriorityStrings.Add(_("4 - Normal low"));
    m_wxChoicePriorityStrings.Add(_("5 - Lower"));
    m_wxChoicePriorityStrings.Add(_("6 - Even lower"));
    m_wxChoicePriorityStrings.Add(_("7 - Lowest"));
    m_wxChoicePriority = new wxChoice;
    m_wxChoicePriority->Create( itemPanel27, ID_CHOICE, wxDefaultPosition, wxSize(120, -1), m_wxChoicePriorityStrings, 0 );
    m_wxChoicePriority->SetStringSelection(_("0"));
    itemFlexGridSizer32->Add(m_wxChoicePriority, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 1);

    itemFlexGridSizer32->Add(5, 5, 0, wxALIGN_LEFT|wxALIGN_TOP|wxRIGHT|wxTOP|wxBOTTOM, 2);

    itemFlexGridSizer32->Add(5, 5, 0, wxALIGN_LEFT|wxALIGN_TOP|wxRIGHT|wxTOP|wxBOTTOM, 2);

    itemFlexGridSizer32->Add(5, 5, 0, wxALIGN_LEFT|wxALIGN_TOP|wxRIGHT|wxTOP|wxBOTTOM, 2);

    wxStaticText* itemStaticText42 = new wxStaticText;
    itemStaticText42->Create( itemPanel27, wxID_STATIC, _("GUID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText42->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemFlexGridSizer32->Add(itemStaticText42, 1, wxALIGN_LEFT|wxALIGN_TOP|wxALL, 0);

    wxStaticText* itemStaticText43 = new wxStaticText;
    itemStaticText43->Create( itemPanel27, wxID_STATIC, _("15 - 8 :"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
    itemStaticText43->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemFlexGridSizer32->Add(itemStaticText43, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxBoxSizer* itemBoxSizer44 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer32->Add(itemBoxSizer44, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    m_strGUID15 = new wxTextCtrl;
    m_strGUID15->Create( itemPanel27, ID_TEXTCTRL, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer44->Add(m_strGUID15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID14 = new wxTextCtrl;
    m_wxStrGUID14->Create( itemPanel27, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer44->Add(m_wxStrGUID14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID13 = new wxTextCtrl;
    m_wxStrGUID13->Create( itemPanel27, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer44->Add(m_wxStrGUID13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID12 = new wxTextCtrl;
    m_wxStrGUID12->Create( itemPanel27, ID_TEXTCTRL3, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer44->Add(m_wxStrGUID12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID11 = new wxTextCtrl;
    m_wxStrGUID11->Create( itemPanel27, ID_TEXTCTRL4, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer44->Add(m_wxStrGUID11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID10 = new wxTextCtrl;
    m_wxStrGUID10->Create( itemPanel27, ID_TEXTCTRL5, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer44->Add(m_wxStrGUID10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID9 = new wxTextCtrl;
    m_wxStrGUID9->Create( itemPanel27, ID_TEXTCTRL6, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer44->Add(m_wxStrGUID9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID8 = new wxTextCtrl;
    m_wxStrGUID8->Create( itemPanel27, ID_TEXTCTRL7, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer44->Add(m_wxStrGUID8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxStaticText* itemStaticText53 = new wxStaticText;
    itemStaticText53->Create( itemPanel27, wxID_STATIC, _("7 - 0 :"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText53->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemFlexGridSizer32->Add(itemStaticText53, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxBoxSizer* itemBoxSizer54 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer32->Add(itemBoxSizer54, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    m_wxStrGUID7 = new wxTextCtrl;
    m_wxStrGUID7->Create( itemPanel27, ID_TEXTCTRL8, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer54->Add(m_wxStrGUID7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID6 = new wxTextCtrl;
    m_wxStrGUID6->Create( itemPanel27, ID_TEXTCTRL9, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer54->Add(m_wxStrGUID6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID5 = new wxTextCtrl;
    m_wxStrGUID5->Create( itemPanel27, ID_TEXTCTRL10, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer54->Add(m_wxStrGUID5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID4 = new wxTextCtrl;
    m_wxStrGUID4->Create( itemPanel27, ID_TEXTCTRL11, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer54->Add(m_wxStrGUID4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID3 = new wxTextCtrl;
    m_wxStrGUID3->Create( itemPanel27, ID_TEXTCTRL12, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer54->Add(m_wxStrGUID3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID2 = new wxTextCtrl;
    m_wxStrGUID2->Create( itemPanel27, ID_TEXTCTRL13, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer54->Add(m_wxStrGUID2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID1 = new wxTextCtrl;
    m_wxStrGUID1->Create( itemPanel27, ID_TEXTCTRL14, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer54->Add(m_wxStrGUID1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_wxStrGUID0 = new wxTextCtrl;
    m_wxStrGUID0->Create( itemPanel27, ID_TEXTCTRL15, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_RIGHT );
    itemBoxSizer54->Add(m_wxStrGUID0, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxStaticText* itemStaticText63 = new wxStaticText;
    itemStaticText63->Create( itemPanel27, wxID_STATIC, _("Data :"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText63->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemFlexGridSizer32->Add(itemStaticText63, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_strVscpData = new wxTextCtrl;
    m_strVscpData->Create( itemPanel27, ID_TEXTCTRL16, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
    if (Configuration::ShowToolTips())
        m_strVscpData->SetToolTip(_("You enter data for the event as a comma separated list. You can arrange the data on lines. Hexadecimal values should be preceded with '0x'."));
    itemFlexGridSizer32->Add(m_strVscpData, 2, wxGROW|wxALIGN_TOP|wxALL, 1);

    itemFlexGridSizer32->Add(5, 5, 0, wxALIGN_LEFT|wxALIGN_TOP|wxRIGHT|wxTOP|wxBOTTOM, 2);

    itemFlexGridSizer32->Add(5, 5, 0, wxALIGN_LEFT|wxALIGN_TOP|wxRIGHT|wxTOP|wxBOTTOM, 2);

    wxStaticText* itemStaticText67 = new wxStaticText;
    itemStaticText67->Create( itemPanel27, wxID_STATIC, _("Note :"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText67->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemFlexGridSizer32->Add(itemStaticText67, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_strNote = new wxTextCtrl;
    m_strNote->Create( itemPanel27, ID_TEXTCTRL17, _T(""), wxDefaultPosition, wxSize(-1, 50), 0 );
    itemFlexGridSizer32->Add(m_strNote, 2, wxGROW|wxALIGN_TOP|wxALL, 1);

    wxBoxSizer* itemBoxSizer69 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer28->Add(itemBoxSizer69, 0, wxALIGN_BOTTOM|wxALL, 1);
    wxBoxSizer* itemBoxSizer70 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer69->Add(itemBoxSizer70, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    GetBookCtrl()->AddPage(itemPanel27, _("Event"));

////@end Configuration content construction
}


/*!
 * Should we show tooltips?
 */

bool Configuration::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap Configuration::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin Configuration bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end Configuration bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon Configuration::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin Configuration icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end Configuration icon retrieval
}
