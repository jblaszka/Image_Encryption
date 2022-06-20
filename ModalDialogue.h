#include <wx/wxprec.h>
#ifndef __ModalnyDlg_h__
#define __ModalnyDlg_h__

class ModalDialogue : public wxDialog
{
private:
    wxButton* m_button_load_image;
    wxButton* m_button_load_code;
    wxButton* m_button_load_message;
    wxPanel* m_panel_image;
    wxPanel* m_panel_message;
    wxPanel* m_panel_code;
    wxButton* m_button_save;


public:
    ModalDialogue(wxWindow* parent, wxWindowID id = 1, const wxString& title = _("Modalny"),
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(250, 150),
        long style = wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX);


    void m_button_load_image_click(wxCommandEvent& event);
    void m_button_load_code_click(wxCommandEvent& event);
    void m_button_load_message_click(wxCommandEvent& event);
    void m_button_save_click(wxCommandEvent& event);
    void add_new_button();
    void add_new_indicator();
    void OnClose(wxCloseEvent& event) { Destroy(); }
    void setIndicatorMessage();
    void setIndicatorImage();
    void setIndicatorCode();
    void setFirstButtonText(wxString text);
    void setSecondButtonText(wxString text);

    wxImage getImage();
    wxImage getMessage();
    wxImage getCode();

    wxImage Img_message, Img_Org, Img_code;
    wxBitmap MyBitmap;
    bool checking = false;

};

#endif