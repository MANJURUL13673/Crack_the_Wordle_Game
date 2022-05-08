
// HackTheWordleGameDlg.h : header file
//
#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;


// CHackTheWordleGameDlg dialog
class CHackTheWordleGameDlg : public CDialogEx
{
// Construction
public:
	CHackTheWordleGameDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HACKTHEWORDLEGAME_DIALOG };
#endif

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
	int step;
	bool falseCharacter[130];
	bool confusedCharacter[130][5];
	char correctCharacter[5];
	string word;
	stack<string>allWords;
	set<char>confusedCharacterList;
	set<char>individualAcceptedCharacter;
	void CollectWords();
	void SetWords();
	string GetGuessWord();
	bool NotValid(char c);
	CMFCButton m_Word00;
	int m_PressButtonWord0;
	CMFCButton m_Word01;
	int m_PressButtonWord1;
	CMFCButton m_Word02;
	int m_PressButtonWord2;
	CMFCButton m_Word03;
	int m_PressButtonWord3;
	CMFCButton m_Word04;
	int m_PressButtonWord4;
	CMFCButton m_Word10;
	CMFCButton m_Word11;
	CMFCButton m_Word12;
	CMFCButton m_Word13;
	CMFCButton m_Word14;
	CMFCButton m_Word20;
	CMFCButton m_Word21;
	CMFCButton m_Word22;
	CMFCButton m_Word23;
	CMFCButton m_Word24;
	CMFCButton m_Word30;
	CMFCButton m_Word31;
	CMFCButton m_Word32;
	CMFCButton m_Word33;
	CMFCButton m_Word34;
	CMFCButton m_Word40;
	CMFCButton m_Word41;
	CMFCButton m_Word42;
	CMFCButton m_Word43;
	CMFCButton m_Word44;
	CMFCButton m_Word50;
	CMFCButton m_Word51;
	CMFCButton m_Word52;
	CMFCButton m_Word53;
	CMFCButton m_Word54;
	afx_msg void OnBnClickedWord00();
	afx_msg void OnBnClickedWord01();
	afx_msg void OnBnClickedWord02();
	afx_msg void OnBnClickedWord03();
	afx_msg void OnBnClickedWord04();
	afx_msg void OnBnClickedWord10();
	afx_msg void OnBnClickedWord11();
	afx_msg void OnBnClickedWord12();
	afx_msg void OnBnClickedWord13();
	afx_msg void OnBnClickedWord14();
	afx_msg void OnBnClickedWord20();
	afx_msg void OnBnClickedWord21();
	afx_msg void OnBnClickedWord22();
	afx_msg void OnBnClickedWord23();
	afx_msg void OnBnClickedWord24();
	afx_msg void OnBnClickedWord30();
	afx_msg void OnBnClickedWord31();
	afx_msg void OnBnClickedWord32();
	afx_msg void OnBnClickedWord33();
	afx_msg void OnBnClickedWord34();
	afx_msg void OnBnClickedWord40();
	afx_msg void OnBnClickedWord41();
	afx_msg void OnBnClickedWord42();
	afx_msg void OnBnClickedWord43();
	afx_msg void OnBnClickedWord44();
	afx_msg void OnBnClickedWord50();
	afx_msg void OnBnClickedWord51();
	afx_msg void OnBnClickedWord52();
	afx_msg void OnBnClickedWord53();
	afx_msg void OnBnClickedWord54();
	afx_msg void OnBnClickedButtonEnter();
};
