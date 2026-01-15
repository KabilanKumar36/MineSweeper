#pragma once
#include <wx/wx.h>
#include "CppMain.h"

class CppApp : public wxApp
{
public:
	CppApp();
	~CppApp();

	virtual bool OnInit();
private:
	CppMain* newframe = nullptr;

};

