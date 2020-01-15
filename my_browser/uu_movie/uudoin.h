// uudoin.h : main header file for the UUDOIN application
//

#if !defined(AFX_UUDOIN_H__A3FF6E72_A031_4CAE_868D_E868F8C4B68F__INCLUDED_)
#define AFX_UUDOIN_H__A3FF6E72_A031_4CAE_868D_E868F8C4B68F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// _UudoinApp:
// See uudoin.cpp for the implementation of this class
//

class _UudoinView; //for get_pView

class _UudoinApp : public CWinApp
{
public:
	_UudoinView* get_pView();
	_UudoinApp();

	//kgs
	class CImpIDispatch*	m_pDispOM;
	//
	int						m_Rose_Count;
	CString					m_Rose_Text;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_UudoinApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(_UudoinApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UUDOIN_H__A3FF6E72_A031_4CAE_868D_E868F8C4B68F__INCLUDED_)
