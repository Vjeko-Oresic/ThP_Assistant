
// ThP_Window.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CThP_WindowApp:
// See ThP_Window.cpp for the implementation of this class
//

class CThP_WindowApp : public CWinApp
{
public:
	CThP_WindowApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CThP_WindowApp theApp;