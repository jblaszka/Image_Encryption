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
	CodeMethod_B();
}


void GUIMyFrame1::m_button_decode_click(wxCommandEvent& event)
{
	dialog_modalny = new ModalDialogue(this);
	dialog_modalny->ShowModal();
	//DecodeMethod_A();	
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
void GUIMyFrame1::CodeMethod_B() {
	srand(time(NULL));
	wxImage Img_A(1600,1066) ;
	wxImage Img_B(1600, 1066);
	wxImage Img_C(1600, 1066);
	unsigned char* Coded;
	unsigned char* Image_a;
	unsigned char* Image_b;
	unsigned char* Image_c;
	Image_b = Img_B.GetData();
	Image_a = Img_A.GetData();
	Image_c = Img_C.GetData();

	Img_Coded = dialog_modalny->getMessage();
	Coded = Img_Coded.GetData();
	for (int i = 0; i < Img_A.GetHeight() * Img_A.GetWidth() * 3; i++) {
		Image_a[i] = 255;
		Image_b[i] = 255;
	}
	for (int i = 0; i < Img_C.GetHeight() * Img_C.GetWidth() * 3; i++) {
		Image_c[i] = 255;
	}

	int a, b;
	for (int i = 0; i < Img_Coded.GetHeight() * Img_Coded.GetWidth() * 3; i = i + 3) {
		int random = rand() % 2;
		if (Coded[i] == 255) {
			if (random == 1) {
				a = 0;
			}
			else {
				a = 255;
			}
			for (int q = 0; q < 3; q++) {
				Image_a[2 * i + q + (i / (Img_Coded.GetWidth()*3)) * Img_A.GetWidth() * 3] = a;
				Image_b[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3] = a;
				Image_a[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3+3]  = 255 - a;
				Image_b[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3+3] = 255 - a;
				Image_a[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3] = 255 - a;
				Image_b[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3] = 255 - a;
				Image_a[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3 + 3] = a;
				Image_b[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3 + 3] = a;
			}
		}
		else {
			if (random == 1) {
				a = 0;
				b = 255;
			}
			else {
				a = 255;
				b = 0;
			}
			for (int q = 0; q < 3; q++) {
				Image_a[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3] = a;
				Image_b[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3] = 255-a;
				Image_a[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3 + 3] = 255 - a;
				Image_b[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3 + 3] = a;
				Image_a[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3] = 255 - a;
				Image_b[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3] = a;
				Image_a[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3 + 3] = a;
				Image_b[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3 + 3] = 255-a;
			
			}
		}
	}
		Img_A.SaveFile("blablaA.png");
		Img_B.SaveFile("BlablaB.png");
		for (int j = 0;j < Img_C.GetHeight() * Img_C.GetWidth() * 3; j+=3)
		{
			if (Image_a[j] != Image_b[j])
			{
				Image_c[j] = 0;
				Image_c[j+1] = 0;
				Image_c[j+2] = 0;
			}
		}
		Img_C.Rescale(800, 533);
		Img_C.SaveFile("BlablaC.png");
		 
}
