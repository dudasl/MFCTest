
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
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCFontComboBoxTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_FONT_COMBO, font_combo_);
}

BEGIN_MESSAGE_MAP(CMFCFontComboBoxTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


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
