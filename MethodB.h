#pragma once
#ifndef __MethodB__
#define __MethodB__
#include "GUIMyFrame1.h"

class MethodB
{
public:
	MethodB();
	wxVector <wxImage> codeWithMethodB(wxImage img1);
	wxImage decode(wxImage img1, wxImage img2);
	void save_methodB_encrypted(wxImage img1);
	void save_methodB_decrypted(wxImage img1, wxImage img2);

	wxImage pattern;
	wxImage messageToCode;
	wxVector <wxImage> vector_img;

private:


};
#endif
