
// MFCEditBrowseCtrlTest.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCEditBrowseCtrlTestApp:
// See MFCEditBrowseCtrlTest.cpp for the implementation of this class
//

class CMFCEditBrowseCtrlTestApp : public CWinApp
{
public:
	CMFCEditBrowseCtrlTestApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCEditBrowseCtrlTestApp theApp;
