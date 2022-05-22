#include "ModalDialogue.h"
#include "GUI.h"
#include <wx/wxprec.h>


ModalDialogue::ModalDialogue(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{

	SetTitle(_("Modalny"));
	SetIcon(wxNullIcon);
	Center();

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxVERTICAL);

	bSizer3->SetMinSize(wxSize(150, -1));
	m_button_load_image = new wxButton(this, wxID_ANY, wxT("Load image"), wxDefaultPosition, wxSize(100, -1), 0);
	bSizer3->Add(m_button_load_image, 0, wxTOP | wxLEFT | wxALIGN_CENTER_HORIZONTAL, 5);

	m_button_load_image->Bind(wxEVT_BUTTON, &ModalDialogue::m_button_load_image_click, this);

	m_button_load_message = new wxButton(this, wxID_ANY, wxT("Load message"), wxDefaultPosition, wxSize(100, -1), 0);
	bSizer3->Add(m_button_load_message, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxLEFT, 5);

	m_button_load_message->Bind(wxEVT_BUTTON, &ModalDialogue::m_button_load_message_click, this);


	bSizer2->Add(bSizer3, 0, wxEXPAND | wxRIGHT, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	m_panel_image = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(20, 20), wxTAB_TRAVERSAL);

	bSizer4->Add(m_panel_image, 0, wxALL, 5);

	m_panel_message = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(20, 20), wxTAB_TRAVERSAL);

	bSizer4->Add(m_panel_message, 0, wxALL, 5);
	m_panel_message->SetBackgroundColour(wxColor(43, 243, 77));
	m_panel_image->SetBackgroundColour(wxColor(43, 243, 77));

	bSizer2->Add(bSizer4, 1, wxEXPAND | wxLEFT, 5);


	bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer(wxVERTICAL);

	m_button_save = new wxButton(this, wxID_ANY, wxT("Save!"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer5->Add(m_button_save, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 5);

	m_button_save->Bind(wxEVT_BUTTON, &ModalDialogue::m_button_save_click, this);

	bSizer1->Add(bSizer5, 1, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	Bind(wxEVT_CLOSE_WINDOW, &ModalDialogue::OnClose, this);

}

void ModalDialogue::m_button_load_image_click(wxCommandEvent& event)
{
	std::shared_ptr<wxFileDialog> WxOpenFileDialog1(new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("JPEG files (*.jpg)|*.jpg"), wxFD_OPEN));
	if (WxOpenFileDialog1->ShowModal() == wxID_OK)
	{
		if (!Img_Org.LoadFile(WxOpenFileDialog1->GetPath(), wxBITMAP_TYPE_JPEG))
			wxLogError(_("Nie mo¿na za³adowaæ obrazka"));
		else
		{
			wxImage TempImg(Img_Org);
		}
		if (MyBitmap.Ok()) this->SetTitle(WxOpenFileDialog1->GetPath());
	}
}

void ModalDialogue::m_button_load_message_click(wxCommandEvent& event)
{
	std::shared_ptr<wxFileDialog> WxOpenFileDialog1(new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("JPEG files (*.jpg)|*.jpg"), wxFD_OPEN));
	if (WxOpenFileDialog1->ShowModal() == wxID_OK)
	{
		if (!Img_message.LoadFile(WxOpenFileDialog1->GetPath(), wxBITMAP_TYPE_JPEG))
			wxLogError(_("Nie mo¿na za³adowaæ obrazka"));
		else
		{
			wxImage TempImg(Img_message);
		}
		if (MyBitmap.Ok()) this->SetTitle(WxOpenFileDialog1->GetPath());
	}
}

void ModalDialogue::m_button_save_click(wxCommandEvent& event) {
	EndModal(wxID_OK);
}

void ModalDialogue::setGreen() {
	m_panel_message->SetBackgroundColour(wxColor(43, 243, 77));
	m_panel_image->SetBackgroundColour(wxColor(43, 243, 77));
	
}

wxImage ModalDialogue::getImage() {
	return Img_Org;
}

wxImage ModalDialogue::getMessage() {
	return Img_message;
}