#pragma once
#ifndef __MethodB__
#define __MethodB__
#include "GUIMyFrame1.h"

class MethodB
{
public:
	MethodB();
	wxVector <wxImage> codeWithMethodB(wxImage img1);
	wxImage pattern;
	wxImage messageToCode;
	wxImage decode(wxImage img1, wxImage img2);
	wxVector <wxImage> vector_img;
private:


};
#endif
