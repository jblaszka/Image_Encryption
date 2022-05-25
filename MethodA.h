#pragma once
#ifndef __MethodA__
#define __MethodA__
#include "GUIMyFrame1.h"

class MethodA 
{
public :
	MethodA();
	wxImage codeWithMethodA(wxImage img1, wxImage img2);
	wxImage pattern;
	wxImage messageToCode;
	wxImage decode(wxImage img1, wxImage img2);

private:


};
#endif
