#pragma once
#include <wx/wx.h>
#include <wx/frame.h>
#include "cppMinesweeper.h"

class CppMain : public wxFrame
{
public:
	CppMain();
	~CppMain();

	wxTextCtrl *m_txt1 = nullptr;
	wxButton* m_btn1 = nullptr;
	wxListBox *m_lst1 = nullptr;

	void OnbuttonClicked(wxCommandEvent &evt);

	virtual bool onInit();

	wxDECLARE_EVENT_TABLE();
private:
	cppMinesweeper* newframe1 = nullptr;
};

class myFrame : public wxFrame
{
public:
	myFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
};

