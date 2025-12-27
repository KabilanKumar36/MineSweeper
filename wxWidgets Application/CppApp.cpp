#include "CppApp.h"

wxIMPLEMENT_APP(CppApp);

CppApp::CppApp()
{

}
CppApp::~CppApp()
{

}
bool CppApp::OnInit()
{
	newframe = new CppMain();
	newframe->Show();
	return true;
}