#include "MethodA.h"


MethodA::MethodA()
{
}

wxImage MethodA::codeWithMethodA(wxImage img1, wxImage img2)
{
	wxImage pattern = img1;
	wxImage messageToCode = img2;
	unsigned char* Template;
	unsigned char* Cipher;
	unsigned char* Coded;
	wxImage Img_Coded = pattern;
	Template = pattern.GetData();
	Cipher = messageToCode.GetData();
	Coded = Img_Coded.GetData();

	for (int i = 0; i < pattern.GetHeight() * pattern.GetWidth() * 3; i = i + 3) {
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
	return Img_Coded;
}

wxImage MethodA::decode(wxImage img1, wxImage img2) {

	wxImage Img_Template = img1;
	wxImage Img_Coded = img2;
	wxImage Img_Cipher(Img_Template.GetWidth(), Img_Template.GetHeight());
	unsigned char* Template;
	unsigned char* Cipher;
	unsigned char* Coded;
	Cipher = Img_Cipher.GetData();

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
	return Img_Cipher;
}
