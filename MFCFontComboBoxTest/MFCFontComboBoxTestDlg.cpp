
// MFCFontComboBoxTestDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCFontComboBoxTest.h"
#include "MFCFontComboBoxTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCFontComboBoxTestDlg dialog



CMFCFontComboBoxTestDlg::CMFCFontComboBoxTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCFONTCOMBOBOXTEST_DIALOG, pParent)
    , font_name_value_(_T(""))
    , script_name_value_(_T(""))
    , full_name_value_(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCFontComboBoxTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_FONT_COMBO, font_combo_);
    DDX_Text(pDX, IDC_FONT_NAME_STATIC, font_name_value_);
    DDX_Text(pDX, IDC_SCRIPT_NAME_STATIC, script_name_value_);
    DDX_Text(pDX, IDC_FULL_NAME_STATIC, full_name_value_);
}

BEGIN_MESSAGE_MAP(CMFCFontComboBoxTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_WM_GETMINMAXINFO()
    ON_CBN_SELCHANGE(IDC_FONT_COMBO, &CMFCFontComboBoxTestDlg::OnSelchangeFontCombo)
END_MESSAGE_MAP()

void CMFCFontComboBoxTestDlg::FillFontInfo(const CMFCFontInfo* fontInfo)
{
    if (fontInfo == nullptr) {
        this->font_name_value_.Empty();
        this->script_name_value_.Empty();
        this->full_name_value_.Empty();
    }
    else {
        this->font_name_value_ = fontInfo->m_strName;
        this->script_name_value_ = fontInfo->m_strScript;
        this->full_name_value_ = fontInfo->GetFullName();
    }

    this->UpdateData(FALSE);
}

// CMFCFontComboBoxTestDlg message handlers

BOOL CMFCFontComboBoxTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

    LOGFONT log_font = {};
    if (this->font_combo_.GetFont()->GetLogFont(&log_font) != 0) {
        log_font.lfHeight = 20;
        font_.CreateFontIndirect(&log_font);
        this->font_combo_.SetFont(&this->font_, FALSE);
    }

    this->font_combo_.InsertString(0, _T("All fonts"));
    this->font_combo_.SetItemHeight(0, 20);
    this->font_combo_.InsertString(0, _T("Recent fonts"));
    this->font_combo_.SetItemHeight(0, 20);
    this->font_combo_.m_bDrawUsingFont = TRUE;

    RECT window_rect = {};
    this->GetWindowRect(&window_rect);
    this->init_dlg_width_ = window_rect.right - window_rect.left;
    this->init_dlg_height_ = window_rect.bottom - window_rect.top;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCFontComboBoxTestDlg::OnPaint()
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
HCURSOR CMFCFontComboBoxTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCFontComboBoxTestDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
    CDialogEx::OnGetMinMaxInfo(lpMMI);

    if (this->init_dlg_width_ != 0)
        lpMMI->ptMinTrackSize.x = this->init_dlg_width_;
    if (this->init_dlg_height_ != 0)
        lpMMI->ptMinTrackSize.y = lpMMI->ptMaxTrackSize.y = this->init_dlg_height_;
}

void CMFCFontComboBoxTestDlg::OnSelchangeFontCombo()
{
    this->FillFontInfo(this->font_combo_.GetSelFont());

#ifdef _DEBUG
    DWORD_PTR item_data = this->font_combo_.GetItemData(this->font_combo_.GetCurSel());
    void* item_data_ptr = this->font_combo_.GetItemDataPtr(this->font_combo_.GetCurSel());
    item_data_ptr = item_data_ptr;
#endif
}
