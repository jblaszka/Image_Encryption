///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include <wx/frame.h>
#include "ModalDialogue.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
private:


protected:
	wxButton* m_button_code;
	wxButton* m_button_decode_A;
	wxButton* m_button_decode_B;
	wxButton* m_button_decode_A_and_B;




	// Virtual event handlers, override them in your derived class
	virtual void m_button_code_click(wxCommandEvent& event) { event.Skip(); }
	virtual void m_button_decode_A_click(wxCommandEvent& event) { event.Skip(); }
	virtual void m_button_decode_B_click(wxCommandEvent& event) { event.Skip(); }
	virtual void m_button_decode_A_and_B_click(wxCommandEvent& event) { event.Skip(); }


public:

	MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1000, 533), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame1();
	wxImage* imagePanel;
	wxScrolledWindow* m_scrolledWindow;

};