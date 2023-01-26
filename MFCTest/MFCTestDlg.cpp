
// MFCTestDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCTest.h"
#include "MFCTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTestDlg dialog



CMFCTestDlg::CMFCTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCTEST_DIALOG, pParent)
    , radio_selected_(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_NOTIFICATION_LIST, notification_list_);
    DDX_Control(pDX, IDC_EDITABLE_COMBO, editable_combobox_);
    DDX_Control(pDX, IDC_RECURSIVE_EDIT, recursive_edit_);
    DDX_Radio(pDX, IDC_RADIO1, radio_selected_);
    DDX_Control(pDX, IDC_SIMPLE_COMBOBOX, simple_combobox_);
    DDX_Control(pDX, IDC_CUEBANNER_EDIT, cuebanner_edit_);
}

BEGIN_MESSAGE_MAP(CMFCTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_CBN_EDITCHANGE(IDC_EDITABLE_COMBO, &CMFCTestDlg::OnCbnEditchangeEditableCombo)
    ON_CBN_SELCHANGE(IDC_EDITABLE_COMBO, &CMFCTestDlg::OnCbnSelchangeEditableCombo)
    ON_BN_CLICKED(IDC_EXPAND_BUTTON, &CMFCTestDlg::OnBnClickedExpandButton)
    ON_CBN_EDITUPDATE(IDC_EDITABLE_COMBO, &CMFCTestDlg::OnCbnEditupdateEditableCombo)
    ON_BN_CLICKED(IDC_SETTEXT_BUTTON, &CMFCTestDlg::OnBnClickedSettextButton)
    ON_WM_CTLCOLOR()
    ON_EN_CHANGE(IDC_RECURSIVE_EDIT, &CMFCTestDlg::OnEnChangeRecursiveEdit)
    ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO1, IDC_RADIO3, &CMFCTestDlg::OnBnClickedRadio)
    ON_BN_CLICKED(IDC_SIMPLEEXPAND_BUTTON, &CMFCTestDlg::OnBnClickedSimpleexpandButton)
    ON_BN_CLICKED(IDC_SETCUEBANNER_BUTTON, &CMFCTestDlg::OnBnClickedSetcuebannerButton)
    ON_WM_CTLCOLOR()
    ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CMFCTestDlg message handlers

BOOL CMFCTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

    // Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

    COMBOBOXEXITEM item0{};
    COMBOBOXEXITEM item1{};
    COMBOBOXEXITEM item2{};

    item0.mask = item1.mask = item2.mask = CBEIF_TEXT;
    item0.pszText = _T("Item 0");
    item1.pszText = _T("Item 1");
    item2.pszText = _T("Item 2");
    item0.iItem = 0;
    item1.iItem = 1;
    item2.iItem = 2;

    this->editable_combobox_.InsertItem(&item0);
    this->editable_combobox_.InsertItem(&item1);
    this->editable_combobox_.InsertItem(&item2);

    this->simple_combobox_.AddString(_T("Simple item 0"));
    this->simple_combobox_.AddString(_T("Simple item 1"));
    this->simple_combobox_.AddString(_T("Simple item 2"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCTestDlg::OnCbnEditchangeEditableCombo()
{
    //CComboBoxEx *combo_ctrl = static_cast<CComboBoxEx *>(this->GetDlgItem(IDC_EDITABLE_COMBO));
    //if (!combo_ctrl)
    //    return;

    //CString curr_value;
    //combo_ctrl->GetWindowText(curr_value);
    //int curr_sel = combo_ctrl->GetCurSel();

    //CString notification_str;
    //notification_str.Format(_T("CBN_EDITCHANGE - %s Selection: %d)"), (LPCTSTR)curr_value, curr_sel);

    //notification_list_.AddString(notification_str);
    ////TRACE(_T("Editable combo-box: Text changed.\n\tValue is: %s\n\tIndex is: %d\n"), ((LPCTSTR)curr_value), curr_sel);
}

void CMFCTestDlg::OnCbnSelchangeEditableCombo()
{
    CComboBoxEx *combo_ctrl = static_cast<CComboBoxEx *>(this->GetDlgItem(IDC_EDITABLE_COMBO));
    if (!combo_ctrl)
        return;

    CString curr_value;
    combo_ctrl->GetWindowText(curr_value);
    int curr_sel = combo_ctrl->GetCurSel();

    CString notification_str;
    notification_str.Format(_T("CBN_SELCHANGE - %s Selection: %d)"), (LPCTSTR)curr_value, curr_sel);

    notification_list_.AddString(notification_str);
    //TRACE(_T("Editable combo-box: Selection changed.\n\tValue is: %s\n\tIndex is: %d\n"), ((LPCTSTR)curr_value), curr_sel);

    //combo_ctrl->SendMessage(WM_SETTEXT, NULL, (LPARAM)(LPCTSTR)curr_value);
    //this->editable_combobox_edit_.SetFilterNextSetTextMessage();
}

void CMFCTestDlg::OnBnClickedExpandButton()
{
    CComboBoxEx *combo_ctrl = static_cast<CComboBoxEx *>(this->GetDlgItem(IDC_EDITABLE_COMBO));
    if (!combo_ctrl)
        return;

    combo_ctrl->ShowDropDown();
    combo_ctrl->SetFocus();
}


void CMFCTestDlg::OnCbnEditupdateEditableCombo()
{
    CComboBoxEx *combo_ctrl = static_cast<CComboBoxEx *>(this->GetDlgItem(IDC_EDITABLE_COMBO));
    if (!combo_ctrl)
        return;

    CString curr_value;
    combo_ctrl->GetWindowText(curr_value);
    int curr_sel = combo_ctrl->GetCurSel();

    CString notification_str;
    notification_str.Format(_T("CBN_EDITUPDATE - %s Selection: %d)"), (LPCTSTR)curr_value, curr_sel);

    notification_list_.AddString(notification_str);
    //TRACE(_T("Editable combo-box: CBN_EDITUPDATE.\n\tValue is: %s\n\tIndex is: %d\n"), ((LPCTSTR)curr_value), curr_sel);

    //combo_ctrl->SendMessage(WM_SETTEXT, NULL, (LPARAM)(LPCTSTR)curr_value);
}


void CMFCTestDlg::OnBnClickedSettextButton()
{
    CComboBoxEx *combo_ctrl = static_cast<CComboBoxEx *>(this->GetDlgItem(IDC_EDITABLE_COMBO));
    if (!combo_ctrl)
        return;

    combo_ctrl->SetWindowText(_T("abc"));
}


void CMFCTestDlg::OnEnChangeRecursiveEdit()
{
    // TODO:  If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CDialogEx::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.
    static int num_notifications = 0;
    
    CString notification_str;
    notification_str.Format(_T("EN_CHANGE - Call SetWindowText from notification number %d"), num_notifications % 5);

    num_notifications++;
    if (num_notifications % 5 == 0)
        notification_str.Append(_T(" - break"));
    notification_list_.AddString(notification_str);

    if (num_notifications % 5 != 0)
        this->recursive_edit_.SetWindowText(_T("a"));    
}


void CMFCTestDlg::OnBnClickedRadio(UINT id)
{
    CString notification_str;
    notification_str.Format(_T("BN_CLICKED - Button with ID %ud clicked"), id);
    notification_list_.AddString(notification_str);

    int old_radio_selected = this->radio_selected_;
    this->UpdateData(TRUE);
    if (old_radio_selected != this->radio_selected_) {
        notification_str.Format(_T("RADIO_SELCHANGE - Chaged selection from %d to %d"), old_radio_selected, this->radio_selected_);
        notification_list_.AddString(notification_str);
    }
}


void CMFCTestDlg::OnBnClickedSimpleexpandButton()
{
    this->simple_combobox_.ShowDropDown();
}

void CMFCTestDlg::OnBnClickedSetcuebannerButton()
{
    this->cuebanner_edit_.SendMessage(EM_SETCUEBANNER, FALSE, (LPARAM)_T("Add text..."));
}

HBRUSH CMFCTestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    if (pWnd && pWnd->GetDlgCtrlID() == IDC_CUEBANNER_EDIT && pWnd->GetWindowTextLength() > 0)
        pDC->SetTextColor(RGB(255, 0, 0)); // red text

    // TODO:  Return a different brush if the default is not desired
    return hbr;
}


void CMFCTestDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    // TODO: Add your message handler code here and/or call default

    CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
