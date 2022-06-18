#pragma once
#ifndef __MethodB__
#define __MethodB__
#include "GUIMyFrame1.h"

class MethodB
{
public:
	MethodB();
	void codeWithMethodB(wxImage img1);
	wxImage pattern;
	wxImage messageToCode;
	void decode(wxImage img1, wxImage img2);

private:


};
#endif
