#pragma once
#include <wx/wx.h>

#include "CppCanvas.h"

class CppChild : public wxMDIChildFrame
{
public:
	CppChild(wxMDIParentFrame* parent, wxString sname);
	~CppChild();

	void OnZoomChange(wxCommandEvent& evt);


private:
	CppCanvas* NewCanvas = nullptr;

	wxStatusBar *StatusBar = nullptr;
	wxSlider *ZoomSlider = nullptr;

	wxDECLARE_EVENT_TABLE();
};

