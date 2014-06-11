
// ThP_WindowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ThP_Window.h"
#include "ThP_WindowDlg.h"
#include "afxdialogex.h"

#include "..\ThP_Assistant\Outs.h"
#include "..\ThP_Assistant\Payouts.h"
#include "..\ThP_Assistant\Statistics.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CThP_WindowDlg dialog


CThP_WindowDlg::CThP_WindowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThP_WindowDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThP_WindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CThP_WindowDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_COUT, &CThP_WindowDlg::OnBnClickedCout)
	ON_BN_CLICKED(IDC_CPRIZE, &CThP_WindowDlg::OnBnClickedCprize)
	ON_BN_CLICKED(IDC_DPLUS, &CThP_WindowDlg::OnBnClickedDplus)
	ON_BN_CLICKED(IDC_PPLUS, &CThP_WindowDlg::OnBnClickedPplus)
	ON_BN_CLICKED(IDC_WPLUS, &CThP_WindowDlg::OnBnClickedWplus)
	ON_BN_CLICKED(IDC_DMINUS, &CThP_WindowDlg::OnBnClickedDminus)
	ON_BN_CLICKED(IDC_PMINUS, &CThP_WindowDlg::OnBnClickedPminus)
	ON_BN_CLICKED(IDC_WMINUS, &CThP_WindowDlg::OnBnClickedWminus)
	ON_BN_CLICKED(IDC_RESET, &CThP_WindowDlg::OnBnClickedReset)
	ON_BN_CLICKED(IDC_ADD, &CThP_WindowDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_ABOUT, &CThP_WindowDlg::OnBnClickedAbout)
	ON_BN_CLICKED(IDC_RESETSTAT, &CThP_WindowDlg::OnBnClickedResetstat)
END_MESSAGE_MAP()


// CThP_WindowDlg message handlers

BOOL CThP_WindowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SetDlgItemInt(IDC_DNUMBER, 0);
	SetDlgItemInt(IDC_PNUMBER, 0);
	SetDlgItemInt(IDC_WNUMBER, 0);
	CheckRadioButton(IDC_FLOP, IDC_TURN, IDC_FLOP);
	//Add values form file to edit box
	struct ThP::ReadValues value = ThP::ReadFromFile();
	SetDlgItemInt(IDC_DHAND, value.deal);
	SetDlgItemInt(IDC_PHAND, value.part);
	SetDlgItemInt(IDC_WHAND, value.won);
	//Convert float to CString for participate hand percent
	float pPart = ThP::Percent(value.part,value.deal);
	if(!value.deal && !value.part)
		pPart = 0;
	CString sPart; sPart.Format(_T("%.2f"),pPart);
	SetDlgItemText(IDC_PPHAND, sPart);
	//Convert float to CString for won hand percent
	float pWon = ThP::Percent(value.won,value.deal);
	if(!value.deal && !value.won)
		pWon = 0;
	CString sWon; sWon.Format(_T("%.2f"),pWon);
	SetDlgItemText(IDC_WPHAND, sWon);
	SetDlgItemInt(IDC_PTOUR, value.tPart);
	SetDlgItemInt(IDC_WTOUR, value.tWon);
	//Convert float to CString foe won tournament percent
	float pTWon = ThP::Percent(value.tWon,value.tPart);
	if(!value.tPart && !value.tWon)
		pTWon = 0;
	CString sTWon; sTWon.Format(_T("%.2f"),pTWon);
	SetDlgItemText(IDC_WPTOUR, sTWon);
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CThP_WindowDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CThP_WindowDlg::OnPaint()
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
HCURSOR CThP_WindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CThP_WindowDlg::OnBnClickedCout()
{
	//Percent for number of out after flop/turn, pot odds
	float percent = 0;
	int out = GetDlgItemInt(IDC_OUT);
	int bet = GetDlgItemInt(IDC_BET);
	int pot = GetDlgItemInt(IDC_POT);
	CButton* flop = (CButton*) GetDlgItem(IDC_FLOP);
	CButton* turn = (CButton*) GetDlgItem(IDC_TURN);
	//Hand after flop percent
	if(flop->GetCheck())
		percent = ThP::Flop(out);
	//Hand after turn percent
	else if(turn->GetCheck())
		percent = ThP::Turn(out);
	//Calculating pot odds
	float hPercent = 100 / percent;
	float odds = float(pot) / float(bet);
	//Convert float to Cstring 
	CString sPercent; sPercent.Format(_T("%.2f"),percent);
	SetDlgItemText(IDC_POUT, sPercent);
	if (percent == 0) hPercent = 0;
	CString sHPercent; sHPercent.Format(_T("%.1f"),hPercent);
	SetDlgItemText(IDC_HPERC, sHPercent);
	if (bet == 0) odds = 0;
	CString sOdds; sOdds.Format(_T("%.1f"),odds);
	SetDlgItemText(IDC_POTBET, sOdds);
}


void CThP_WindowDlg::OnBnClickedCprize()
{
	//Calculate tournament payouts
	int players = GetDlgItemInt(IDC_PLAYERS);
	int money = GetDlgItemInt(IDC_MONEY);
	//Calculate total prize
	int prize = players * money;
	SetDlgItemInt(IDC_PRIZE, prize);
	//Calculate prizes for every place
	SetDlgItemInt(IDC_PLACE1, ThP::Place1(players, money));
	SetDlgItemInt(IDC_PLACE2, ThP::Place2(players, money));
	SetDlgItemInt(IDC_PLACE3, ThP::Place3(players, money));
	SetDlgItemInt(IDC_PLACE4, ThP::Place4(players, money));
	SetDlgItemInt(IDC_PLACE5, ThP::Place5(players, money));
	SetDlgItemInt(IDC_PLACE6, ThP::Place6(players, money));
	SetDlgItemInt(IDC_PLACE7, ThP::Place7(players, money));
	SetDlgItemInt(IDC_PLACE8, ThP::Place8(players, money));
	SetDlgItemInt(IDC_PLACE9, ThP::Place9(players, money));
}


void CThP_WindowDlg::OnBnClickedDplus()
{
	// Plus 1 for Deal
	int number = GetDlgItemInt(IDC_DNUMBER);
	++number;
	SetDlgItemInt(IDC_DNUMBER, number);
}


void CThP_WindowDlg::OnBnClickedPplus()
{
	// Plus 1 for Participate
	int number = GetDlgItemInt(IDC_PNUMBER);
	++number;
	SetDlgItemInt(IDC_PNUMBER, number);
}


void CThP_WindowDlg::OnBnClickedWplus()
{
	// Plus 1 for Won
	int number = GetDlgItemInt(IDC_WNUMBER);
	++number;
	SetDlgItemInt(IDC_WNUMBER, number);
}


void CThP_WindowDlg::OnBnClickedDminus()
{
	// Minus 1 for Deal
	int number = GetDlgItemInt(IDC_DNUMBER);
	--number;
	SetDlgItemInt(IDC_DNUMBER, number);
}


void CThP_WindowDlg::OnBnClickedPminus()
{
	// Minus 1 for Participate
	int number = GetDlgItemInt(IDC_PNUMBER);
	--number;
	SetDlgItemInt(IDC_PNUMBER, number);
}


void CThP_WindowDlg::OnBnClickedWminus()
{
	// Minus 1 for Won
	int number = GetDlgItemInt(IDC_WNUMBER);
	-- number;
	SetDlgItemInt(IDC_WNUMBER, number);
}


void CThP_WindowDlg::OnBnClickedReset()
{
	//Set edit box on 0 and check box uncheck
	SetDlgItemInt(IDC_DNUMBER, 0);
	SetDlgItemInt(IDC_PNUMBER, 0);
	SetDlgItemInt(IDC_WNUMBER, 0);
	CButton * cWon = (CButton*) GetDlgItem(IDC_CWON);
	cWon->SetCheck(0);
}


void CThP_WindowDlg::OnBnClickedAdd()
{
	//Add values from edit box to file
	int deal = GetDlgItemInt(IDC_DNUMBER);
	int part = GetDlgItemInt(IDC_PNUMBER);
	int won = GetDlgItemInt(IDC_WNUMBER);
	CButton * cbWon = (CButton*) GetDlgItem(IDC_CWON);
	bool cWon = cbWon->GetCheck() == BST_CHECKED;
	ThP::AddToFile(deal,part,won,cWon);
	//Add values from file to edit box
	struct ThP::ReadValues value = ThP::ReadFromFile();
	SetDlgItemInt(IDC_DHAND, value.deal);
	SetDlgItemInt(IDC_PHAND, value.part);
	SetDlgItemInt(IDC_WHAND, value.won);
	//Convert float to CString for participate hand percent
	float pPart = ThP::Percent(value.part,value.deal);
	CString sPart; sPart.Format(_T("%.2f"),pPart);
	SetDlgItemText(IDC_PPHAND, sPart);
	//Convert float to CString for won hand percent
	float pWon = ThP::Percent(value.won,value.deal);
	CString sWon; sWon.Format(_T("%.2f"),pWon);
	SetDlgItemText(IDC_WPHAND, sWon);
	SetDlgItemInt(IDC_PTOUR, value.tPart);
	SetDlgItemInt(IDC_WTOUR, value.tWon);
	//Convert float to CString foe won tournament percent
	float pTWon = ThP::Percent(value.tWon,value.tPart);
	CString sTWon; sTWon.Format(_T("%.2f"),pTWon);
	SetDlgItemText(IDC_WPTOUR, sTWon);
}


void CThP_WindowDlg::OnBnClickedAbout()
{
	//Open about dialog
	CAboutDlg dlg;
	dlg.DoModal();
}


void CThP_WindowDlg::OnBnClickedResetstat()
{
	//Set all values in file on 0
	ThP::ResetFile();
	//Add values from file to edit box
	struct ThP::ReadValues value = ThP::ReadFromFile();
	SetDlgItemInt(IDC_DHAND, value.deal);
	SetDlgItemInt(IDC_PHAND, value.part);
	SetDlgItemInt(IDC_WHAND, value.won);
	SetDlgItemInt(IDC_PPHAND, 0);
	SetDlgItemInt(IDC_WPHAND, 0);
	SetDlgItemInt(IDC_PTOUR, value.tPart);
	SetDlgItemInt(IDC_WTOUR, value.tWon);
	SetDlgItemInt(IDC_WPTOUR, 0);
}
