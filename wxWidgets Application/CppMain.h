#pragma once
#include <wx/wx.h>
#include <wx/frame.h>

#include "CppChild.h"

class CppMain : public wxMDIParentFrame
{
public:
	CppMain();
	~CppMain();

	wxMenuBar *m_Menubar = nullptr;
	wxToolBar* m_Toolbar = nullptr;

	void OnSelectColor(wxCommandEvent &evt);

	wxTextCtrl *m_txt1 = nullptr;
	wxButton* m_btn1 = nullptr;
	wxListBox *m_lst1 = nullptr;
	void OnbuttonClicked(wxCommandEvent &evt);
	void OnMenuNew(wxCommandEvent& evt);
	void OnMenuOpen(wxCommandEvent& evt);
	void OnMenuSave(wxCommandEvent& evt);
	void OnMenuExit(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

