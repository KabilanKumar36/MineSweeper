#include "CppMain.h"
enum Events
{
	Startbutton = 10000,
	FileNew,
	FileOpen,
	FileSave,
	FileExit
};

wxBEGIN_EVENT_TABLE(CppMain, wxMDIParentFrame)

EVT_BUTTON(Startbutton, OnbuttonClicked)
EVT_MENU(FileNew, OnMenuNew)
EVT_MENU(FileOpen, OnMenuOpen)
EVT_MENU(FileSave, OnMenuSave)
EVT_MENU(FileExit, OnMenuExit)

wxEND_EVENT_TABLE()
CppMain::CppMain() : wxMDIParentFrame(nullptr, wxID_ANY, "Mine Sweeper", wxPoint(20,20), wxSize(1500, 800))
{
	m_Menubar = new wxMenuBar();
	this->SetMenuBar(m_Menubar);

	wxMenu* MenuFile = new wxMenu();
	MenuFile->Append(FileNew, "New");
	MenuFile->Append(FileOpen, "open");
	MenuFile->Append(FileSave, "Save");
	MenuFile->Append(FileExit, "Exit");

	m_Menubar->Append(MenuFile, "File");

	m_Toolbar = CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
	wxColor Palatte[4];
	Palatte[0] = wxColor(0, 0, 0);
	Palatte[1] = wxColor(128, 0, 0);
	Palatte[2] = wxColor(0, 128, 0);
	Palatte[3] = wxColor(0, 0, 128);

	for (int i = 0; i < 4; i++)
	{
		wxButton* b = new wxButton(m_Toolbar, 10100 + i, "", wxDefaultPosition, wxSize(40, 24), 0);
		b->SetBackgroundColour(Palatte[i]);
		b->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CppMain::OnSelectColor), nullptr, this);
		m_Toolbar->AddControl(b);
	}

	wxButton* b = new wxButton(m_Toolbar, 10105, "Alpha", wxDefaultPosition, wxSize(40, 24), 0);
	m_Toolbar->AddControl(b);

	m_Toolbar->Realize();

	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(5, 10), wxSize(200, 20));
	m_btn1 = new wxButton(this, Startbutton, "Start", wxPoint(5, 40), wxSize(200, 20));
	m_lst1 = new wxListBox(this, wxID_ANY,wxPoint(5, 70), wxSize(200, 200));
}

CppMain::~CppMain()
{
}
void CppMain::OnbuttonClicked(wxCommandEvent &evt)
{
	m_lst1->AppendString(m_txt1->GetValue());
	evt.Skip();
}
void CppMain::OnMenuNew(wxCommandEvent& evt)
{
	CppChild* c = new CppChild(this, "test_1");
	c->Show();
	evt.Skip();
}
void CppMain::OnMenuOpen(wxCommandEvent& evt)
{
}
void CppMain::OnMenuSave(wxCommandEvent& evt)
{
}
void CppMain::OnMenuExit(wxCommandEvent& evt)
{
	Close();
	evt.Skip();
}
void CppMain::OnSelectColor(wxCommandEvent& evt)
{

}