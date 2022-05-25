
#include "GUI.h"


MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	bSizer2->SetMinSize(wxSize(200, 533));
	m_button_code = new wxButton(this, wxID_ANY, wxT("Codee"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer2->Add(m_button_code, 0, wxEXPAND | wxTOP | wxLEFT, 5);

	m_button_decode = new wxButton(this, wxID_ANY, wxT("Decode"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer2->Add(m_button_decode, 0, wxEXPAND | wxTOP | wxLEFT, 5);

	bSizer1->Add(bSizer2, 0, wxEXPAND | wxRIGHT, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxVERTICAL);

	bSizer3->SetMinSize(wxSize(800, 533));
	m_scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(800, 533), wxHSCROLL | wxVSCROLL);
	m_scrolledWindow->SetScrollRate(5, 5);
	m_scrolledWindow->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
	m_scrolledWindow->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));

	bSizer3->Add(m_scrolledWindow, 1, wxEXPAND | wxALL, 5);

	bSizer1->Add(bSizer3, 1, wxEXPAND, 5);

	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	m_button_code->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_button_code_click), NULL, this);
	m_button_decode->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_button_decode_click), NULL, this);
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_button_code->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_button_code_click), NULL, this);
	m_button_decode->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_button_decode_click), NULL, this);
}
