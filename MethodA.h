#pragma once
#ifndef __MethodA__
#define __MethodA__
#include "GUIMyFrame1.h"

class MethodA 
{
public :
	MethodA();
	wxImage codeWithMethodA(wxImage img1, wxImage img2);
	wxImage decodeMethodA(wxImage img1, wxImage img2);

	void save_MethodA_encrypted(wxImage img1, wxImage img2);
	void save_MethodA_decrypted(wxImage img1, wxImage img2);


private:
	wxImage pattern;
	wxImage messageToCode;

};
#endif
