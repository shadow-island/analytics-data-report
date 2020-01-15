// MainFrm.cpp : implementation of the _MainFrame class
//

#include "stdafx.h"
#include "uudoin.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _MainFrame

IMPLEMENT_DYNCREATE(_MainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(_MainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(_MainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// _MainFrame construction/destruction

_MainFrame::_MainFrame()
{
	// TODO: add member initialization code here
	
}

_MainFrame::~_MainFrame()
{
}

int _MainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//kgs
	SetWindowText("UU Movie");
	//

	return 0;
}

BOOL _MainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	//kgs
	cs.style &= ~FWS_ADDTOTITLE ; 
	//

	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs




	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// _MainFrame diagnostics

#ifdef _DEBUG
void _MainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void _MainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// _MainFrame message handlers

