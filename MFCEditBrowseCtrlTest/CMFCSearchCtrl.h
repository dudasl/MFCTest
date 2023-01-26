#pragma once


// CMFCSearchCtrl

class CMFCSearchCtrl : public CMFCEditBrowseCtrl
{
	DECLARE_DYNAMIC(CMFCSearchCtrl)

public:
	CMFCSearchCtrl();
	virtual ~CMFCSearchCtrl();

protected:
	DECLARE_MESSAGE_MAP()

    virtual void OnDrawBrowseButton(CDC* pDC, CRect rect, BOOL bIsButtonPressed, BOOL bIsButtonHot);
    virtual void OnBrowse();
};


