
// MFCFontComboBoxTestDlg.h : header file
//

#pragma once

#include "CMFCFontComboBoxEx.h"


// CMFCFontComboBoxTestDlg dialog
class CMFCFontComboBoxTestDlg : public CDialogEx
{
// Construction
public:
	CMFCFontComboBoxTestDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCFONTCOMBOBOXTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
private:
    LONG init_dlg_width_ = 0;
    LONG init_dlg_height_ = 0;

    CString font_name_value_;
    CString script_name_value_;

private:
    void FillFontInfo(const CMFCFontInfo* fontInfo);

protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
    CMFCFontComboBoxEx font_combo_;
    CFont font_;
public:
    afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
    afx_msg void OnSelchangeFontCombo();
};
