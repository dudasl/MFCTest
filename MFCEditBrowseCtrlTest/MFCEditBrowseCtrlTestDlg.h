
// MFCEditBrowseCtrlTestDlg.h : header file
//

#pragma once

#include "CMFCSearchCtrl.h"

// CMFCEditBrowseCtrlTestDlg dialog
class CMFCEditBrowseCtrlTestDlg : public CDialogEx
{
// Construction
public:
	CMFCEditBrowseCtrlTestDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCEDITBROWSECTRLTEST_DIALOG };
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
public:
    CMFCSearchCtrl search_edit_ctrl_;
};
