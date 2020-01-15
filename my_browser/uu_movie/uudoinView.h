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
#include <string> //DEBUG_NEW앞에 있어야함

//	Il1i0Oo
//	ABCDEFG
//	Consolars

// ! 1.1 //-> coloring, vs 꾸미기 assist?->글꼴변경 
// ~ 1.2. source 정리 ?
// ~ 1.3. temp 간단

// 2. coding 
/*
6.12	숫자,파일정보,타이머,실행모드 구분하기,시간진행표시 필요,
6/14	시간얼마 지났는지 표시,우선 y영상으로 파일처리, 시간제 초로 변경,e영상추가,자동로그인,완전자동
		선택모드, cinero 분리,정확한 시간, buffer두기, max값을 표시,box 자동(실지 완전 자동)

6/15	random구현,30초전 monitor모드, test모드일때 영상선택,auto manual상태 표시,
6/16	cinero time,New VIDEO 확률,buff값도 관리, 선택모드는 cursor없음, auto만.
6/17	cusor는 반대로 움지기에게 (최근부터 노출되게),manual모드일때는 ero스킵
6/18	 총시간 계산 기능(각종 정보),평균값,총 재생수 표시,auto/,manual실시간 반영
6/19~21	 전체섞기,run_mode -> ini 화, cinero버튼, non_cinero_ratio  재생이력,
6/22~24	 schedual 다시 보기,timer restart schedual title, y_video 0부터시작하기 (전체한번돈지알수잇게)
6/25~27 ero? 확률제가아닌 카운트제 buff숫자 보이게,new video tilte화, TEST_MODE runmode 통합,총시간 
6/28~29	manual시 ero빼기 ,시간 분단위로 나오게 ;매뉴얼모드 시는 my만 .

매뉴얼일때는 전체 타이머 멈춤?
  같은거 다시 켜기 ?
4++ //GetFileAttributes();mfc 파일 자세한 속성 비디오 길이
  윈도우즈 파일의 특성(Attribute) 정보 얻어오기, 파일시간 얻자 .
*tv다추가후  //다른사람 영상 추가?->  쓸데없는것 다추가후. ->동물원 노래 추가 ?.



video file화 -> 프로그램 바꿀시 기존 영상 플레이?->새로운 영상 추가되면 확률 = 높게 
동영상 게산 기 
일단 한 page 넘으면? search하기 
? asx다 푼후? //오자마자 female나가면 분리하기 ~일단 평균값 (추후 의견 고려 20분현재)
		-> 짧은 영상 두번실행? 특정영사한정? code필요 
? y mode E mode 표시??  file재생 바뀐거 좀 알아보게,UI상.-> 
id두가지 지원?
std로 구현 ~ 2005도전-> local버전 만들기? c#연습? -> 
//함수화는 7줄 이상일때~
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
		//vector화?
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
