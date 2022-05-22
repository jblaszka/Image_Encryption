#include "ModalnyDlg.h"
#include "GUIMyFrame1.h" 
#include <wx/wxprec.h>

GUIMyFrame1* frame;

ModalnyDlg::ModalnyDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	SetTitle(_("Modalny"));
	SetIcon(wxNullIcon);
	SetSize(8, 8, 368, 185);
	Center();

	WxButton1 = new wxButton(this, wxID_ANY, _("OK"), wxPoint(126, 80), wxSize(86, 28), 0, wxDefaultValidator, _("WxButton1"));
	WxButton1->Bind(wxEVT_BUTTON, &ModalnyDlg::WxButton1Click, this);


	WxButton2 = new wxButton(this, wxID_ANY, _("Tesst"), wxPoint(126, 50), wxSize(86, 28), 0, wxDefaultValidator, _("WxButton2"));
	WxButton2->Bind(wxEVT_BUTTON, &ModalnyDlg::WxButton2Click, this);

	WxStaticText1 = new wxStaticText(this, wxID_ANY, _("Wciœnij OKii"), wxPoint(44, 24), wxDefaultSize, 0, _("WxStaticText1"));

	Bind(wxEVT_CLOSE_WINDOW, &ModalnyDlg::OnClose, this);

	Img_Org = wxImage(800, 533);
	Img_Cpy = wxImage(800, 533);
}



void ModalnyDlg::WxButton1Click(wxCommandEvent& event)
{
	EndModal(wxID_OK);
}



void ModalnyDlg::WxButton2Click(wxCommandEvent& event)
{
		std::shared_ptr<wxFileDialog> WxOpenFileDialog1(new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("JPEG files (*.jpg)|*.jpg"), wxFD_OPEN));
		if (WxOpenFileDialog1->ShowModal() == wxID_OK)
		{
			if (!Img_Org.LoadFile(WxOpenFileDialog1->GetPath(), wxBITMAP_TYPE_JPEG))
				wxLogError(_("Nie mo¿na za³adowaæ obrazka"));
			else
			{
				wxImage TempImg(Img_Org);
				Img_Cpy = Img_Org.Copy();
				//frame->setImage(Img_Org);
			}
			if (MyBitmap.Ok()) this->SetTitle(WxOpenFileDialog1->GetPath());
		}
}

wxImage ModalnyDlg::dajObraz(){
	return Img_Cpy;
}


