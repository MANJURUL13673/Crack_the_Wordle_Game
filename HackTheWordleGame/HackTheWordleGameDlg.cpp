
// HackTheWordleGameDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "HackTheWordleGame.h"
#include "HackTheWordleGameDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CHackTheWordleGameDlg dialog



CHackTheWordleGameDlg::CHackTheWordleGameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HACKTHEWORDLEGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_PressButtonWord0 = 0;
	m_PressButtonWord1 = 0;
	m_PressButtonWord2 = 0;
	m_PressButtonWord3 = 0;
	m_PressButtonWord4 = 0;
	memset(falseCharacter, false, sizeof(falseCharacter));
	memset(confusedCharacter, false, sizeof(confusedCharacter));
	for (int i = 0; i < 5; i++)
	{
		correctCharacter[i] = '?';
	}
}

void CHackTheWordleGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_Word00);
	DDX_Control(pDX, IDC_BUTTON2, m_Word01);
	DDX_Control(pDX, IDC_BUTTON3, m_Word02);
	DDX_Control(pDX, IDC_BUTTON4, m_Word03);
	DDX_Control(pDX, IDC_BUTTON5, m_Word04);
	DDX_Control(pDX, IDC_BUTTON6, m_Word10);
	DDX_Control(pDX, IDC_BUTTON7, m_Word11);
	DDX_Control(pDX, IDC_BUTTON8, m_Word12);
	DDX_Control(pDX, IDC_BUTTON9, m_Word13);
	DDX_Control(pDX, IDC_BUTTON10, m_Word14);
	DDX_Control(pDX, IDC_BUTTON11, m_Word20);
	DDX_Control(pDX, IDC_BUTTON12, m_Word21);
	DDX_Control(pDX, IDC_BUTTON13, m_Word22);
	DDX_Control(pDX, IDC_BUTTON14, m_Word23);
	DDX_Control(pDX, IDC_BUTTON15, m_Word24);
	DDX_Control(pDX, IDC_BUTTON16, m_Word30);
	DDX_Control(pDX, IDC_BUTTON17, m_Word31);
	DDX_Control(pDX, IDC_BUTTON18, m_Word32);
	DDX_Control(pDX, IDC_BUTTON19, m_Word33);
	DDX_Control(pDX, IDC_BUTTON20, m_Word34);
	DDX_Control(pDX, IDC_BUTTON21, m_Word40);
	DDX_Control(pDX, IDC_BUTTON22, m_Word41);
	DDX_Control(pDX, IDC_BUTTON23, m_Word42);
	DDX_Control(pDX, IDC_BUTTON24, m_Word43);
	DDX_Control(pDX, IDC_BUTTON25, m_Word44);
	DDX_Control(pDX, IDC_BUTTON27, m_Word50);
	DDX_Control(pDX, IDC_BUTTON28, m_Word51);
	DDX_Control(pDX, IDC_BUTTON29, m_Word52);
	DDX_Control(pDX, IDC_BUTTON30, m_Word53);
	DDX_Control(pDX, IDC_BUTTON31, m_Word54);

}

BEGIN_MESSAGE_MAP(CHackTheWordleGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CHackTheWordleGameDlg::OnBnClickedWord00)
	ON_BN_CLICKED(IDC_BUTTON2, &CHackTheWordleGameDlg::OnBnClickedWord01)
	ON_BN_CLICKED(IDC_BUTTON3, &CHackTheWordleGameDlg::OnBnClickedWord02)
	ON_BN_CLICKED(IDC_BUTTON4, &CHackTheWordleGameDlg::OnBnClickedWord03)
	ON_BN_CLICKED(IDC_BUTTON5, &CHackTheWordleGameDlg::OnBnClickedWord04)
	ON_BN_CLICKED(IDC_BUTTON6, &CHackTheWordleGameDlg::OnBnClickedWord10)
	ON_BN_CLICKED(IDC_BUTTON7, &CHackTheWordleGameDlg::OnBnClickedWord11)
	ON_BN_CLICKED(IDC_BUTTON8, &CHackTheWordleGameDlg::OnBnClickedWord12)
	ON_BN_CLICKED(IDC_BUTTON9, &CHackTheWordleGameDlg::OnBnClickedWord13)
	ON_BN_CLICKED(IDC_BUTTON10, &CHackTheWordleGameDlg::OnBnClickedWord14)
	ON_BN_CLICKED(IDC_BUTTON11, &CHackTheWordleGameDlg::OnBnClickedWord20)
	ON_BN_CLICKED(IDC_BUTTON12, &CHackTheWordleGameDlg::OnBnClickedWord21)
	ON_BN_CLICKED(IDC_BUTTON13, &CHackTheWordleGameDlg::OnBnClickedWord22)
	ON_BN_CLICKED(IDC_BUTTON14, &CHackTheWordleGameDlg::OnBnClickedWord23)
	ON_BN_CLICKED(IDC_BUTTON15, &CHackTheWordleGameDlg::OnBnClickedWord24)
	ON_BN_CLICKED(IDC_BUTTON16, &CHackTheWordleGameDlg::OnBnClickedWord30)
	ON_BN_CLICKED(IDC_BUTTON17, &CHackTheWordleGameDlg::OnBnClickedWord31)
	ON_BN_CLICKED(IDC_BUTTON18, &CHackTheWordleGameDlg::OnBnClickedWord32)
	ON_BN_CLICKED(IDC_BUTTON19, &CHackTheWordleGameDlg::OnBnClickedWord33)
	ON_BN_CLICKED(IDC_BUTTON20, &CHackTheWordleGameDlg::OnBnClickedWord34)
	ON_BN_CLICKED(IDC_BUTTON21, &CHackTheWordleGameDlg::OnBnClickedWord40)
	ON_BN_CLICKED(IDC_BUTTON22, &CHackTheWordleGameDlg::OnBnClickedWord41)
	ON_BN_CLICKED(IDC_BUTTON23, &CHackTheWordleGameDlg::OnBnClickedWord42)
	ON_BN_CLICKED(IDC_BUTTON24, &CHackTheWordleGameDlg::OnBnClickedWord43)
	ON_BN_CLICKED(IDC_BUTTON25, &CHackTheWordleGameDlg::OnBnClickedWord44)
	ON_BN_CLICKED(IDC_BUTTON27, &CHackTheWordleGameDlg::OnBnClickedWord50)
	ON_BN_CLICKED(IDC_BUTTON28, &CHackTheWordleGameDlg::OnBnClickedWord51)
	ON_BN_CLICKED(IDC_BUTTON29, &CHackTheWordleGameDlg::OnBnClickedWord52)
	ON_BN_CLICKED(IDC_BUTTON30, &CHackTheWordleGameDlg::OnBnClickedWord53)
	ON_BN_CLICKED(IDC_BUTTON31, &CHackTheWordleGameDlg::OnBnClickedWord54)
	ON_BN_CLICKED(IDC_BUTTON26, &CHackTheWordleGameDlg::OnBnClickedButtonEnter)
END_MESSAGE_MAP()


// CHackTheWordleGameDlg message handlers

BOOL CHackTheWordleGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);

	// TODO: Add extra initialization here
	step = 0;
	CollectWords();
	SetWords();
	//wordControl00.CreateSol
	//GetDlgItem(IDC_BUTTON1)->SetWindowTextW(L"1");
	//m_Word00.EnableWindowsTheming(FALSE);
	//m_Word00.SetFaceColor(RGB(0, 255, 255), true);
	//m_Word00.EnableWindowsTheming(TRUE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHackTheWordleGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHackTheWordleGameDlg::OnPaint()
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
HCURSOR CHackTheWordleGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CHackTheWordleGameDlg::CollectWords()
{
	string word;
	ifstream myfile;
	myfile.open("../Dataset/WordDataset.txt");
	while (myfile >> word)
	{
		allWords.push(word);
		if (myfile.eof())
		{
			break;
		}
	}
	myfile.close();
}

void CHackTheWordleGameDlg::SetWords()
{
	if (step == 0)
	{
		word = allWords.top();
		allWords.pop();
		m_Word00.SetWindowText(CString(word[0]));
		m_Word01.SetWindowText(CString(word[1]));
		m_Word02.SetWindowText(CString(word[2]));
		m_Word03.SetWindowText(CString(word[3]));
		m_Word04.SetWindowText(CString(word[4]));
		m_Word10.SetWindowText("");
		m_Word11.SetWindowText("");
		m_Word12.SetWindowText("");
		m_Word13.SetWindowText("");
		m_Word14.SetWindowText("");
		m_Word20.SetWindowText("");
		m_Word21.SetWindowText("");
		m_Word22.SetWindowText("");
		m_Word23.SetWindowText("");
		m_Word24.SetWindowText("");
		m_Word30.SetWindowText("");
		m_Word31.SetWindowText("");
		m_Word32.SetWindowText("");
		m_Word33.SetWindowText("");
		m_Word34.SetWindowText("");
		m_Word40.SetWindowText("");
		m_Word41.SetWindowText("");
		m_Word42.SetWindowText("");
		m_Word43.SetWindowText("");
		m_Word44.SetWindowText("");
		m_Word50.SetWindowText("");
		m_Word51.SetWindowText("");
		m_Word52.SetWindowText("");
		m_Word53.SetWindowText("");
		m_Word54.SetWindowText("");
		m_Word10.EnableWindow(FALSE);
		m_Word11.EnableWindow(FALSE);
		m_Word12.EnableWindow(FALSE);
		m_Word13.EnableWindow(FALSE);
		m_Word14.EnableWindow(FALSE);
		m_Word20.EnableWindow(FALSE);
		m_Word21.EnableWindow(FALSE);
		m_Word22.EnableWindow(FALSE);
		m_Word23.EnableWindow(FALSE);
		m_Word24.EnableWindow(FALSE);
		m_Word30.EnableWindow(FALSE);
		m_Word31.EnableWindow(FALSE);
		m_Word32.EnableWindow(FALSE);
		m_Word33.EnableWindow(FALSE);
		m_Word34.EnableWindow(FALSE);
		m_Word40.EnableWindow(FALSE);
		m_Word41.EnableWindow(FALSE);
		m_Word42.EnableWindow(FALSE);
		m_Word43.EnableWindow(FALSE);
		m_Word44.EnableWindow(FALSE);
		m_Word50.EnableWindow(FALSE);
		m_Word51.EnableWindow(FALSE);
		m_Word52.EnableWindow(FALSE);
		m_Word53.EnableWindow(FALSE);
		m_Word54.EnableWindow(FALSE);
	}
	else if (step == 1)
	{
		m_Word10.EnableWindow(TRUE);
		m_Word11.EnableWindow(TRUE);
		m_Word12.EnableWindow(TRUE);
		m_Word13.EnableWindow(TRUE);
		m_Word14.EnableWindow(TRUE);
		//word = GetGuessWord();
		word = allWords.top();
		allWords.pop();
		m_Word10.SetWindowText(CString(word[0]));
		m_Word11.SetWindowText(CString(word[1]));
		m_Word12.SetWindowText(CString(word[2]));
		m_Word13.SetWindowText(CString(word[3]));
		m_Word14.SetWindowText(CString(word[4]));
		m_Word00.EnableWindow(FALSE);
		m_Word01.EnableWindow(FALSE);
		m_Word02.EnableWindow(FALSE);
		m_Word03.EnableWindow(FALSE);
		m_Word04.EnableWindow(FALSE);
	}
	else if (step == 2)
	{
		m_Word20.EnableWindow(TRUE);
		m_Word21.EnableWindow(TRUE);
		m_Word22.EnableWindow(TRUE);
		m_Word23.EnableWindow(TRUE);
		m_Word24.EnableWindow(TRUE);
		//word = GetGuessWord();
		word = allWords.top();
		allWords.pop();
		m_Word20.SetWindowText(CString(word[0]));
		m_Word21.SetWindowText(CString(word[1]));
		m_Word22.SetWindowText(CString(word[2]));
		m_Word23.SetWindowText(CString(word[3]));
		m_Word24.SetWindowText(CString(word[4]));
		m_Word10.EnableWindow(FALSE);
		m_Word11.EnableWindow(FALSE);
		m_Word12.EnableWindow(FALSE);
		m_Word13.EnableWindow(FALSE);
		m_Word14.EnableWindow(FALSE);
	}
	else if (step == 3)
	{
		m_Word30.EnableWindow(TRUE);
		m_Word31.EnableWindow(TRUE);
		m_Word32.EnableWindow(TRUE);
		m_Word33.EnableWindow(TRUE);
		m_Word34.EnableWindow(TRUE);
		if (individualAcceptedCharacter.size() >= 3) 
		{
			word = GetGuessWord();
		}
		else
		{
			word = allWords.top();
			allWords.pop();
		}
		m_Word30.SetWindowText(CString(word[0]));
		m_Word31.SetWindowText(CString(word[1]));
		m_Word32.SetWindowText(CString(word[2]));
		m_Word33.SetWindowText(CString(word[3]));
		m_Word34.SetWindowText(CString(word[4]));
		m_Word20.EnableWindow(FALSE);
		m_Word21.EnableWindow(FALSE);
		m_Word22.EnableWindow(FALSE);
		m_Word23.EnableWindow(FALSE);
		m_Word24.EnableWindow(FALSE);
	}
	else if (step == 4)
	{
		m_Word40.EnableWindow(TRUE);
		m_Word41.EnableWindow(TRUE);
		m_Word42.EnableWindow(TRUE);
		m_Word43.EnableWindow(TRUE);
		m_Word44.EnableWindow(TRUE);
		word = GetGuessWord();
		m_Word40.SetWindowText(CString(word[0]));
		m_Word41.SetWindowText(CString(word[1]));
		m_Word42.SetWindowText(CString(word[2]));
		m_Word43.SetWindowText(CString(word[3]));
		m_Word44.SetWindowText(CString(word[4]));
		m_Word30.EnableWindow(FALSE);
		m_Word31.EnableWindow(FALSE);
		m_Word32.EnableWindow(FALSE);
		m_Word33.EnableWindow(FALSE);
		m_Word34.EnableWindow(FALSE);
	}
	else if(step == 5)
	{
		m_Word50.EnableWindow(TRUE);
		m_Word51.EnableWindow(TRUE);
		m_Word52.EnableWindow(TRUE);
		m_Word53.EnableWindow(TRUE);
		m_Word54.EnableWindow(TRUE);
		word = GetGuessWord();
		m_Word50.SetWindowText(CString(word[0]));
		m_Word51.SetWindowText(CString(word[1]));
		m_Word52.SetWindowText(CString(word[2]));
		m_Word53.SetWindowText(CString(word[3]));
		m_Word54.SetWindowText(CString(word[4]));
		m_Word40.EnableWindow(FALSE);
		m_Word41.EnableWindow(FALSE);
		m_Word42.EnableWindow(FALSE);
		m_Word43.EnableWindow(FALSE);
		m_Word44.EnableWindow(FALSE);
	}
	else
	{

	}
}

string CHackTheWordleGameDlg::GetGuessWord()
{
	string guessWord = "";
	bool falseWord;
	while (true)
	{
		guessWord = allWords.top();
		/*if (guessWord == "LIGHT")
		{
			TRACE("OK\n");
		}*/
		/*if (guessWord == "TIGHT")
		{
			TRACE("OK\n");
		}*/
		falseWord = false;
		for (int j = 0; j < 5; j++)
		{
			if ((correctCharacter[j] != '?' && correctCharacter[j] != guessWord[j]) || confusedCharacter[guessWord[j]][j] == true || falseCharacter[guessWord[j]] == true)
			{
				falseWord = true;
				break;
			}
		}
		if (falseWord)
		{
			allWords.pop();
		}
		else
		{
			set<char>::iterator it;
			bool allExist = true;
			for (it = confusedCharacterList.begin(); it != confusedCharacterList.end(); it++)
			{
				if (guessWord.find(*it) == string::npos)
				{
					allExist = false;
					break;
				}
			}
			if (allExist)
			{
				allWords.pop();
				return guessWord;
			}
			else
			{
				allWords.pop();
			}
		}
	}
	return guessWord = "";
}

void CHackTheWordleGameDlg::OnBnClickedWord00()
{
	// TODO: Add your control notification handler code here
	m_Word00.SetTextColor(RGB(255, 255, 255));
	if (m_PressButtonWord0 % 3 == 0)
	{
		m_Word00.EnableWindowsTheming(FALSE);
		m_Word00.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord0++;
	}
	else if (m_PressButtonWord0 % 3 == 1)
	{
		m_Word00.EnableWindowsTheming(FALSE);
		m_Word00.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord0++;
	}
	else if (m_PressButtonWord0 % 3 == 2)
	{
		m_Word00.EnableWindowsTheming(FALSE);
		m_Word00.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord0++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord01()
{
	// TODO: Add your control notification handler code here
	m_Word01.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord1 %= 3;
	if (m_PressButtonWord1 % 3 == 0)
	{
		m_Word01.EnableWindowsTheming(FALSE);
		m_Word01.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord1++;
	}
	else if (m_PressButtonWord1 % 3 == 1)
	{
		m_Word01.EnableWindowsTheming(FALSE);
		m_Word01.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord1++;
	}
	else if (m_PressButtonWord1 % 3 == 2)
	{
		m_Word01.EnableWindowsTheming(FALSE);
		m_Word01.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord1++;
	}
}




void CHackTheWordleGameDlg::OnBnClickedWord02()
{
	// TODO: Add your control notification handler code here
	m_Word02.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord2 %= 3;
	if (m_PressButtonWord2 % 3 == 0)
	{
		m_Word02.EnableWindowsTheming(FALSE);
		m_Word02.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord2++;
	}
	else if (m_PressButtonWord2 % 3 == 1)
	{
		m_Word02.EnableWindowsTheming(FALSE);
		m_Word02.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord2++;
	}
	else if (m_PressButtonWord2 % 3 == 2)
	{
		m_Word02.EnableWindowsTheming(FALSE);
		m_Word02.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord2++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord03()
{
	// TODO: Add your control notification handler code here
	m_Word03.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord3 %= 3;
	if (m_PressButtonWord3 % 3 == 0)
	{
		m_Word03.EnableWindowsTheming(FALSE);
		m_Word03.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord3++;
	}
	else if (m_PressButtonWord3 % 3 == 1)
	{
		m_Word03.EnableWindowsTheming(FALSE);
		m_Word03.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord3++;
	}
	else if (m_PressButtonWord3 % 3 == 2)
	{
		m_Word03.EnableWindowsTheming(FALSE);
		m_Word03.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord3++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord04()
{
	// TODO: Add your control notification handler code here
	m_Word04.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord4 %= 3;
	if (m_PressButtonWord4 == 0)
	{
		m_Word04.EnableWindowsTheming(FALSE);
		m_Word04.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord4++;
	}
	else if (m_PressButtonWord4 == 1)
	{
		m_Word04.EnableWindowsTheming(FALSE);
		m_Word04.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord4++;
	}
	else if (m_PressButtonWord4 == 2)
	{
		m_Word04.EnableWindowsTheming(FALSE);
		m_Word04.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord4++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord10()
{
	// TODO: Add your control notification handler code here
	m_Word10.SetTextColor(RGB(255, 255, 255));
	if (m_PressButtonWord0 % 3 == 0)
	{
		m_Word10.EnableWindowsTheming(FALSE);
		m_Word10.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord0++;
	}
	else if (m_PressButtonWord0 % 3 == 1)
	{
		m_Word10.EnableWindowsTheming(FALSE);
		m_Word10.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord0++;
	}
	else if (m_PressButtonWord0 % 3 == 2)
	{
		m_Word10.EnableWindowsTheming(FALSE);
		m_Word10.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord0++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord11()
{
	// TODO: Add your control notification handler code here
	m_Word11.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord1 %= 3;
	if (m_PressButtonWord1 % 3 == 0)
	{
		m_Word11.EnableWindowsTheming(FALSE);
		m_Word11.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord1++;
	}
	else if (m_PressButtonWord1 % 3 == 1)
	{
		m_Word11.EnableWindowsTheming(FALSE);
		m_Word11.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord1++;
	}
	else if (m_PressButtonWord1 % 3 == 2)
	{
		m_Word11.EnableWindowsTheming(FALSE);
		m_Word11.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord1++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord12()
{
	// TODO: Add your control notification handler code here
	m_Word12.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord2 %= 3;
	if (m_PressButtonWord2 % 3 == 0)
	{
		m_Word12.EnableWindowsTheming(FALSE);
		m_Word12.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord2++;
	}
	else if (m_PressButtonWord2 % 3 == 1)
	{
		m_Word12.EnableWindowsTheming(FALSE);
		m_Word12.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord2++;
	}
	else if (m_PressButtonWord2 % 3 == 2)
	{
		m_Word12.EnableWindowsTheming(FALSE);
		m_Word12.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord2++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord13()
{
	// TODO: Add your control notification handler code here
	m_Word13.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord3 %= 3;
	if (m_PressButtonWord3 % 3 == 0)
	{
		m_Word13.EnableWindowsTheming(FALSE);
		m_Word13.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord3++;
	}
	else if (m_PressButtonWord3 % 3 == 1)
	{
		m_Word13.EnableWindowsTheming(FALSE);
		m_Word13.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord3++;
	}
	else if (m_PressButtonWord3 % 3 == 2)
	{
		m_Word13.EnableWindowsTheming(FALSE);
		m_Word13.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord3++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord14()
{
	// TODO: Add your control notification handler code here
	m_Word14.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord4 %= 3;
	if (m_PressButtonWord4 == 0)
	{
		m_Word14.EnableWindowsTheming(FALSE);
		m_Word14.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord4++;
	}
	else if (m_PressButtonWord4 == 1)
	{
		m_Word14.EnableWindowsTheming(FALSE);
		m_Word14.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord4++;
	}
	else if (m_PressButtonWord4 == 2)
	{
		m_Word14.EnableWindowsTheming(FALSE);
		m_Word14.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord4++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord20()
{
	// TODO: Add your control notification handler code here
	m_Word20.SetTextColor(RGB(255, 255, 255));
	if (m_PressButtonWord0 % 3 == 0)
	{
		m_Word20.EnableWindowsTheming(FALSE);
		m_Word20.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord0++;
	}
	else if (m_PressButtonWord0 % 3 == 1)
	{
		m_Word20.EnableWindowsTheming(FALSE);
		m_Word20.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord0++;
	}
	else if (m_PressButtonWord0 % 3 == 2)
	{
		m_Word20.EnableWindowsTheming(FALSE);
		m_Word20.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord0++;
	}
}

void CHackTheWordleGameDlg::OnBnClickedWord21()
{
	// TODO: Add your control notification handler code here
	m_Word21.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord1 %= 3;
	if (m_PressButtonWord1 % 3 == 0)
	{
		m_Word21.EnableWindowsTheming(FALSE);
		m_Word21.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord1++;
	}
	else if (m_PressButtonWord1 % 3 == 1)
	{
		m_Word21.EnableWindowsTheming(FALSE);
		m_Word21.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord1++;
	}
	else if (m_PressButtonWord1 % 3 == 2)
	{
		m_Word21.EnableWindowsTheming(FALSE);
		m_Word21.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord1++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord22()
{
	// TODO: Add your control notification handler code here
	m_Word22.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord2 %= 3;
	if (m_PressButtonWord2 % 3 == 0)
	{
		m_Word22.EnableWindowsTheming(FALSE);
		m_Word22.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord2++;
	}
	else if (m_PressButtonWord2 % 3 == 1)
	{
		m_Word22.EnableWindowsTheming(FALSE);
		m_Word22.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord2++;
	}
	else if (m_PressButtonWord2 % 3 == 2)
	{
		m_Word22.EnableWindowsTheming(FALSE);
		m_Word22.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord2++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord23()
{
	// TODO: Add your control notification handler code here
	m_Word23.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord3 %= 3;
	if (m_PressButtonWord3 % 3 == 0)
	{
		m_Word23.EnableWindowsTheming(FALSE);
		m_Word23.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord3++;
	}
	else if (m_PressButtonWord3 % 3 == 1)
	{
		m_Word23.EnableWindowsTheming(FALSE);
		m_Word23.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord3++;
	}
	else if (m_PressButtonWord3 % 3 == 2)
	{
		m_Word23.EnableWindowsTheming(FALSE);
		m_Word23.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord3++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord24()
{
	// TODO: Add your control notification handler code here
	m_Word24.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord4 %= 3;
	if (m_PressButtonWord4 == 0)
	{
		m_Word24.EnableWindowsTheming(FALSE);
		m_Word24.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord4++;
	}
	else if (m_PressButtonWord4 == 1)
	{
		m_Word24.EnableWindowsTheming(FALSE);
		m_Word24.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord4++;
	}
	else if (m_PressButtonWord4 == 2)
	{
		m_Word24.EnableWindowsTheming(FALSE);
		m_Word24.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord4++;
	}
}

void CHackTheWordleGameDlg::OnBnClickedWord30()
{
	// TODO: Add your control notification handler code here
	m_Word30.SetTextColor(RGB(255, 255, 255));
	if (m_PressButtonWord0 % 3 == 0)
	{
		m_Word30.EnableWindowsTheming(FALSE);
		m_Word30.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord0++;
	}
	else if (m_PressButtonWord0 % 3 == 1)
	{
		m_Word30.EnableWindowsTheming(FALSE);
		m_Word30.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord0++;
	}
	else if (m_PressButtonWord0 % 3 == 2)
	{
		m_Word30.EnableWindowsTheming(FALSE);
		m_Word30.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord0++;
	}
}

void CHackTheWordleGameDlg::OnBnClickedWord31()
{
	// TODO: Add your control notification handler code here
	m_Word31.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord1 %= 3;
	if (m_PressButtonWord1 % 3 == 0)
	{
		m_Word31.EnableWindowsTheming(FALSE);
		m_Word31.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord1++;
	}
	else if (m_PressButtonWord1 % 3 == 1)
	{
		m_Word31.EnableWindowsTheming(FALSE);
		m_Word31.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord1++;
	}
	else if (m_PressButtonWord1 % 3 == 2)
	{
		m_Word31.EnableWindowsTheming(FALSE);
		m_Word31.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord1++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord32()
{
	// TODO: Add your control notification handler code here
	m_Word32.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord2 %= 3;
	if (m_PressButtonWord2 % 3 == 0)
	{
		m_Word32.EnableWindowsTheming(FALSE);
		m_Word32.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord2++;
	}
	else if (m_PressButtonWord2 % 3 == 1)
	{
		m_Word32.EnableWindowsTheming(FALSE);
		m_Word32.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord2++;
	}
	else if (m_PressButtonWord2 % 3 == 2)
	{
		m_Word32.EnableWindowsTheming(FALSE);
		m_Word32.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord2++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord33()
{
	// TODO: Add your control notification handler code here
	m_Word33.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord3 %= 3;
	if (m_PressButtonWord3 % 3 == 0)
	{
		m_Word33.EnableWindowsTheming(FALSE);
		m_Word33.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord3++;
	}
	else if (m_PressButtonWord3 % 3 == 1)
	{
		m_Word33.EnableWindowsTheming(FALSE);
		m_Word33.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord3++;
	}
	else if (m_PressButtonWord3 % 3 == 2)
	{
		m_Word33.EnableWindowsTheming(FALSE);
		m_Word33.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord3++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord34()
{
	// TODO: Add your control notification handler code here
	m_Word34.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord4 %= 3;
	if (m_PressButtonWord4 == 0)
	{
		m_Word34.EnableWindowsTheming(FALSE);
		m_Word34.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord4++;
	}
	else if (m_PressButtonWord4 == 1)
	{
		m_Word34.EnableWindowsTheming(FALSE);
		m_Word34.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord4++;
	}
	else if (m_PressButtonWord4 == 2)
	{
		m_Word34.EnableWindowsTheming(FALSE);
		m_Word34.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord4++;
	}
}

void CHackTheWordleGameDlg::OnBnClickedWord40()
{
	// TODO: Add your control notification handler code here
	m_Word40.SetTextColor(RGB(255, 255, 255));
	if (m_PressButtonWord0 % 3 == 0)
	{
		m_Word40.EnableWindowsTheming(FALSE);
		m_Word40.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord0++;
	}
	else if (m_PressButtonWord0 % 3 == 1)
	{
		m_Word40.EnableWindowsTheming(FALSE);
		m_Word40.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord0++;
	}
	else if (m_PressButtonWord0 % 3 == 2)
	{
		m_Word40.EnableWindowsTheming(FALSE);
		m_Word40.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord0++;
	}
}

void CHackTheWordleGameDlg::OnBnClickedWord41()
{
	// TODO: Add your control notification handler code here
	m_Word41.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord1 %= 3;
	if (m_PressButtonWord1 % 3 == 0)
	{
		m_Word41.EnableWindowsTheming(FALSE);
		m_Word41.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord1++;
	}
	else if (m_PressButtonWord1 % 3 == 1)
	{
		m_Word41.EnableWindowsTheming(FALSE);
		m_Word41.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord1++;
	}
	else if (m_PressButtonWord1 % 3 == 2)
	{
		m_Word41.EnableWindowsTheming(FALSE);
		m_Word41.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord1++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord42()
{
	// TODO: Add your control notification handler code here
	m_Word42.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord2 %= 3;
	if (m_PressButtonWord2 % 3 == 0)
	{
		m_Word42.EnableWindowsTheming(FALSE);
		m_Word42.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord2++;
	}
	else if (m_PressButtonWord2 % 3 == 1)
	{
		m_Word42.EnableWindowsTheming(FALSE);
		m_Word42.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord2++;
	}
	else if (m_PressButtonWord2 % 3 == 2)
	{
		m_Word42.EnableWindowsTheming(FALSE);
		m_Word42.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord2++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord43()
{
	// TODO: Add your control notification handler code here
	m_Word43.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord3 %= 3;
	if (m_PressButtonWord3 % 3 == 0)
	{
		m_Word43.EnableWindowsTheming(FALSE);
		m_Word43.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord3++;
	}
	else if (m_PressButtonWord3 % 3 == 1)
	{
		m_Word43.EnableWindowsTheming(FALSE);
		m_Word43.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord3++;
	}
	else if (m_PressButtonWord3 % 3 == 2)
	{
		m_Word43.EnableWindowsTheming(FALSE);
		m_Word43.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord3++;
	}
}


void CHackTheWordleGameDlg::OnBnClickedWord44()
{
	// TODO: Add your control notification handler code here
	m_Word44.SetTextColor(RGB(255, 255, 255));
	//m_PressButtonWord4 %= 3;
	if (m_PressButtonWord4 == 0)
	{
		m_Word44.EnableWindowsTheming(FALSE);
		m_Word44.SetFaceColor(RGB(59, 57, 53), true);
		m_PressButtonWord4++;
	}
	else if (m_PressButtonWord4 == 1)
	{
		m_Word44.EnableWindowsTheming(FALSE);
		m_Word44.SetFaceColor(RGB(199, 154, 30), true);
		m_PressButtonWord4++;
	}
	else if (m_PressButtonWord4 == 2)
	{
		m_Word44.EnableWindowsTheming(FALSE);
		m_Word44.SetFaceColor(RGB(55, 199, 30), true);
		m_PressButtonWord4++;
	}
}

void CHackTheWordleGameDlg::OnBnClickedWord50()
{
	// TODO: Add your control notification handler code here
}

void CHackTheWordleGameDlg::OnBnClickedWord51()
{
	// TODO: Add your control notification handler code here
}


void CHackTheWordleGameDlg::OnBnClickedWord52()
{
	// TODO: Add your control notification handler code here
}


void CHackTheWordleGameDlg::OnBnClickedWord53()
{
	// TODO: Add your control notification handler code here
}


void CHackTheWordleGameDlg::OnBnClickedWord54()
{
	// TODO: Add your control notification handler code here
}

void CHackTheWordleGameDlg::OnBnClickedButtonEnter()
{
	// TODO: Add your control notification handler code here
	if (m_PressButtonWord0 != 0 && m_PressButtonWord1 != 0 && m_PressButtonWord2 != 0 && m_PressButtonWord3 != 0 && m_PressButtonWord4 != 0)
	{
		bool charNotValid[5];
		memset(charNotValid, true, sizeof(charNotValid));
		for (int i = 0; i < word.length(); i++)
		{
			if (i != 0 && word[i] == word[0] && (m_PressButtonWord0 % 3 == 2 || m_PressButtonWord0 % 3 == 0))
			{
				charNotValid[i] = false;
			}
			if (i != 1 && word[i] == word[1] && (m_PressButtonWord1 % 3 == 2 || m_PressButtonWord1 % 3 == 0))
			{
				charNotValid[i] = false;
			}
			if (i != 2 && word[i] == word[2] && (m_PressButtonWord2 % 3 == 2 || m_PressButtonWord2 % 3 == 0))
			{
				charNotValid[i] = false;
			}
			if (i != 3 && word[i] == word[3] && (m_PressButtonWord3 % 3 == 2 || m_PressButtonWord3 % 3 == 0))
			{
				charNotValid[i] = false;
			}
			if (i != 4 && word[i] == word[4] && (m_PressButtonWord4 % 3 == 2 || m_PressButtonWord4 % 3 == 0))
			{
				charNotValid[i] = false;
			}
		}
		if (m_PressButtonWord0 % 3 == 1)
		{
			falseCharacter[word[0]] = charNotValid[0];
		}
		else if (m_PressButtonWord0 % 3 == 2)
		{
			confusedCharacter[word[0]][0] = true;
			confusedCharacterList.insert(word[0]);
			individualAcceptedCharacter.insert(word[0]);
		}
		else 
		{
			correctCharacter[0] = word[0];
			individualAcceptedCharacter.insert(word[0]);
		}
		if (m_PressButtonWord1 % 3 == 1)
		{
			falseCharacter[word[1]] = charNotValid[1];
		}
		else if (m_PressButtonWord1 % 3 == 2)
		{
			confusedCharacter[word[1]][1] = true;
			confusedCharacterList.insert(word[1]);
			individualAcceptedCharacter.insert(word[1]);
		}
		else
		{
			correctCharacter[1] = word[1];
			individualAcceptedCharacter.insert(word[1]);
		}
		if (m_PressButtonWord2 % 3 == 1)
		{
			falseCharacter[word[2]] = charNotValid[2];
		}
		else if (m_PressButtonWord2 % 3 == 2)
		{
			confusedCharacter[word[2]][2] = true;
			confusedCharacterList.insert(word[2]);
			individualAcceptedCharacter.insert(word[2]);
		}
		else
		{
			correctCharacter[2] = word[2];
			individualAcceptedCharacter.insert(word[2]);
		}
		if (m_PressButtonWord3 % 3 == 1)
		{
			falseCharacter[word[3]] = charNotValid[3];
		}
		else if (m_PressButtonWord3 % 3 == 2)
		{
			confusedCharacter[word[3]][3] = true;
			confusedCharacterList.insert(word[3]);
			individualAcceptedCharacter.insert(word[3]);
		}
		else
		{
			correctCharacter[3] = word[3];
			individualAcceptedCharacter.insert(word[3]);
		}
		if (m_PressButtonWord4 % 4 == 1)
		{
			falseCharacter[word[4]] = charNotValid[4];
		}
		else if (m_PressButtonWord4 % 4 == 2)
		{
			confusedCharacter[word[4]][4] = true;
			confusedCharacterList.insert(word[4]);
			individualAcceptedCharacter.insert(word[4]);
		}
		else
		{
			correctCharacter[4] = word[4];
			individualAcceptedCharacter.insert(word[4]);
		}
		m_PressButtonWord0 = 0;
		m_PressButtonWord1 = 0;
		m_PressButtonWord2 = 0;
		m_PressButtonWord3 = 0;
		m_PressButtonWord4 = 0;
		step++;
		SetWords();
	}
}

bool CHackTheWordleGameDlg::NotValid(char c)
{
	for (int i = 0; i < 5; i++)
	{
		if (correctCharacter[i] == c)
		{
			return false;
		}
		if (confusedCharacter[c][i] == true)
		{
			return false;
		}
	}
	return true;
}
