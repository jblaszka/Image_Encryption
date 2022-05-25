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
	method_A = new MethodA(dialog_modalny->getImage(), dialog_modalny->getMessage());
	method_A->codeWithMethodA().SaveFile("Zakodowany_Obraz.png");
}


void GUIMyFrame1::m_button_decode_click( wxCommandEvent& event )
{
	imageMain = dialog_modalny->getImage();
	Repaint();
	imageMain.SaveFile("test.png");
}


void GUIMyFrame1::Repaint()
{
	wxBitmap bitmap(imageMain);    
	wxClientDC dc(m_scrolledWindow);  
	m_scrolledWindow->DoPrepareDC(dc);
	dc.DrawBitmap(bitmap, 0, 0, true);
}

