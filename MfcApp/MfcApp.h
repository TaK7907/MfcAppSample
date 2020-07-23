
// MfcApp.h : main header file for the MfcApp application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMfcAppApp:
// See MfcApp.cpp for the implementation of this class
//

class CMfcAppApp : public CWinApp
{
public:
	CMfcAppApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMfcAppApp theApp;
