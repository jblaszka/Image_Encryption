#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__
#include "GUI.h"
#include "MethodA.h"
#include "MethodB.h"

class GUIMyFrame1 : public MyFrame1
{
	protected:
		void m_button_code_click( wxCommandEvent& event );
		void m_button_decode_A_click( wxCommandEvent& event );
		void m_button_decode_B_click(wxCommandEvent& event);
		void m_button_decode_A_and_B_click(wxCommandEvent& event);

	public:
		ModalDialogue* dialog_modalny;
		ModalDialogue* dialog_modalny2;
		ModalDialogue* dialog_modalny3;
		ModalDialogue* dialog_modalny4;
		GUIMyFrame1( wxWindow* parent );
		void Repaint(wxImage image);
		wxImage Img_Message;
		wxImage Img_Code;
		wxImage Img_Reference;

};

#endif 