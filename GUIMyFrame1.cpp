#include "GUIMyFrame1.h"
#include <wx/wxprec.h>

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1(parent)
{
}


void GUIMyFrame1::m_button_code_click(wxCommandEvent& event)
{
	dialog_modalny = new ModalDialogue(this);
	dialog_modalny->ShowModal();
	MethodA method_A;

	//method_A.codeWithMethodA(dialog_modalny->getImage(), dialog_modalny->getMessage());
	if (dialog_modalny->checking == true) {
		method_A.codeWithMethodA(dialog_modalny->getImage(), dialog_modalny->getMessage());
	}
	else {
		wxLogError(_("Nie mo¿na za³adowaæ obrazka"));
	}
}


void GUIMyFrame1::m_button_decode_click( wxCommandEvent& event )
{
	dialog_modalny2 = new ModalDialogue(this);
	dialog_modalny2->ShowModal();
	MethodA method_2;
	method_2.decode(dialog_modalny2->getImage(), dialog_modalny2->getMessage());
}


void GUIMyFrame1::Repaint()
{
	wxBitmap bitmap(imageMain);    
	wxClientDC dc(m_scrolledWindow);  
	m_scrolledWindow->DoPrepareDC(dc);
	dc.DrawBitmap(bitmap, 0, 0, true);
}

