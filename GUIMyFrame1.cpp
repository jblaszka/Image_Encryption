#include "GUIMyFrame1.h"
#include <wx/wxprec.h>

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1(parent)
{
	imageMain = wxImage(800, 533);
	imageMessage = wxImage(800, 533);
}


void GUIMyFrame1::m_button_code_click(wxCommandEvent& event)
{
	dialog_modalny = new ModalDialogue(this);
	dialog_modalny->ShowModal();
}


void GUIMyFrame1::m_button_decode_click( wxCommandEvent& event )
{
	imageMain = dialog_modalny->getImage();
	imageMain.SaveFile("test.jpg");
}


void GUIMyFrame1::Repaint()
{
	imageMain = dialog_modalny->getImage();
	imageMessage = dialog_modalny->getMessage();

	wxBitmap bitmap(imageMain);    
	wxClientDC dc(m_scrolledWindow);  
	m_scrolledWindow->DoPrepareDC(dc);
	dc.DrawBitmap(bitmap, 0, 0, true);
}

