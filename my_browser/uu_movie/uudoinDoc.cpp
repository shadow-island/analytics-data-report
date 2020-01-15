// uudoinDoc.cpp : implementation of the _UudoinDoc class
//

#include "stdafx.h"
#include "uudoin.h"

#include "uudoinDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _UudoinDoc

IMPLEMENT_DYNCREATE(_UudoinDoc, CDocument)

BEGIN_MESSAGE_MAP(_UudoinDoc, CDocument)
	//{{AFX_MSG_MAP(_UudoinDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _UudoinDoc construction/destruction

_UudoinDoc::_UudoinDoc()
{
	// TODO: add one-time construction code here

}

_UudoinDoc::~_UudoinDoc()
{
}

BOOL _UudoinDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// _UudoinDoc serialization

void _UudoinDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// _UudoinDoc diagnostics

#ifdef _DEBUG
void _UudoinDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void _UudoinDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// _UudoinDoc commands
