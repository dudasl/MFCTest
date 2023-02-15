
// MarlettFontTestDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MarlettFontTest.h"
#include "MarlettFontTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMarlettFontTestDlg dialog



CMarlettFontTestDlg::CMarlettFontTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MARLETTFONTTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMarlettFontTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_GLYPH_STATIC, glyph_ctrl_);
    DDX_Control(pDX, IDC_GLYPH_SPIN, glyph_spin_ctrl_);
}

BEGIN_MESSAGE_MAP(CMarlettFontTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_WM_GETMINMAXINFO()
    ON_NOTIFY(UDN_DELTAPOS, IDC_GLYPH_SPIN, &CMarlettFontTestDlg::OnDeltaposGlyphSpin)
END_MESSAGE_MAP()


// CMarlettFontTestDlg message handlers

void CMarlettFontTestDlg::UpdateTitle()
{
    CString title;
    title.Format(_T("Glyph ID: %d"), this->glyph_ctrl_.GetGlyph());
    this->SetWindowText(title);
}

BOOL CMarlettFontTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

    RECT window_rect = {};
    this->GetWindowRect(&window_rect);
    this->init_dlg_width_ = window_rect.right - window_rect.left;
    this->init_dlg_height_ = window_rect.bottom - window_rect.top;

    this->glyph_spin_ctrl_.SetRange(0, 40);
    this->glyph_spin_ctrl_.SetPos(7);
    this->glyph_ctrl_.SetGlyph(this->glyph_spin_ctrl_.GetPos());
    this->UpdateTitle();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMarlettFontTestDlg::OnPaint()
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
HCURSOR CMarlettFontTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMarlettFontTestDlg::OnGetMinMaxInfo(MINMAXINFO * lpMMI)
{
    CDialogEx::OnGetMinMaxInfo(lpMMI);

    if (this->init_dlg_width_ != 0)
        lpMMI->ptMinTrackSize.x = this->init_dlg_width_;
    if (this->init_dlg_height_ != 0)
        lpMMI->ptMinTrackSize.y = this->init_dlg_height_;
}


void CMarlettFontTestDlg::OnDeltaposGlyphSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
    int newPos = pNMUpDown->iPos + pNMUpDown->iDelta;
    if (newPos >= 0 && newPos <= 40) {
        this->glyph_ctrl_.SetGlyph(pNMUpDown->iPos + pNMUpDown->iDelta);
        this->UpdateTitle();
    }
    *pResult = 0;
}
