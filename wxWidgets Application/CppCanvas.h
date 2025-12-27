#pragma once
#include <wx\wx.h>
#include <wx\vscroll.h>

class CppCanvas : public wxHVScrolledWindow
{
public:
	CppCanvas(wxWindow *parent);
	~CppCanvas();

	void SetPixel(int n);

	void OnDraw(wxDC &evt);
	void OnPaint(wxPaintEvent &evt);

private:
	int Pixelsize = 8;

	

	virtual wxCoord OnGetRowHeight(size_t row) const;
	virtual wxCoord OnGetColumnWidth(size_t col) const;

	wxDECLARE_EVENT_TABLE();
};

