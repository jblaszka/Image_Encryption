#include "GUIMyFrame1.h"
#include "GUIMyFrame1.h"
#include <wx/wxprec.h>

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
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

		method_A.save_MethodA_encrypted(Img_Reference, Img_Message);
		method_B.save_methodB_encrypted(Img_Message);
		//A+B
		Img_Reference.Rescale(2 * Img_Message.GetWidth(), 2 * Img_Message.GetHeight());
		method_A.codeWithMethodA(Img_Reference
								, method_B.codeWithMethodB(Img_Message)[0]).SaveFile("A1_and_B_1.png");
		method_A.codeWithMethodA(Img_Reference
								, method_B.codeWithMethodB(Img_Message)[1]).SaveFile("A1_and_B_2.png");
		Img_Reference.SaveFile("Reference_to_mixed_A_and_B.png");
	}
	else {
		wxLogError(_("Error loading the image."));
	}

}


void GUIMyFrame1::m_button_decode_A_click(wxCommandEvent& event)
{
	dialog_modalny2 = new ModalDialogue(this);
	dialog_modalny2->ShowModal();
	MethodA method_2;
	MethodB method_B2;

	if (dialog_modalny2->checking == true) {
		Img_Reference = dialog_modalny2->getImage();
		Img_Message = dialog_modalny2->getMessage();
		Repaint(method_2.decodeMethodA(Img_Reference, Img_Message));
		method_2.save_MethodA_decrypted(Img_Reference, Img_Message);
	}
	else {
		wxLogError(_("Error loading the image."));
	}
}

void GUIMyFrame1::m_button_decode_B_click(wxCommandEvent& event)
{
	dialog_modalny3 = new ModalDialogue(this);
	dialog_modalny3->setFirstButtonText("Load code 1!");
	dialog_modalny3->setSecondButtonText("Load code 2");
	dialog_modalny3->ShowModal();
	MethodB method_B2;

	if (dialog_modalny3->checking == true) {
		Img_Reference = dialog_modalny3->getImage();
		Img_Message = dialog_modalny3->getMessage();
		Repaint(method_B2.decode(Img_Reference, Img_Message));
		method_B2.save_methodB_decrypted(Img_Reference, Img_Message);
	}
	else {
		wxLogError(_("Error loading the image."));
	}
}

void GUIMyFrame1::m_button_decode_A_and_B_click(wxCommandEvent& event)
{
	dialog_modalny4 = new ModalDialogue(this);
	dialog_modalny4->setFirstButtonText("Load image");
	dialog_modalny4->setSecondButtonText("Load code 1");
	dialog_modalny4->add_new_button();
	dialog_modalny4->ShowModal();
	MethodB method_B2;
	MethodA method_A2;

	if (dialog_modalny4->checking == true) {
		Img_Reference = dialog_modalny4->getImage();
		Img_Message = dialog_modalny4->getMessage();
		Img_Code = dialog_modalny4->getCode();
		method_B2.decode(method_A2.decodeMethodA(Img_Message, Img_Reference),
					method_A2.decodeMethodA(Img_Message, Img_Code)).SaveFile("A_and_B_decoded.png");
		Repaint(method_B2.decode(method_A2.decodeMethodA(Img_Message, Img_Reference),
			method_A2.decodeMethodA(Img_Message, Img_Code)));
	}
	else {
		wxLogError(_("Error loading the image."));
	}
}


void GUIMyFrame1::Repaint(wxImage image)
{
	image.Rescale(800, 533);
	wxBitmap bitmap(image);
	wxClientDC dc(m_scrolledWindow);
	m_scrolledWindow->DoPrepareDC(dc);
	dc.DrawBitmap(bitmap, 0, 0, true);
}
