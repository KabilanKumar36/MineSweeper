#pragma once
#include <wx/wx.h>
#include <wx/frame.h>

class cppMinesweeper : public wxFrame
{
public:
	cppMinesweeper();
	~cppMinesweeper();

	int width = 10;
	int height = 10;
	wxButton** btn;
	int* field = nullptr;
	bool firstclick = true;

	void OnbuttonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

