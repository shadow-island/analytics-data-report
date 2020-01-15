// uudoinView.h : interface of the _UudoinView class
//
/////////////////////////////////////////////////////////////////////////////
// uudoinView.cpp : implementation of the _UudoinView class



#if !defined(AFX_UUDOINVIEW_H__BDBE8E26_948F_4C0D_843E_511BDD2F2007__INCLUDED_)
#define AFX_UUDOINVIEW_H__BDBE8E26_948F_4C0D_843E_511BDD2F2007__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//
#include "webbrowser2.h"
//
#include <string> //DEBUG_NEW�տ� �־����

//	Il1i0Oo
//	ABCDEFG
//	Consolars

// ! 1.1 //-> coloring, vs �ٹ̱� assist?->�۲ú��� 
// ~ 1.2. source ���� ?
// ~ 1.3. temp ����

// 2. coding 
/*
6.12	����,��������,Ÿ�̸�,������ �����ϱ�,�ð�����ǥ�� �ʿ�,
6/14	�ð��� �������� ǥ��,�켱 y�������� ����ó��, �ð��� �ʷ� ����,e�����߰�,�ڵ��α���,�����ڵ�
		���ø��, cinero �и�,��Ȯ�� �ð�, buffer�α�, max���� ǥ��,box �ڵ�(���� ���� �ڵ�)

6/15	random����,30���� monitor���, test����϶� ������,auto manual���� ǥ��,
6/16	cinero time,New VIDEO Ȯ��,buff���� ����, ���ø��� cursor����, auto��.
6/17	cusor�� �ݴ�� �����⿡�� (�ֱٺ��� ����ǰ�),manual����϶��� ero��ŵ
6/18	 �ѽð� ��� ���(���� ����),��հ�,�� ����� ǥ��,auto/,manual�ǽð� �ݿ�
6/19~21	 ��ü����,run_mode -> ini ȭ, cinero��ư, non_cinero_ratio  ����̷�,
6/22~24	 schedual �ٽ� ����,timer restart schedual title, y_video 0���ͽ����ϱ� (��ü�ѹ������˼��հ�)
6/25~27 ero? Ȯ�������ƴ� ī��Ʈ�� buff���� ���̰�,new video tilteȭ, TEST_MODE runmode ����,�ѽð� 
6/28~29	manual�� ero���� ,�ð� �д����� ������ ;�Ŵ����� �ô� my�� .

�Ŵ����϶��� ��ü Ÿ�̸� ����?
  ������ �ٽ� �ѱ� ?
4++ //GetFileAttributes();mfc ���� �ڼ��� �Ӽ� ���� ����
  �������� ������ Ư��(Attribute) ���� ������, ���Ͻð� ���� .
*tv���߰���  //�ٸ���� ���� �߰�?->  �������°� ���߰���. ->������ �뷡 �߰� ?.



video fileȭ -> ���α׷� �ٲܽ� ���� ���� �÷���?->���ο� ���� �߰��Ǹ� Ȯ�� = ���� 
������ �Ի� �� 
�ϴ� �� page ������? search�ϱ� 
? asx�� Ǭ��? //���ڸ��� female������ �и��ϱ� ~�ϴ� ��հ� (���� �ǰ� ��� 20������)
		-> ª�� ���� �ι�����? Ư����������? code�ʿ� 
? y mode E mode ǥ��??  file��� �ٲ�� �� �˾ƺ���,UI��.-> 
id�ΰ��� ����?
std�� ���� ~ 2005����-> local���� �����? c#����? -> 
//�Լ�ȭ�� 7�� �̻��϶�~
*/

enum
{
	CH_MAX = 136,
};

struct struct_video
{
	char	title[CH_MAX];
	char	time[CH_MAX];
	char	url[CH_MAX];				
};

class _UudoinView : public CView
{
public:
	bool	m_bRoseMode;

private:	
	enum
	{
		//vectorȭ?
		N_VIDEO_MAX		= 176,
		Y_VIDEO_MAX		= 60,
		E_VIDEO_MAX		= 52,	

		TIMER_PROGRESS	= 10,
		TIMER_READY,
		TIMER_END,
		TIMER_ROSE,
	};

	//
	ocx_WebBrowser2 m_ocx_ie;
	//
	
	bool		m_b_run_mode;
	bool		m_b_play_mode;
	bool		m_b_auto_mode;
	bool		m_b_new_video;

	CString		m_cs_shuffles;
	CString		m_window_text;
	CString		m_history;
	
	CTime		m_total_start_time;
	CTime		m_this_start_time;
	int			m_video_sec;


	CString			_exe_path(CString str);
	void			_do_video_num(int n, int max, CString);
	struct_video	_video(int,int n);

protected: // create from serialization only
	_UudoinView();
	DECLARE_DYNCREATE(_UudoinView)

	afx_msg void OnBUTTON_Next(bool);
	afx_msg void OnDocumentCompleteExplorer2(LPDISPATCH pDisp, VARIANT FAR* URL);

// Attributes
public:
	_UudoinDoc* GetDocument();



	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_UudoinView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();	
	protected:		
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void _go(CString str);
	virtual ~_UudoinView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(_UudoinView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void button_Start();
	afx_msg void button_Auto();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void _OnBUTTON_run();
	afx_msg void OnBUTTON_JS();
	afx_msg void button_End();
	afx_msg void OnBUTTON_History();
	afx_msg void button_GetRose();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString fromINI(CString param);

};

#ifndef _DEBUG  // debug version in uudoinView.cpp
inline _UudoinDoc* _UudoinView::GetDocument()
   { return (_UudoinDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UUDOINVIEW_H__BDBE8E26_948F_4C0D_843E_511BDD2F2007__INCLUDED_)
