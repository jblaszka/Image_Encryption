#include "MethodA.h"


MethodA::MethodA()
{
}

void MethodA::codeWithMethodA(wxImage img1, wxImage img2)
{
	wxImage Img_Reference = img1;
	wxImage Img_MessageToCode = img2;
	wxImage Img_encrypted = Img_Reference;

	unsigned char* Template;
	unsigned char* Cipher;
	unsigned char* Coded;

	Template = Img_Reference.GetData();
	Cipher = Img_MessageToCode.GetData();
	Coded = Img_encrypted.GetData();

	for (int i = 0; i < Img_Reference.GetHeight() * Img_Reference.GetWidth() * 3; i = i + 3) {
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
	Img_encrypted.SaveFile("methodA_encrypted.png");

}

void MethodA::decode(wxImage img1, wxImage img2) {

	wxImage Img_Reference = img1;
	wxImage Img_Encrypted = img2;

	wxImage Img_Message(Img_Reference.GetWidth(), Img_Reference.GetHeight());

	unsigned char* Template;
	unsigned char* Cipher;
	unsigned char* Coded;

	Cipher = Img_Message.GetData();

	for (int i = 0; i < Img_Reference.GetHeight() * Img_Reference.GetWidth() * 3; i++) {
		Cipher[i] = 255;
	}
	Template = Img_Reference.GetData();

	Coded = Img_Encrypted.GetData();
	for (int i = 0; i < Img_Reference.GetHeight() * Img_Reference.GetWidth() * 3; i = i + 3) {
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
	Img_Message.SaveFile("methodA_decrypted.png"); 
}


