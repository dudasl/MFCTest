
// MFCTestDlg.h : header file
//

#pragma once

// CMFCTestDlg dialog
class CMFCTestDlg : public CDialogEx
{
// Construction
public:
	CMFCTestDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTEST_DIALOG };
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

private:
    CListBox notification_list_;
    CComboBoxEx editable_combobox_;
    CComboBox simple_combobox_;
    CEdit recursive_edit_;
    int radio_selected_;
    CEdit cuebanner_edit_;

public:
    afx_msg void OnCbnEditchangeEditableCombo();
    afx_msg void OnCbnSelchangeEditableCombo();
    afx_msg void OnBnClickedExpandButton();
    afx_msg void OnCbnEditupdateEditableCombo();
    afx_msg void OnBnClickedSettextButton();
    afx_msg void OnEnChangeRecursiveEdit();
    afx_msg void OnBnClickedRadio(UINT id);
    afx_msg void OnBnClickedSimpleexpandButton();
    afx_msg void OnBnClickedSetcuebannerButton();
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
};
