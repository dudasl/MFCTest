// CGlyphStatic.cpp : implementation file
//

#include "pch.h"
#include "MarlettFontTest.h"
#include "CGlyphStatic.h"


// CGlyphStatic

IMPLEMENT_DYNAMIC(CGlyphStatic, CStatic)

CGlyphStatic::CGlyphStatic()
{

}

CGlyphStatic::~CGlyphStatic()
{
}

void CGlyphStatic::SetGlyph(WORD glyph_id)
{
    this->glyph_id_ = glyph_id;

    this->RedrawWindow();
}


BEGIN_MESSAGE_MAP(CGlyphStatic, CStatic)
END_MESSAGE_MAP()



// CGlyphStatic message handlers


void CGlyphStatic::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    CDC* dc = this->GetDC();

    LOGFONT lf = {};
    lf.lfHeight = 1200;
    lf.lfWeight = FW_NORMAL;
    lf.lfCharSet = SYMBOL_CHARSET;
    wcscpy_s(lf.lfFaceName, L"Marlett");

    CFont font;
    if (!font.CreatePointFontIndirect(&lf, dc))
        return;

    CRect rect;
    this->GetClientRect(&rect);

    CBrush brush;
    brush.CreateSolidBrush(RGB(255, 255, 255));
    dc->FillRect(rect, &brush);

    CFont * old_font = dc->SelectObject(&font);
    dc->ExtTextOutW(0, 0, ETO_GLYPH_INDEX | ETO_CLIPPED, rect, (LPCTSTR)&this->glyph_id_, 1, NULL);
    dc->SelectObject(old_font);
}


void CGlyphStatic::PreSubclassWindow()
{
    this->ModifyStyle(0, SS_OWNERDRAW, 0);

    CStatic::PreSubclassWindow();
}
