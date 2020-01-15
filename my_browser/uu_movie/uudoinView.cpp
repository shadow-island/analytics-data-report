#include "stdafx.h"
#include "uudoin.h"

#include "uudoinDoc.h"
#include "uudoinView.h"


//code
#include "MainFrm.h"
#include <mshtml.h>
#include <atlconv.h>	// OLE2T용

//
enum
{
	ID_BROWSER	= 0,
	IE_MARGIN	= -2,
};


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _UudoinView

IMPLEMENT_DYNCREATE(_UudoinView, CView)

BEGIN_MESSAGE_MAP(_UudoinView, CView)
	//{{AFX_MSG_MAP(_UudoinView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_BUTTON_step, button_Start)	
	ON_COMMAND(ID_BUTTON_auto, button_Auto)
	ON_WM_TIMER()
	ON_COMMAND(ID_BUTTON_run, _OnBUTTON_run)
	ON_COMMAND(ID_BUTTON_js,	OnBUTTON_JS)
	ON_COMMAND(ID_BUTTON_End,	button_End)
	ON_COMMAND(ID_BUTTON_History, OnBUTTON_History)
	ON_COMMAND(ID_BUTTON_next, OnBUTTON_Next)
	ON_COMMAND(ID_BUTTON_GetRose, button_GetRose)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(_UudoinView, CView)
//{{AFX_EVENTSINK_MAP(dialog_web)
/* DocumentComplete */
ON_EVENT(_UudoinView, ID_BROWSER, 259 , OnDocumentCompleteExplorer2, VTS_DISPATCH VTS_PVARIANT)	
//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()


/////////////////////////////////////////////////////////////////////////////
// _UudoinView construction/destruction

_UudoinView::_UudoinView()
{
	// TODO: add construction code here

}

_UudoinView::~_UudoinView()
{
}

BOOL _UudoinView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// _UudoinView drawing

void _UudoinView::OnDraw(CDC* pDC)
{
	_UudoinDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

}

/////////////////////////////////////////////////////////////////////////////
// _UudoinView printing

BOOL _UudoinView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void _UudoinView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void _UudoinView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// _UudoinView diagnostics

#ifdef _DEBUG
void _UudoinView::AssertValid() const
{
	CView::AssertValid();
}

void _UudoinView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

_UudoinDoc* _UudoinView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(_UudoinDoc)));
	return (_UudoinDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// _UudoinView message handlers

int _UudoinView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here

	// 이게 OnInitialUpdate 안에 있으면 onsize시 에러 
	m_ocx_ie.Create("Browser", WS_VISIBLE, CRect(IE_MARGIN,IE_MARGIN,100,100), this, ID_BROWSER);		
	
	// ID는 BEGIN_EVENTSINK_MAP과 맞추기위한 것
	// IE_MARGIN = control이 view에 꽉차게	

	char ftemp[CH_MAX]={0,};
	GetPrivateProfileString(
		"HOME","run_mode","",ftemp,CH_MAX,_exe_path("uumovie.ini"));   
	if (atoi(ftemp) == 1)
		m_b_run_mode	= true;
	else
		m_b_run_mode	= false;

	m_b_auto_mode	= false;
	m_b_new_video	= false;

	srand( (unsigned)time( NULL ) );

	if (m_b_run_mode)
		button_Start();

	return 0;
}

void _UudoinView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if (nType != SIZE_MINIMIZED)
	{
		// Use the ActiveX Control methods, not
		// the CWnd versions (MoveWindow)
		try 
		{			
			//대충 스크롤 폭을 받은 것임 나중에 진짜로
			m_ocx_ie.SetWidth (cx + 20); 
			m_ocx_ie.SetHeight (cy + 18);
		} 
		catch (COleDispatchException* r)
		{
			CString str;
			str.Format ("Error <%d> in <%s>: <%s>", r->m_wCode, r->m_strSource, r->m_strDescription);
			::AfxMessageBox (str);
			r->Delete();
		} 
		catch (COleException* pE)
		{
			::AfxMessageBox ("IDispatch Error with Browser Control.\n");
			pE->Delete();
		}

		//안깜빡거리게
		m_ocx_ie.UpdateWindow();
	}
}

void _UudoinView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	/*
	SetScrollRange(SB_HORZ,0,1000,true);
	SetScrollRange(SB_VERT,0,768,true);	
	SetScrollPos(SB_VERT,0);
	SetScrollPos(SB_HORZ,0);
	*/
}

void _UudoinView::_go(CString str)
{
	m_ocx_ie.Navigate(str, NULL, NULL, NULL, NULL);
}


struct_video _UudoinView::_video(int type, int val_n)
{		
	struct_video y_video_new[N_VIDEO_MAX] = 		
	{
		{"dream_k_bed*",	"5:00",		"http://blox"},
		
	};


	struct_video y_video[Y_VIDEO_MAX] =
	{				
		//
		{"~P33.paipa",		"33:39","http://ubuntuone.com/07mTbJ68gVXCwB7aJTxxN"},	
					
		//위의 사이에 보충 해야함 
		
		
		//영상 여기서부터 넣기?
		//안되는거/시간체크 후 weebly/ y추가,e추가(readon),
		//다른 영상설명 수정요(게시판에 방송)자료도 고려,
		//개발1회 
		// g os om g ws wm?
		

		/*			
		
		*/
	};		



	static int shuffle_n[N_VIDEO_MAX];
	static int shuffle_y[Y_VIDEO_MAX];

	static bool is_fisrt = true;
	if (is_fisrt == true)
	{
		is_fisrt = false;
		//

		//
		for (int i = 0;i < N_VIDEO_MAX; i++)
			shuffle_n[i] = -1;					 
		for (i = 0;i < N_VIDEO_MAX; i++)
		{
			while(1)
			{
				int target = rand() % N_VIDEO_MAX;
				if (shuffle_n[target] == -1)
				{
					shuffle_n[target] = i;
					break;
				}
			}			
		}
		//
		for (i = 0;i < N_VIDEO_MAX; i++)
		{
			CString s;
			s.Format("%02d:%02d %s\n",i,shuffle_n[i],y_video_new[shuffle_n[i]].title);
			m_cs_shuffles += s;
		}

		MessageBox(m_cs_shuffles);
		m_cs_shuffles ="";

		//
		for (i = 0;i < Y_VIDEO_MAX; i++)
			shuffle_y[i] = -1;					 
		for (i = 0;i < Y_VIDEO_MAX; i++)
		{
			while(1)
			{
				int target = rand() % Y_VIDEO_MAX;
				if (shuffle_y[target] == -1)
				{
					shuffle_y[target] = i;
					break;
				}
			}			
		}
		//

		for (i = 0;i < Y_VIDEO_MAX; i++)
		{
			CString s;
			s.Format("%02d:%02d %s\n",i,shuffle_y[i],y_video[shuffle_y[i]].title);
			m_cs_shuffles += s;
		}
		
		
		MessageBox(m_cs_shuffles);
	}	

	if (0 == type)
	{
		return y_video_new[shuffle_n[val_n]];
	}
	else if (1 == type)
	{
		return y_video[shuffle_y[val_n]];
	}
	else
	{
		struct_video e_video_old[E_VIDEO_MAX] = 	
		{			
			{"kino-1",	"85:41",	"http://wadiv"},
			
			
			//아예 전체 올리고 시간은 나중에 수정? 짧은 영상의 경우 고려 가치?
		};

		char ftemp[CH_MAX]={0,};
		GetPrivateProfileString("HOME","cinero","",ftemp,CH_MAX,_exe_path("uumovie.ini"));   
		strcpy(e_video_old[val_n].time,ftemp);

		return e_video_old[val_n];
	}
}







void _UudoinView::button_Start() 
{
	//const CString id = "guest37270";
	const CString id = fromINI("login");
	//_go("http://www.geopia.com/?view=action&action=login&&userid=qweas4&passwd=wls117&rtnUrl=http%3A%2F%2Fchat.geopia.com%2F%3Fview%3Dindex%26mode%3Dlist%26cate1%3D%25BF%25AC%25B7%25C9%25BA%25B0%26cate2%3D40%25B4%25EB%25C0%25CC%25BB%25F3");	
	
	
	//pw도 입력받게? 
	_go("http://www.geopia.com/?view=action&action=login&userid=" + id + "&passwd=wls117&rtnUrl=http%3A%2F%2Fchat.geopia.com%2F%3Fview%3Dindex%26mode%3Dlist%26cate1%3D%25BF%25AC%25B7%25C9%25BA%25B0%26cate2%3D40%25B4%25EB%25C0%25CC%25BB%25F3");	
	//암호가 틀리면 여기서 안넘어감 

	std::string str;
	str = id;
	if (str.compare("qweas4") != 0)
		_video(1,1); //여기서 왜 처음 하는지 모르겠네 
}

void _UudoinView::button_Auto() 
{
	m_b_auto_mode = !m_b_auto_mode;

	if (m_b_auto_mode)	
		MessageBox("AUTO_MODE");	
	else	
		MessageBox("MANUAL_MODE");	
}




void _UudoinView::OnBUTTON_Next(bool b_play_or_end_mode = true)
{	
	static bool is_fisrt = true;
	if (is_fisrt == true)
	{
		is_fisrt = false;
		//
		m_total_start_time = CTime::GetCurrentTime();
	}

	int		video_n;
	CString	video_title;
	CString	video_time;
	CString	video_url;	
	//CString	cinero = "mms://182.161.120.180/cinero/vod/Cinero2";
	CString	cinero = "http://weebly.com/uploads/1/9/8/4/19848167/zoo_cinero.asx";
	
	//static bool is_y_mode = true;		
	static int	total = 1;	

	if (b_play_or_end_mode)
	{
		static int new_old = 0;
		new_old++;

		if (m_b_auto_mode == false)
			new_old = 0;	

		//이것도 ini화?
		if ((new_old % 4) != 0)
		{
			//int n = rand() % N_VIDEO_MAX ;

			static int n_my_video_index = 0;
			
			video_n		=	-(n_my_video_index);
			video_title	=	_video(0,n_my_video_index).title;
			video_time	=	_video(0,n_my_video_index).time;
			video_url	=	_video(0,n_my_video_index).url;			

			if (++n_my_video_index == N_VIDEO_MAX)
				n_my_video_index = 0;
		}			
		else
		{			
			static int y_video_count = 0;
			y_video_count++;

			// Y 영상, manual일때는 이것만 
			if (m_b_auto_mode == false || y_video_count % atoi(fromINI("e_video_ratio")) != 0) //1~
			{
				static int y_my_video_index = 0;
				
				video_n		= y_my_video_index;				
				video_title	= _video(1,video_n).title;
				video_time	= _video(1,video_n).time;
				video_url	= _video(1,video_n).url;

				if (++y_my_video_index == Y_VIDEO_MAX)
					y_my_video_index = 0;
			}				
			else
			{						
				//ETC 영상
				static int	e_video_count = 1;
				
				video_time = fromINI("cinero");	
				
				// ini화
				//non_cinero_ratio
				//MessageBox(fromINI("non_cinero_ratio"));
				////확률제가아닌 카운트제로?
				
				if (e_video_count++ % atoi(fromINI("non_etc_good_ratio")) != 0) //	Cinero
				{
					static int	etc_good_video_count = 0;
					//etc_good_video_count++;
					if ((etc_good_video_count % 2) == 1)
					{
						video_n		= -2;
						//안됨?
						//오전 12:18 2013-07-14
						video_title	= "WT Calendri*";
						video_time	= "01:10";
						video_url	= "http://www.lewebradio3.net/I%20CALENDARI%20WEBTV";		//062619		
					}
					else //	Cinero				
					{
						video_n		= Y_VIDEO_MAX + E_VIDEO_MAX;
						video_title	= "Cinero";
						video_url	= cinero;
					}		
				}
				else
				{	
					// 여기서 나가면 Cinero 올림 + kino추가?
					// video_n 구하기 
					video_n = atoi(fromINI("e_video"));	
					
					video_title	= _video(2,video_n).title;
					video_time	= _video(2,video_n).time;
					video_url	= _video(2,video_n).url;
					
					_do_video_num(video_n,E_VIDEO_MAX,"e_video");	
				}
			}					
		}								
	}
	else
	{
		char ftemp[CH_MAX]={0,};
		GetPrivateProfileString("HOME","cinero","",ftemp,CH_MAX,_exe_path("uumovie.ini"));   
		video_time = ftemp;

		video_n		= Y_VIDEO_MAX + E_VIDEO_MAX;
		video_title	= "film";
		video_url	= "http://weebly.com/uploads/1/9x";
	}


	////////////////////////////////////////////////////////////////////////// 
	// UI
	////////////////////////////////////////////////////////////////////////// 
	
	m_history = m_window_text;

	CString s_run;
	if (m_b_run_mode)
		s_run = "RUN";
	else
		s_run = "";

	m_window_text.Format("%d %s UUMovie (%d/N%dY%dE%d)%s",
		total,s_run,video_n,N_VIDEO_MAX,Y_VIDEO_MAX,E_VIDEO_MAX,video_title);

	CString s_auto;
	if (m_b_auto_mode)
		s_auto = "Auto";
	else
		s_auto = "Manual";

	CString s;
	s.Format("%s %s",s_auto,m_window_text);
	((_MainFrame*)AfxGetMainWnd())->SetWindowText(s);
	//

	////////////////////////////////////////////////////////////////////////// 
	// Action
	////////////////////////////////////////////////////////////////////////// 

		
	CStdioFile file_old;
	if ( !file_old.Open( _exe_path("temp_a.html"), CFile::modeRead) )
	{
		MessageBox("Error");
		return;
	}
		
	CFile file_write;	
	file_write.Open( _exe_path("go.html"), CFile::modeCreate | CFile::modeWrite );
	
	CString strLine;	
	while( file_old.ReadString( strLine ) )
	{			
		strLine.Replace("EK_URL",video_url);
		strLine += "\n";
		// 한줄씩 복사 
		file_write.Write(strLine, strLine.GetLength() );
	}
	
	file_old.Close();
	file_write.Close();
	
	m_b_play_mode = false;

	_go(_exe_path("go.html"));


	int min = atoi(video_time.Left(video_time.Find(":")));
	int sec = atoi(video_time.Right(video_time.GetLength() - video_time.Find(":") - 1));	

	m_video_sec = min*60 + sec; 

	char ftemp[CH_MAX]={0,};
	GetPrivateProfileString("HOME","new_video","",ftemp,CH_MAX,_exe_path("uumovie.ini"));   
	int new_video = atoi(ftemp);

	if (m_b_auto_mode && total >= new_video) // manual 모드신 안나오게
		m_b_new_video = true;
	
	total++;
}


void _UudoinView::_do_video_num(int n, int max,CString ini_ye_item)
{	
	/*
	if (ini_ye_item == "y_video")
	{
		if (n-- == 0)
			n = Y_VIDEO_MAX - 1;
	}
	else
		*/
	{
		//n값을 다 쓴후 제일 마지막 처리
		n++;	
		if (n >= max)
		n = 0; //첫숫자로
	}		

	CString s;		
	s.Format("%d",n);

	WritePrivateProfileString("HOME",ini_ye_item,s,_exe_path("uumovie.ini"));
}


void _UudoinView::OnDocumentCompleteExplorer2(LPDISPATCH pDisp, VARIANT FAR* URL) 
{
	//if (m_start_js == true)
	if (m_b_play_mode == false && m_b_auto_mode == true)
		OnBUTTON_JS();

	//m_start_js = false;
}

void _UudoinView::OnBUTTON_JS() 
{
	if (m_b_play_mode == false)
	{
		CString language = "JScript";
		CString function = "uu_submit()"; //괄호도 있어야함
		
		LPDISPATCH pDisp;
		pDisp = m_ocx_ie.GetDocument();				
		
		IHTMLDocument2* spDoc;
		pDisp->QueryInterface(IID_IHTMLDocument2, (LPVOID*)&spDoc);
		
		IHTMLWindow2* pWin;
		spDoc->get_parentWindow(&pWin);
		
		//////////////////////////////////////
		//자바 스크립트 실행
		BSTR Javascript = T2BSTR(language.GetBuffer(language.GetLength()));
		BSTR Function = T2BSTR(function.GetBuffer(function.GetLength()));
		VARIANT vVal;
		VariantInit(&vVal);
		pWin->execScript(Function,Javascript,&vVal);	
	}	
	else
		;	//MessageBox("Restarted!");

	/////
	SetTimer(TIMER_READY,(m_video_sec - 19)*1000,NULL );
	
	//buff 최소 4초는 걸리네;
	char ftemp[CH_MAX]={0,};
	GetPrivateProfileString("HOME","buffer","",ftemp,CH_MAX,_exe_path("uumovie.ini"));   
	int buffer = atoi(ftemp);

	SetTimer(TIMER_END,(m_video_sec + buffer)*1000,NULL );//,이것도 관리?+1
	
	m_this_start_time = CTime::GetCurrentTime();
	SetTimer(TIMER_PROGRESS,500,NULL );		// tic toc 초재기.

	m_b_play_mode = true;
}



CString _UudoinView::_exe_path(CString str)
{
	TCHAR TCHAR_path[300];		
	::GetModuleFileName(NULL, TCHAR_path, MAX_PATH);	
	CString path_file = TCHAR_path;
	path_file = path_file.Left(path_file.ReverseFind('\\'));	
	path_file += "\\" + str;
	
	return path_file;
}



void _UudoinView::OnTimer(UINT nIDEvent) 
{
	//kgs
	if (nIDEvent == TIMER_READY)
	{
		m_window_text = "!!! Time" + m_window_text;
		((_MainFrame*)AfxGetMainWnd())->SetWindowText(m_window_text);

		KillTimer(TIMER_READY);
	}
	else if (nIDEvent == TIMER_END)
	{
		KillTimer(TIMER_END);
		
		if (m_b_auto_mode)
			OnBUTTON_Next(true);
	}
	else if (nIDEvent == TIMER_PROGRESS)
	{
		CString s_total_window_text;

		CTime		now_time	= CTime::GetCurrentTime();
		CTimeSpan	this_span	= now_time - m_this_start_time;

		char ftemp[CH_MAX]={0,};
		GetPrivateProfileString("HOME","buffer","",ftemp,CH_MAX,_exe_path("uumovie.ini"));   
		int buffer = atoi(ftemp);

		CTimeSpan	total_span	= now_time - m_total_start_time;

		CString s_auto;
		if (m_b_auto_mode)
			s_auto = "Auto";
		else
			s_auto = "Manual";

		CString s_new;
		if (m_b_new_video)
			s_new = "New Video!";
		else
			s_new = "";
	
		s_total_window_text.Format("%s %02d:%02d/%02d:%02d+%d/%02dh%02d %s %s",
			m_window_text,
			this_span.GetMinutes(),this_span.GetSeconds(),
			m_video_sec/60,m_video_sec%60,buffer,
			total_span.GetTotalHours(),total_span.GetMinutes(),
			s_auto,s_new
		);
		((_MainFrame*)AfxGetMainWnd())->SetWindowText(s_total_window_text);
	}	
	else if (nIDEvent == TIMER_ROSE)
	{
		CString s_total_window_text;
		
		// CClassApp *pApp=(CClassApp *)AfxGetApp();   //View -> App
		_UudoinApp *pApp=(_UudoinApp *)AfxGetApp();		 
		s_total_window_text.Format("Rose %02d %s",pApp->m_Rose_Count,pApp->m_Rose_Text);
		((_MainFrame*)AfxGetMainWnd())->SetWindowText(s_total_window_text);

		button_GetRose();
	}

	//~kgs
	CView::OnTimer(nIDEvent);
}


void _UudoinView::_OnBUTTON_run() 
{	
	m_b_run_mode = true;
}


void _UudoinView::button_End() 
{
	OnBUTTON_Next(false);
}

CString _UudoinView::fromINI(CString param)
{
	CString r;
	char ftemp[256]={0,};				
	GetPrivateProfileString("HOME", param, "", ftemp, 256, _exe_path("uumovie.ini")); 
	
	r.Format("%s",ftemp);
	return r;
}

void _UudoinView::OnBUTTON_History() 
{
	MessageBox(m_history);	

	
	//이하는 섞는 거랑  상관없군; 
	CTimeSpan	m_total_time = CTimeSpan(0,0,0,0);
	
	for (int i = 0;i < Y_VIDEO_MAX; i++)
	{
		CString video_time = _video(1,i).time;
		
		int min = atoi(video_time.Left(video_time.Find(":")));
		int sec = atoi(video_time.Right(video_time.GetLength() - video_time.Find(":") - 1));
		
		m_total_time += CTimeSpan(0,0,min,sec);			
	}		
	
	CTimeSpan avr(0,0,0,m_total_time.GetTotalSeconds() / Y_VIDEO_MAX);
	
	CString s;
	s.Format("%d:%02d:%d %d/%d=%d\n %d:%d\n",
		m_total_time.GetHours(),
		m_total_time.GetMinutes(),
		m_total_time.GetSeconds(),
		m_total_time.GetTotalSeconds(),
		Y_VIDEO_MAX,
		avr.GetTotalSeconds(),
		avr.GetMinutes(),avr.GetSeconds());
	
	MessageBox(s+ m_cs_shuffles);	
}

void _UudoinView::button_GetRose() 
{
	static bool is_fisrt = true;
	if (is_fisrt == true)
	{
		is_fisrt = false;
		//

		SetTimer(TIMER_ROSE,34*1000,NULL );		
		// CClassApp *pApp=(CClassApp *)AfxGetApp();   //View -> App
		_UudoinApp *pApp=(_UudoinApp *)AfxGetApp();
		pApp->m_Rose_Count = 0;
	}	

	//
	CString language = "JScript";
	CString function = "_getRose()"; //괄호도 있어야함,세미콜론 불필요 
	
	LPDISPATCH pDisp;
	pDisp = m_ocx_ie.GetDocument();				
	
	IHTMLDocument2* spDoc;
	pDisp->QueryInterface(IID_IHTMLDocument2, (LPVOID*)&spDoc);
	
	IHTMLWindow2* pWin;
	spDoc->get_parentWindow(&pWin);
	
	//////////////////////////////////////
	//자바 스크립트 실행
	BSTR Javascript = T2BSTR(language.GetBuffer(language.GetLength()));
	BSTR Function = T2BSTR(function.GetBuffer(function.GetLength()));
	VARIANT vVal;
	VariantInit(&vVal);
	pWin->execScript(Function,Javascript,&vVal);
}
