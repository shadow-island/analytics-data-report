// uudoinDoc.h : interface of the _UudoinDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UUDOINDOC_H__8826B640_397D_49B0_B381_EF4A272D1772__INCLUDED_)
#define AFX_UUDOINDOC_H__8826B640_397D_49B0_B381_EF4A272D1772__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class _UudoinDoc : public CDocument
{
protected: // create from serialization only
	_UudoinDoc();
	DECLARE_DYNCREATE(_UudoinDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(_UudoinDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~_UudoinDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(_UudoinDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UUDOINDOC_H__8826B640_397D_49B0_B381_EF4A272D1772__INCLUDED_)
