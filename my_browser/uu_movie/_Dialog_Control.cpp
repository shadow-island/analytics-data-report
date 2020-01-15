// _Dialog_Control.cpp : implementation file
//

#include "stdafx.h"
#include "uudoin.h"
#include "_Dialog_Control.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Dialog_Control dialog


_Dialog_Control::_Dialog_Control(CWnd* pParent /*=NULL*/)
	: CDialog(_Dialog_Control::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Dialog_Control)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Dialog_Control::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Dialog_Control)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(_Dialog_Control, CDialog)
	//{{AFX_MSG_MAP(_Dialog_Control)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Dialog_Control message handlers



BOOL _Dialog_Control::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	enum
	{
		ID_BROWSER	= 0,
		IE_MARGIN	= -2,
	};

	//GetClientRect()

	// 이게 OnInitialUpdate 안에 있으면 onsize시 에러 
	ocx_ie.Create("Browser", WS_VISIBLE, CRect(IE_MARGIN,IE_MARGIN,100,100), this, ID_BROWSER);		
	
	// ID는 BEGIN_EVENTSINK_MAP과 맞추기위한 것
	// IE_MARGIN = control이 view에 꽉차게	

	ocx_ie.Navigate("http://naver.com", NULL, NULL, NULL, NULL);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
