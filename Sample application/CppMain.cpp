#include "CppMain.h"
enum Events
{
	Startbutton = 10000
};

wxBEGIN_EVENT_TABLE(CppMain, wxFrame)

EVT_BUTTON(Startbutton, OnbuttonClicked)

wxEND_EVENT_TABLE()
CppMain::CppMain() : wxFrame(nullptr, wxID_ANY, "Mine Sweeper", wxPoint(20,20), wxSize(1500, 800))
{
	onInit();
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(5, 10), wxSize(200, 20));
	m_btn1 = new wxButton(this, Startbutton, "Start", wxPoint(5, 40), wxSize(200, 20));
	m_lst1 = new wxListBox(this, wxID_ANY,wxPoint(5, 70), wxSize(200, 200));
}

CppMain::~CppMain()
{
}
void CppMain::OnbuttonClicked(wxCommandEvent &evt)
{
	//onInit();
	m_lst1->AppendString(m_txt1->GetValue());
	evt.Skip();
}
bool CppMain::onInit()
{
	newframe1 = new cppMinesweeper();
	newframe1->Show();
	/*myFrame* newframe2 = new myFrame("New panel", wxDefaultPosition, wxDefaultSize);
	newframe2->Show(true);*/
	
	/*wxPanel* TopPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(250, 200), wxDD_DEFAULT_STYLE, "Top panel");
	TopPanel->SetBackgroundColour(wxColor(100, 100, 200));

	wxPanel* BottomPanel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(50, 200), wxDD_DEFAULT_STYLE, "Left Base panel");
	BottomPanel1->SetBackgroundColour(wxColor(200, 100, 200));
	wxPanel* BottomPanel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150, 200), wxDD_DEFAULT_STYLE, "Right Base panel");
	BottomPanel2->SetBackgroundColour(wxColor(200, 200, 100));

	/*wxPanel* BottomPanel2_1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(75, 200), wxDD_DEFAULT_STYLE, "Right Base panel_part1");
	BottomPanel2->SetBackgroundColour(wxColor(100, 200, 100));

	wxBoxSizer* newsizer3 = new wxBoxSizer(wxHORIZONTAL);
	newsizer3->Add(BottomPanel2, 1, 0, 15);
	newsizer3->Add(BottomPanel2_1, 1, 0, 15);
	wxBoxSizer* newsizer2 = new wxBoxSizer(wxHORIZONTAL);
	newsizer2->Add(BottomPanel1, 1, 0, 15);
	newsizer2->Add(BottomPanel2, 3, 0, 15);
	//newsizer2->Add(newsizer3, 3, 0, 15);
	wxBoxSizer* newsizer1 = new wxBoxSizer(wxVERTICAL);
	newsizer1->Add(TopPanel, 3, wxEXPAND | wxALL, 15);
	newsizer1->Add(newsizer2, 1, wxEXPAND | wxTop | wxLeft | wxRight, 15);

	this->SetSizer(newsizer1);*/
	
	return true;
}

myFrame::myFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
	: wxFrame(nullptr, wxID_ANY, title, pos, size)
{
	wxPanel *TopPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(250, 200), wxDD_DEFAULT_STYLE, "Top panel");
	TopPanel->SetBackgroundColour(wxColor(100, 100, 200));
	
	wxPanel* BottomPanel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(50, 200), wxDD_DEFAULT_STYLE, "Left Base panel");
	BottomPanel1->SetBackgroundColour(wxColor(200, 100, 200));
	wxPanel* BottomPanel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150, 200), wxDD_DEFAULT_STYLE, "Right Base panel");
	BottomPanel2->SetBackgroundColour(wxColor(200, 200, 100));
	
	
	wxBoxSizer* newsizer2 = new wxBoxSizer(wxHORIZONTAL)
;
	newsizer2->Add(BottomPanel1, 1, 0, 15);
	newsizer2->Add(BottomPanel2, 3, 0, 15);
	wxBoxSizer* newsizer1 = new wxBoxSizer(wxVERTICAL);
	newsizer1->Add(TopPanel, 3, wxEXPAND| wxALL, 15);
	newsizer1->Add(newsizer2, 1, wxEXPAND | wxTop | wxLeft | wxRight, 15);

	this->SetSizer(newsizer1);
}