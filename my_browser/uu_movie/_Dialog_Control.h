#if !defined(AFX__DIALOG_CONTROL_H__BE274E93_63FD_4E8F_B4D0_78EC4FB2A81D__INCLUDED_)
#define AFX__DIALOG_CONTROL_H__BE274E93_63FD_4E8F_B4D0_78EC4FB2A81D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// _Dialog_Control.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// _Dialog_Control dialog

//
#include "webbrowser2.h"
//


class _Dialog_Control : public CDialog
{
// Construction
public:
	_Dialog_Control(CWnd* pParent = NULL);   // standard constructor

private:
	ocx_WebBrowser2 ocx_ie;

// Dialog Data
	//{{AFX_DATA(_Dialog_Control)
	enum { IDD = IDD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_Dialog_Control)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(_Dialog_Control)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__DIALOG_CONTROL_H__BE274E93_63FD_4E8F_B4D0_78EC4FB2A81D__INCLUDED_)
