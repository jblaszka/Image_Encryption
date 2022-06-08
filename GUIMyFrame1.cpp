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
	MethodB method_B;

	if (dialog_modalny->checking == true) {

		Img_Reference = dialog_modalny->getImage();
		Img_Message = dialog_modalny->getMessage();

		Repaint(Img_Reference);

		method_A.codeWithMethodA( Img_Reference, Img_Message);
		method_B.codeWithMethodB(Img_Message)[0].SaveFile("BBB.png");
		method_B.codeWithMethodB(Img_Message)[1].SaveFile("BBB2.png");
	}
	else {
		wxLogError(_("B³¹d podczas ³adowania obrazów."));
	}



}


void GUIMyFrame1::m_button_decode_A_click( wxCommandEvent& event )
{
	dialog_modalny2 = new ModalDialogue(this);
	dialog_modalny2->ShowModal();
	MethodA method_2;
	MethodB method_B2;

	Img_Reference = dialog_modalny2->getImage();
	Img_Message = dialog_modalny2->getMessage();

	method_2.decode(Img_Reference, Img_Message);
}

void GUIMyFrame1::m_button_decode_B_click(wxCommandEvent& event)
{
	dialog_modalny3 = new ModalDialogue(this);
	dialog_modalny3->ShowModal();

	MethodB method_B2;

	Img_Reference = dialog_modalny3->getImage();
	Img_Message = dialog_modalny3->getMessage();

	method_B2.decode(Img_Reference, Img_Message).SaveFile("BWynik.png");
}


void GUIMyFrame1::Repaint(wxImage image)
{
	image.Rescale(800, 533);
	wxBitmap bitmap(image);    
	wxClientDC dc(m_scrolledWindow);  
	m_scrolledWindow->DoPrepareDC(dc);
	dc.DrawBitmap(bitmap, 0, 0, true);
}

