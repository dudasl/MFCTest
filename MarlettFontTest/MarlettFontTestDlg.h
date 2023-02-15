
// MarlettFontTestDlg.h : header file
//

#pragma once

#include "CGlyphStatic.h"


// CMarlettFontTestDlg dialog
class CMarlettFontTestDlg : public CDialogEx
{
// Construction
public:
	CMarlettFontTestDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MARLETTFONTTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
private:
    LONG init_dlg_width_ = 0;
    LONG init_dlg_height_ = 0;
    CGlyphStatic glyph_ctrl_;
    CSpinButtonCtrl glyph_spin_ctrl_;

protected:
	HICON m_hIcon;

    void UpdateTitle();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnDeltaposGlyphSpin(NMHDR *pNMHDR, LRESULT *pResult);
};
