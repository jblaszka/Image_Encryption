#include <wx/wx.h>
#include "GUIMyFrame1.h"



class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	wxFrame* mainFrame = new GUIMyFrame1(NULL);

	wxImage::AddHandler(new wxJPEGHandler);           // Dodajemy handlery do formatow
	wxImage::AddHandler(new wxPNGHandler);            // z jakich bedziemy korzytsac

	mainFrame->Show(true);

	return true;
}