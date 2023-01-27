// CMFCFontComboBoxEx.cpp : implementation file
//

#include "pch.h"
#include "MFCFontComboBoxTest.h"
#include "CMFCFontComboBoxEx.h"
#include <memory>


// CMFCFontComboBoxEx

IMPLEMENT_DYNAMIC(CMFCFontComboBoxEx, CMFCFontComboBox)

CMFCFontComboBoxEx::CMFCFontComboBoxEx()
{

}

CMFCFontComboBoxEx::~CMFCFontComboBoxEx()
{
}


BEGIN_MESSAGE_MAP(CMFCFontComboBoxEx, CMFCFontComboBox)
    ON_WM_DRAWITEM()
END_MESSAGE_MAP()



// CMFCFontComboBoxEx message handlers


void CMFCFontComboBoxEx::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    if (nIDCtl == this->GetDlgCtrlID()) {
        if (lpDrawItemStruct->itemID == 0 || lpDrawItemStruct->itemID == 1) {
            LPCTSTR all_fonts_text = _T("All fonts");
            LPCTSTR recent_fonts_text = _T("Recent fonts");
            LPCTSTR text_to_draw = lpDrawItemStruct->itemID == 0 ? all_fonts_text : recent_fonts_text;
            int text_to_draw_len = static_cast<int>(_tcslen(text_to_draw));
            HBRUSH brush = ::CreateSolidBrush(RGB(200, 200, 200));
            HFONT font = NULL;
            LOGFONT log_font = {};
            if (this->GetFont()->GetLogFont(&log_font) != 0) {
                log_font.lfWeight = FW_BOLD;
                font = ::CreateFontIndirect(&log_font);
            }
            ::FillRect(lpDrawItemStruct->hDC, &lpDrawItemStruct->rcItem, brush);
            HGDIOBJ old_font = ::SelectObject(lpDrawItemStruct->hDC, font);
            ::DrawText(lpDrawItemStruct->hDC, text_to_draw, text_to_draw_len, &lpDrawItemStruct->rcItem, DT_LEFT | DT_TOP);
            ::SelectObject(lpDrawItemStruct->hDC, old_font);
            ::DeleteObject(font);
            ::DeleteObject(brush);
            return;
        }
    }

    CMFCFontComboBox::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
