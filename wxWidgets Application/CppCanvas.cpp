#include "CppCanvas.h"

#include "wx\dcclient.h"
#include "wx\dcmemory.h"
#include "wx\dcbuffer.h"

wxBEGIN_EVENT_TABLE(CppCanvas, wxHVScrolledWindow)
EVT_PAINT(CppCanvas::OnPaint)
wxEND_EVENT_TABLE()

CppCanvas::CppCanvas(wxWindow* parent) : wxHVScrolledWindow(parent, wxID_ANY)
{
    SetRowColumnCount(40,40);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

CppCanvas::~CppCanvas()
{
}

void CppCanvas::SetPixel(int n)
{
    Pixelsize = n;
    wxVarHScrollHelper::RefreshAll();
    wxVarVScrollHelper::RefreshAll();
    Refresh();
}

wxCoord CppCanvas::OnGetRowHeight(size_t row) const
{
    return wxCoord(Pixelsize);
}

wxCoord CppCanvas::OnGetColumnWidth(size_t col) const
{
    return wxCoord(Pixelsize);
}
void CppCanvas::OnDraw(wxDC &dc)
{
    dc.Clear();
    wxBrush NewBrush = dc.GetBrush();
    wxPen NewPen = dc.GetPen();
    wxPosition s = GetVisibleBegin();
    wxPosition e = GetVisibleEnd();

    NewPen.SetStyle(wxPENSTYLE_DOT_DASH);
    NewPen.SetColour(200, 200, 200);
    dc.SetPen(NewPen);

    dc.SetBrush(NewBrush);
    dc.DrawRectangle(20, 20, 200, 200);
}

void CppCanvas::OnPaint(wxPaintEvent &evt)
{
    wxBufferedPaintDC dc(this);
    this->PrepareDC(dc);
    this->OnDraw(dc);
}
