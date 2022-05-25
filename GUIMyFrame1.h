#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__
#include "GUI.h"
#include "MethodA.h"

class GUIMyFrame1 : public MyFrame1
{
	protected:
		void m_button_code_click( wxCommandEvent& event );
		void m_button_decode_click( wxCommandEvent& event );

	public:
		ModalDialogue* dialog_modalny;
		MethodA* method_A;
		GUIMyFrame1( wxWindow* parent );
		void Repaint();
		wxImage imageMain;
		wxImage imageMessage;
};

#endif 