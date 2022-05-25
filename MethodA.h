#pragma once
#ifndef __MethodA__
#define __MethodA__
#include "GUIMyFrame1.h"

class MethodA 
{
public :
	MethodA();
	void codeWithMethodA(wxImage img1, wxImage img2);
	void decode(wxImage img1, wxImage img2);

private:
	wxImage pattern;
	wxImage messageToCode;

};
#endif
