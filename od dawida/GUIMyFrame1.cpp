#include "GUIMyFrame1.h"
#include <wx/wxprec.h>
#include "ModalnyDlg.h"


GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	imageMain = wxImage(800, 533);
}

void GUIMyFrame1::m_button_save_click( wxCommandEvent& event )
{
	dialog_modalny = new ModalnyDlg(this);
	dialog_modalny->ShowModal();
	Repaint();
}

void GUIMyFrame1::m_button_method_A_click( wxCommandEvent& event )
{
	dialog_modalny1 = new ModalnyDlg(this);
	dialog_modalny1->ShowModal();
	Repaint();
}


void GUIMyFrame1::Repaint()
{
	
	imageMain = dialog_modalny->dajObraz();

	wxBitmap bitmap(imageMain);          // Tworzymy tymczasowa bitmape na podstawie Img_Cpy
	wxClientDC dc(m_scrolledWindow);   // Pobieramy kontekst okna
	m_scrolledWindow->DoPrepareDC(dc);
	dc.DrawBitmap(bitmap, 0, 0, true); // Rysujemy bitmape na kontekscie urzadzenia
}

void GUIMyFrame1::setImage(wxImage imageToSet) {
	Repaint();
}