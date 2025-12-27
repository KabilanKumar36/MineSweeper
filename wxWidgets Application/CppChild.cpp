#include "CppChild.h"



wxBEGIN_EVENT_TABLE(CppChild, wxMDIChildFrame)

EVT_SLIDER(20001, CppChild::OnZoomChange)

wxEND_EVENT_TABLE()


CppChild::CppChild(wxMDIParentFrame* parent, wxString sname) : wxMDIChildFrame(parent, wxID_ANY, sname)
{
	NewCanvas = new CppCanvas(this);
	StatusBar = this->CreateStatusBar(2, wxSTB_DEFAULT_STYLE, wxID_ANY);
	ZoomSlider = new wxSlider(StatusBar, 20001, 8, 1, 32);
}

CppChild::~CppChild()
{
}

void CppChild::OnZoomChange(wxCommandEvent& evt)
{
	StatusBar->SetStatusText(wxString("Zoom : ") << ZoomSlider->GetValue(), 1);
	NewCanvas->SetPixel(ZoomSlider->GetValue());
}

