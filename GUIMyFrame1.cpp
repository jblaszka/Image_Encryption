#include "GUIMyFrame1.h"
#include <wx/wxprec.h>

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	Img_Coded = wxImage(800, 533);
	Img_Template = wxImage(800, 533);
	Img_Cipher = wxImage(800, 533);
}


void GUIMyFrame1::m_button_code_click(wxCommandEvent& event)
{
	dialog_modalny = new ModalDialogue(this);
	dialog_modalny->ShowModal();
	CodeMethod_A();
}


void GUIMyFrame1::m_button_decode_click(wxCommandEvent& event)
{
	dialog_modalny = new ModalDialogue(this);
	dialog_modalny->ShowModal();
	DecodeMethod_A();	
}


void GUIMyFrame1::Repaint()
{

	wxBitmap bitmap(Img_Cipher);
	wxClientDC dc(m_scrolledWindow);
	m_scrolledWindow->DoPrepareDC(dc);
	dc.DrawBitmap(bitmap, 0, 0, true);
}

void GUIMyFrame1::CodeMethod_A() {
	Img_Template = dialog_modalny->getImage();
	Img_Cipher = dialog_modalny->getMessage();

	unsigned char* Template;
	unsigned char* Cipher;
	unsigned char* Coded;
	Img_Coded = Img_Template;
	Template = Img_Template.GetData();
	Cipher = Img_Cipher.GetData();
	Coded = Img_Coded.GetData();

	for (int i = 0; i < Img_Template.GetHeight() * Img_Template.GetWidth() * 3; i = i + 3) {
		if (Cipher[i] < 32) {
			Coded[i] -= 1;
			Coded[i + 1] -= 1;
			Coded[i + 2] -= 1;
		}
		else if (Cipher[i] >= 32 && Cipher[i] < 64) {
			Coded[i] -= 1;
			Coded[i + 1] -= 1;
		}
		else if (Cipher[i] >= 64 && Cipher[i] < 96) {
			Coded[i] -= 1;
			Coded[i + 2] -= 1;
		}
		else if (Cipher[i] >= 96 && Cipher[i] < 128) {
			Coded[i] -= 1;
		}
		else if (Cipher[i] >= 128 && Cipher[i] < 160) {
			Coded[i + 1] -= 1;
			Coded[i + 2] -= 1;
		}
		else if (Cipher[i] >= 160 && Cipher[i] < 192) {
			Coded[i + 1] -= 1;
		}
		else if (Cipher[i] >= 192 && Cipher[i] < 224) {
			Coded[i + 2] -= 1;
		}
	}
	Img_Coded.SaveFile("Zakodowany_Obraz.png");
}

void GUIMyFrame1::DecodeMethod_A() {

	unsigned char* Template;
	unsigned char* Cipher;
	unsigned char* Coded;
	Cipher = Img_Cipher.GetData();
	Img_Template = dialog_modalny->getImage();
	Img_Coded = dialog_modalny->getMessage();
	for (int i = 0; i < Img_Template.GetHeight() * Img_Template.GetWidth() * 3; i++) {
		Cipher[i] = 255;
	}
	Template = Img_Template.GetData();

	Coded = Img_Coded.GetData();
	for (int i = 0; i < Img_Template.GetHeight() * Img_Template.GetWidth() * 3; i = i + 3) {
		if (Template[i + 2] - Coded[i + 2] == 1 && Template[i + 1] - Coded[i + 1] == 1 && Template[i] - Coded[i] == 1) {
			Cipher[i] = 0;
			Cipher[i + 1] = 0;
			Cipher[i + 2] = 0;
		}
		else if (Template[i + 2] - Coded[i + 2] == 1 && Template[i + 1] - Coded[i + 1] == 1 && Template[i] - Coded[i] == 1) {
			Cipher[i] = 32;
			Cipher[i + 1] = 32;
			Cipher[i + 2] = 32;
		}
		else if (Template[i + 2] - Coded[i + 2] == 1 && Template[i] - Coded[i] == 1) {
			Cipher[i] = 64;
			Cipher[i + 1] = 64;
			Cipher[i + 2] = 64;
		}
		else if (Template[i] - Coded[i] == 1) {
			Cipher[i] = 96;
			Cipher[i + 1] = 96;
			Cipher[i + 2] = 96;
		}
		else if (Template[i + 1] - Coded[i + 1] == 1 && Template[i + 2] - Coded[i + 2] == 1) {
			Cipher[i] = 128;
			Cipher[i + 1] = 128;
			Cipher[i + 2] = 128;
		}
		else if (Template[i + 1] - Coded[i + 1] == 1) {
			Cipher[i] = 160;
			Cipher[i + 1] = 160;
			Cipher[i + 2] = 160;
		}
		else if (Template[i + 2] - Coded[i + 2] == 1) {
			Cipher[i] = 192;
			Cipher[i + 1] = 192;
			Cipher[i + 2] = 192;
		}
	}
	Img_Cipher.SaveFile("rozwiazanie.png");
	Repaint();
}

