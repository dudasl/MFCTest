#pragma once


// CMFCFontComboBoxEx

class CMFCFontComboBoxEx : public CMFCFontComboBox
{
	DECLARE_DYNAMIC(CMFCFontComboBoxEx)

public:
	CMFCFontComboBoxEx();
	virtual ~CMFCFontComboBoxEx();

protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
};


