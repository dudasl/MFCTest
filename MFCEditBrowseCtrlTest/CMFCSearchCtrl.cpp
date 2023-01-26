// CMFCSearchCtrl.cpp : implementation file
//

#include "pch.h"
#include "MFCEditBrowseCtrlTest.h"
#include "CMFCSearchCtrl.h"


// CMFCSearchCtrl

IMPLEMENT_DYNAMIC(CMFCSearchCtrl, CMFCEditBrowseCtrl)

CMFCSearchCtrl::CMFCSearchCtrl()
{

}

CMFCSearchCtrl::~CMFCSearchCtrl()
{
}


BEGIN_MESSAGE_MAP(CMFCSearchCtrl, CMFCEditBrowseCtrl)
END_MESSAGE_MAP()



// CMFCSearchCtrl message handlers

#ifndef USE_SetBrowseButtonImage
void CMFCSearchCtrl::OnDrawBrowseButton(CDC* pDC, CRect rect, BOOL bIsButtonPressed, BOOL bIsButtonHot)
{
    HICON search_icon = ::LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SEARCH_ICON));
    if (search_icon)
        pDC->DrawIcon(rect.TopLeft(), search_icon);
    else
        return CMFCEditBrowseCtrl::OnDrawBrowseButton(pDC, rect, bIsButtonPressed, bIsButtonHot);
}
#endif

void CMFCSearchCtrl::OnBrowse()
{
    CString search_text;
    this->GetWindowText(search_text);
    AfxMessageBox(search_text);
}
