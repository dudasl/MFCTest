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
        if (this->GetItemDataPtr(lpDrawItemStruct->itemID) == nullptr) {
            // Drawing "Recent fonts" or "All fonts"
            CString item_text;
            this->GetLBText(lpDrawItemStruct->itemID, item_text);
            HBRUSH brush = ::CreateSolidBrush(RGB(200, 200, 200));
            HFONT font = NULL;
            HGDIOBJ old_font = NULL;
            LOGFONT log_font = {};
            if (this->GetFont()->GetLogFont(&log_font) != 0) {
                log_font.lfWeight = FW_BOLD;
                font = ::CreateFontIndirect(&log_font);
                old_font = ::SelectObject(lpDrawItemStruct->hDC, font);
            }

            ::FillRect(lpDrawItemStruct->hDC, &lpDrawItemStruct->rcItem, brush);
            ::DrawText(lpDrawItemStruct->hDC, item_text, item_text.GetLength(), &lpDrawItemStruct->rcItem, DT_LEFT | DT_TOP);

            if (old_font)
                ::SelectObject(lpDrawItemStruct->hDC, old_font);
            ::DeleteObject(font);
            ::DeleteObject(brush);
            return;
        }
    }

    CMFCFontComboBox::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
