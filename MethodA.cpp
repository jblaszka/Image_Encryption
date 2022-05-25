
#include "MethodA.h"

MethodA::MethodA(wxImage pattern, wxImage messageToCode)
{
	this-> pattern = pattern;
	this->messageToCode = messageToCode;
	
}


wxImage MethodA::codeWithMethodA()
{
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
