#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__
#include "GUI.h"

class GUIMyFrame1 : public MyFrame1
{
protected:
	void m_button_code_click(wxCommandEvent& event);
	void m_button_decode_click(wxCommandEvent& event);
	void CodeMethod_A();
	void DecodeMethod_A();

public:
	ModalDialogue* dialog_modalny;
	GUIMyFrame1(wxWindow* parent);
	void Repaint();
	wxImage Img_Coded;
	wxImage Img_Template;
	wxImage Img_Cipher;
};

#endif 
