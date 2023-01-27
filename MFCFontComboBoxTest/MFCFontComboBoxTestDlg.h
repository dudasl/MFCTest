
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
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
    CMFCFontComboBoxEx font_combo_;
    CFont font_;
};
