
// MFCEditBrowseCtrlTestDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCEditBrowseCtrlTest.h"
#include "MFCEditBrowseCtrlTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCEditBrowseCtrlTestDlg dialog



CMFCEditBrowseCtrlTestDlg::CMFCEditBrowseCtrlTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCEDITBROWSECTRLTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCEditBrowseCtrlTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SEARCH_BUTTON, search_edit_ctrl_);
}

BEGIN_MESSAGE_MAP(CMFCEditBrowseCtrlTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFCEditBrowseCtrlTestDlg message handlers

BOOL CMFCEditBrowseCtrlTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

#ifdef USE_SetBrowseButtonImage
    // This code should go to initialize control. But how?
    HICON search_icon = ::LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SEARCH_ICON));
    if (search_icon)
        this->search_edit_ctrl_.SetBrowseButtonImage(search_icon);
#endif

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCEditBrowseCtrlTestDlg::OnPaint()
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
HCURSOR CMFCEditBrowseCtrlTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

