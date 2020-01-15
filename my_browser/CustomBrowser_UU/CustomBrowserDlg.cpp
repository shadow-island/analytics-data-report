// CustomBrowserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CustomBrowser.h"
#include "CustomBrowserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomBrowserDlg dialog

CCustomBrowserDlg::CCustomBrowserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCustomBrowserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCustomBrowserDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	nWindowCount = 0;
	strModalDialogInfo.nWidth=0;
	strModalDialogInfo.nHeight = 0;
	strModalDialogInfo.nLeft = 0;
	strModalDialogInfo.nTop = 0;
}

void CCustomBrowserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomBrowserDlg)
	DDX_Control(pDX, IDC_EXPLORER1, m_Browser);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCustomBrowserDlg, CDialog)
	//{{AFX_MSG_MAP(CCustomBrowserDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_Next, OnBUTTON_Next)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomBrowserDlg message handlers

BOOL CCustomBrowserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	CRect rect;
	GetClientRect(&rect);
	rect.DeflateRect(1,1,1,1);
	
	m_button_size = 22;
	m_Browser.SetWindowPos(NULL,
		rect.left, rect.top + m_button_size, rect.Width(), rect.Height() - m_button_size,NULL);
	

	//Get Current Path of exe
	CString cszFullFileName;
	GetModuleFileName ( AfxGetInstanceHandle ( ), cszFullFileName.GetBuffer( MAX_PATH ), MAX_PATH ) ;
	cszFullFileName.ReleaseBuffer();
	cszFullFileName = cszFullFileName.Left ( cszFullFileName.ReverseFind ( '\\' ) ) ;


	COleVariant varEmpty;
	//COleVariant varURL(cszFullFileName + "\\CustomTest.html");
	COleVariant varURL("http://www.geopia.com/?view=action&action=login&&userid=qweas4&passwd=wls117&rtnUrl=http%3A%2F%2Fchat.geopia.com%2F%3Fview%3Dindex%26mode%3Dlist%26cate1%3D%25BF%25AC%25B7%25C9%25BA%25B0%26cate2%3D40%25B4%25EB%25C0%25CC%25BB%25F3");

	if (0)
		m_Browser.Navigate2(varURL, varEmpty,varEmpty,varEmpty,varEmpty);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCustomBrowserDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCustomBrowserDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCustomBrowserDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCustomBrowserDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	rect.DeflateRect(1,1,1,1);
	if(m_Browser)
		m_Browser.SetWindowPos(NULL,
			rect.left, rect.top + m_button_size, rect.Width(), rect.Height() - m_button_size,NULL);
}

BOOL CCustomBrowserDlg::CB_IsOurCustomBrowser()
{
	//return true because this is obviously our
	//custom browser
	return TRUE;
}

void CCustomBrowserDlg::CB_Close()
{
	//AfxMessageBox("Close the browser here or the current window");

	//This is one way you can determine whether or not
	//to close a dialog or the main application depending
	//on if you call the CB_Close method from an html page
	//in a dialog/window or from an html page in the main app
	
	
	CWnd* pWnd = GetActiveWindow();

	if(pWnd == this)
	{
		
		EndDialog(0);
	}
	else
	{
		CDialog* pWin = (CDialog*)pWnd;
		pWin->EndDialog(1);
	}
	
}

void CCustomBrowserDlg::CB_CustomFunction()
{

	AfxMessageBox("Do whatever you like here!");
}

void CCustomBrowserDlg::CB_CustomFunctionWithParams(CString cszString, int nNumber)
{
	CString cszParameters;
	cszParameters.Format("parameter 1: %s\nparameter 2:  %d", cszString, nNumber);
	AfxMessageBox(cszParameters);
}

void CCustomBrowserDlg::CB_OpenWindow(CString cszURL, int nLeft, int nTop, int nWidth, int nHeight, int nResizable)
{
	/*CString cszParameters;
	cszParameters.Format("URL=%s LEFT=%d TOP=%d WIDTH=%d HEIGHT=%d RESIZABLE=%d", cszURL, nLeft, nTop, nWidth, nHeight, nResizable);
	AfxMessageBox(cszParameters);*/

	dlg[nWindowCount].Create(IDD_WINDOW);
	dlg[nWindowCount].SetWindowPos(NULL,nLeft, nTop, nWidth, nHeight,NULL);
	dlg[nWindowCount].cszURL = cszURL;
	dlg[nWindowCount].ShowWindow(SW_SHOW);
	nWindowCount++;
}

void CCustomBrowserDlg::CB_ShowModalDialog(CString cszURL, int nLeft, int nTop, int nWidth, int nHeight)
{
	/*CString cszParameters;
	cszParameters.Format("URL=%s LEFT=%d TOP=%d WIDTH=%d HEIGHT=%d RESIZABLE=%d", cszURL, nLeft, nTop, nWidth, nHeight);
	AfxMessageBox(cszParameters);*/

	CCustomModalDialog modaldlg;
	strModalDialogInfo.cszURL = cszURL;
	strModalDialogInfo.nWidth = nWidth;
	strModalDialogInfo.nHeight = nHeight;
	strModalDialogInfo.nLeft = nLeft;
	strModalDialogInfo.nTop = nTop;
	modaldlg.DoModal();
}

void CCustomBrowserDlg::CB_ShowModelessDialog(CString cszURL, int nLeft, int nTop, int nWidth, int nHeight)
{
	/*CString cszParameters;
	cszParameters.Format("URL=%s LEFT=%d TOP=%d WIDTH=%d HEIGHT=%d RESIZABLE=%d", cszURL, nLeft, nTop, nWidth, nHeight);
	AfxMessageBox(cszParameters);*/

	dlgmodeless[nWindowCount].Create(IDD_MODELESS_DIALOG);
	dlgmodeless[nWindowCount].SetWindowPos(NULL,nLeft, nTop, nWidth, nHeight,NULL);
	dlgmodeless[nWindowCount].cszURL = cszURL;
	dlgmodeless[nWindowCount].ShowWindow(SW_SHOW);
	nWindowCount++;
}

void CCustomBrowserDlg::OnBUTTON_Next() 
{
	const CH_MAX		= 111;
	const	Y_VIDEO_MAX	= 17;	//vector화?	
	const	E_VIDEO_MAX	= 5;	//vector화
	//

	struct struct_video
	{
		char	title[CH_MAX];
		char	time[CH_MAX];
		char	url[CH_MAX];				
	};
	
	static bool is_y_mode = true;
	CString		ini_ye_item;

	if (is_y_mode)
		ini_ye_item = "y_video";
	else
		ini_ye_item = "e_video";
	
	//Get Current Path of exe
	CString cszFullFileName;
	GetModuleFileName ( AfxGetInstanceHandle ( ), cszFullFileName.GetBuffer( MAX_PATH ), MAX_PATH ) ;
	cszFullFileName.ReleaseBuffer();
	cszFullFileName = cszFullFileName.Left ( cszFullFileName.ReverseFind ( '\\' ) ) ;

	char ftemp[CH_MAX]={0,};
	GetPrivateProfileString("HOME",ini_ye_item,"",ftemp,CH_MAX,cszFullFileName + "\\uumovie.ini");

	int		video_n = atoi(ftemp);
	CString	video_title;
	CString	video_time;
	CString	video_url;

	int		max = Y_VIDEO_MAX + E_VIDEO_MAX;

	if (is_y_mode)
	{			
		struct_video video[Y_VIDEO_MAX] = 	
		{	
			// 초반에 많이 나가나 보고 많이나가면 random으로?
			//이때 추가 작업하자 
			{"~?P33.paipan*",	"33:00",	"http://ubuntuone.com/07mTbJ68gVXCwB7aJTxxNu"},
			{"os7_3some*",		"7:00",	"http://blogcafe.dreamwiz.com/cafefile/r/h/rhlgw/111(1).asx"},
			{"~op27_LezM27*",	"26:00",	"http://ubuntuone.com/5u7g6VefdgGX6mAzdK9jdg"},
			{"ws4_o_se*",		"5:00",	"http://ubuntuone.com/4P07YR52Z9zmBnjAnRoW7E"},			
			{"wp7_ball*",		"7:00",	"http://ubuntuone.com/1Mm5QkwyIzCh9GRGsvUkdP"},
			
			//5
			{"p3_girl",			"3:01",	"http://ubuntuone.com/0hfI0jNzIGlYgiLnHVsIpD"},
			{"? Os7_K_m2com*","7:00",	"http://ubuntuone.com/7BTyxSShJlgEI2pzNvF0nj"},
			{"~OP24_K_Mas*",	"24:00",	"http://ubuntuone.com/5BKCBzl90z9W73IjTn5Yqo"},
			{"ws6_fore_bed*",	"6:00",	"http://ubuntuone.com/00NuFZEjQOAiJmsX2JeqAg"},			
			{"wp9_foot*",		"9:30",	"http://ubuntuone.com/4XRAzHqUtmhX2pLk9waGtE"},				
			
			//10
			{"p20-pro.Chair*","20:00",	"http://ubuntuone.com/26f5hyyxnIHazS6DHioAiP"},				
			{"? os_9MIN_conv*","9:00",	"http://ubuntuone.com/4itjuPJkHxnn4mahrNe9DG"},
			{"OP11_5ko_ero*",	"11:00",	"http://www.weebly.com/uploads/1/9/8/4/19848167/op11_5ko_dogpussy_js1m_asian_s1m_pissing1m_maid6_ero.asx"},
			{"? WS10 her_a2m*","10:00","http://ubuntuone.com/1TUzTI263v07YCukI4pEtl"},	
			//이상은 정확한 시간아님 
			{"wp2_Rimming",	"1:41",	"http://ubuntuone.com/0iUupDrOXxyv9shR3gm2rm"},	
			//15
			{"p7.39-k.fOot",	"7:39",	"http://ubuntuone.com/3jo1s7rKTD79SWGoCmYyMc"},
			//시간모름
			{"os10_j_dream*",	"10:00",	"http://Blogcafe.dreamwiz.com/cafefile/d/f/dfdfdffgd/kim.asx"},
			//안되는거 하나 체크 후 시간체크 후 추가~ 
		};
		
		video_title	= video[video_n].title;
		video_time	= video[video_n].time;
		video_url	= video[video_n].url;		
		max			= Y_VIDEO_MAX;

		Do_video_num(video_n,max,ini_ye_item);		
	}
	else
	{
		int	ransu;
		ransu	=	rand() % 2;

		if (ransu == 0)
		{
			video_n		= max;
			video_title	= "cinero";
			video_time	= "00:13"; //다들 기다리면 증가?
			video_url	= "mms://182.161.120.180/cinero/vod/Cinero2";	
		}
		else
		{	
			struct_video video[E_VIDEO_MAX] = 	
			{			
				{"kino-1",	"85:41",	"http://wadisk.co.kr/abc/kino/1.wmv"},
				{"kino-2",	"80:05",	"http://wadisk.co.kr/abc/kino/2.wmv"},			
				{"kino-3",	"76:57",	"http://wadisk.co.kr/abc/kino/3.wmv"},			
				{"kino-4",	"72:34",	"http://wadisk.co.kr/abc/kino/4.wmv"},	
				{"kino-5",	"87:50",	"http://wadisk.co.kr/abc/kino/5.wmv"},					
			};

			video_title	= video[video_n].title;
			video_time	= video[video_n].time;
			video_url	= video[video_n].url;				
			max			= E_VIDEO_MAX;			

			Do_video_num(video_n,max,ini_ye_item);	
		}
	}
	
	
	CStdioFile file_old;
	CString f;
	f = cszFullFileName + "\\temp_a.html";
	if ( !file_old.Open(f,  CFile::modeRead) )
	{
		MessageBox("Error");
		return;
	}
		
	CFile file_write;	
	f = cszFullFileName + "\\go.html";
	file_write.Open( f, CFile::modeCreate | CFile::modeWrite );
	
	CString strLine;	
	while( file_old.ReadString( strLine ) )
	{			
		strLine.Replace("EK",video_url);
		strLine += "\n";
		// 한줄씩 복사 
		file_write.Write(strLine, strLine.GetLength() );
	}
	
	file_old.Close();
	file_write.Close();
			
		

	
	
	COleVariant varEmpty;
	COleVariant varURL(cszFullFileName + "\\go.html");	
	
	m_Browser.Navigate2(varURL, varEmpty,varEmpty,varEmpty,varEmpty);
	//

	//~
	CString s_run;
	if (m_b_run_mode)
		s_run = "RUN";
	else
		s_run = "";
	

	m_window_text.Format("%s UUMovie (%d/%d)%s",s_run,video_n,max,video_title);
	((_MainFrame*)AfxGetMainWnd())->SetWindowText(m_window_text);
	//~

	KillTimer(TIMER_END);
	
	int min = atoi(video_time.Left(video_time.Find(":")));
	int sec = atoi(video_time.Right(video_time.GetLength() - video_time.Find(":") - 1));	

	m_video_sec = min*60 + sec; 
	
	//buff		
	SetTimer(TIMER_END,(m_video_sec+1)*1000,NULL );

	m_start_time = CTime::GetCurrentTime();
	SetTimer(TIMER_PROGRESS,500,NULL );		// tic toc 초재기.

	is_y_mode = !is_y_mode;	

	if (m_b_auto_mode == true)
		m_start_js = true;


}

void CCustomBrowserDlg::Do_video_num(int n, int max, CString ini_ye_item)
{
	CString s;
	if (n == max - 1)
	{
		s.Format("new %s",ini_ye_item);
		MessageBox(s);
	}
	
	//n값을 다 쓴후 제일 마지막 처리
	n++;	
	if (n >= max)
		n = 0; //첫숫자로
	
	s.Format("%d",n);
	WritePrivateProfileString("HOME",ini_ye_item,s,_exe_path("uumovie.ini"));
	
	ini_ye_item += "_max";
	s.Format("%d",max);
	WritePrivateProfileString("HOME",ini_ye_item,s,_exe_path("uumovie.ini"));
}
