#include <wx/wxprec.h>
#ifndef __ModalnyDlg_h__
#define __ModalnyDlg_h__

class ModalnyDlg : public wxDialog
{
private:
    wxButton* WxButton1;
    wxButton* WxButton2;
    wxStaticText* WxStaticText1;
public:
    ModalnyDlg(wxWindow* parent, wxWindowID id = 1, const wxString& title = _("Modalny"),
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX);
    void WxButton1Click(wxCommandEvent& event);
    void WxButton2Click(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event) { Destroy(); }
    wxImage Img_Org, // tu bedzie przechowywany oryginalny obrazek
        Img_Cpy;
    wxBitmap MyBitmap;
    wxImage dajObraz();

};

#endif
