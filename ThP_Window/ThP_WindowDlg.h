
// ThP_WindowDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CThP_WindowDlg dialog
class CThP_WindowDlg : public CDialogEx
{
// Construction
public:
	CThP_WindowDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_THP_WINDOW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// Calculate outs percent
	afx_msg void OnBnClickedCout();
	//Calculate prize
	afx_msg void OnBnClickedCprize();
	//Statistics
	afx_msg void OnBnClickedDplus();
	afx_msg void OnBnClickedPplus();
	afx_msg void OnBnClickedWplus();
	afx_msg void OnBnClickedDminus();
	afx_msg void OnBnClickedPminus();
	afx_msg void OnBnClickedWminus();
	afx_msg void OnBnClickedReset();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedAbout();
	afx_msg void OnBnClickedResetstat();
};
