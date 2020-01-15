// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "webbrowser2.h"

/////////////////////////////////////////////////////////////////////////////
// ocx_WebBrowser2

IMPLEMENT_DYNCREATE(ocx_WebBrowser2, CWnd)

/////////////////////////////////////////////////////////////////////////////
// ocx_WebBrowser2 properties

/////////////////////////////////////////////////////////////////////////////
// ocx_WebBrowser2 operations

void ocx_WebBrowser2::GoBack()
{
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ocx_WebBrowser2::GoForward()
{
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ocx_WebBrowser2::GoHome()
{
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ocx_WebBrowser2::GoSearch()
{
	InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ocx_WebBrowser2::Navigate(LPCTSTR URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 URL, Flags, TargetFrameName, PostData, Headers);
}


void ocx_WebBrowser2::Navigate2(VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers)
{
	//이쪽으론 안오네 
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x1f4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 URL, Flags, TargetFrameName, PostData, Headers);
}

void ocx_WebBrowser2::Refresh()
{
	InvokeHelper(DISPID_REFRESH, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ocx_WebBrowser2::Refresh2(VARIANT* Level)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Level);
}

void ocx_WebBrowser2::Stop()
{
	InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH ocx_WebBrowser2::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0xc8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH ocx_WebBrowser2::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH ocx_WebBrowser2::GetContainer()
{
	LPDISPATCH result;
	InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH ocx_WebBrowser2::GetDocument()
{
	LPDISPATCH result;
	InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL ocx_WebBrowser2::GetTopLevelContainer()
{
	BOOL result;
	InvokeHelper(0xcc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString ocx_WebBrowser2::GetType()
{
	CString result;
	InvokeHelper(0xcd, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long ocx_WebBrowser2::GetLeft()
{
	long result;
	InvokeHelper(0xce, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetLeft(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xce, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long ocx_WebBrowser2::GetTop()
{
	long result;
	InvokeHelper(0xcf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetTop(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xcf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long ocx_WebBrowser2::GetWidth()
{
	long result;
	InvokeHelper(0xd0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetWidth(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xd0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long ocx_WebBrowser2::GetHeight()
{
	long result;
	InvokeHelper(0xd1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetHeight(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xd1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString ocx_WebBrowser2::GetLocationName()
{
	CString result;
	InvokeHelper(0xd2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString ocx_WebBrowser2::GetLocationURL()
{
	CString result;
	InvokeHelper(0xd3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL ocx_WebBrowser2::GetBusy()
{
	BOOL result;
	InvokeHelper(0xd4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::Quit()
{
	InvokeHelper(0x12c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ocx_WebBrowser2::ClientToWindow(long* pcx, long* pcy)
{
	static BYTE parms[] =
		VTS_PI4 VTS_PI4;
	InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pcx, pcy);
}

void ocx_WebBrowser2::PutProperty(LPCTSTR Property_, const VARIANT& vtValue)
{
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Property_, &vtValue);
}

VARIANT ocx_WebBrowser2::GetProperty_(LPCTSTR Property_)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x12f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Property_);
	return result;
}

CString ocx_WebBrowser2::GetName()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long ocx_WebBrowser2::GetHwnd()
{
	long result;
	InvokeHelper(DISPID_HWND, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString ocx_WebBrowser2::GetFullName()
{
	CString result;
	InvokeHelper(0x190, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString ocx_WebBrowser2::GetPath()
{
	CString result;
	InvokeHelper(0x191, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL ocx_WebBrowser2::GetVisible()
{
	BOOL result;
	InvokeHelper(0x192, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetVisible(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x192, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL ocx_WebBrowser2::GetStatusBar()
{
	BOOL result;
	InvokeHelper(0x193, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetStatusBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x193, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString ocx_WebBrowser2::GetStatusText()
{
	CString result;
	InvokeHelper(0x194, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetStatusText(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x194, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long ocx_WebBrowser2::GetToolBar()
{
	long result;
	InvokeHelper(0x195, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetToolBar(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x195, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL ocx_WebBrowser2::GetMenuBar()
{
	BOOL result;
	InvokeHelper(0x196, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetMenuBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x196, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL ocx_WebBrowser2::GetFullScreen()
{
	BOOL result;
	InvokeHelper(0x197, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetFullScreen(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x197, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}


long ocx_WebBrowser2::QueryStatusWB(long cmdID)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1f5, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		cmdID);
	return result;
}

void ocx_WebBrowser2::ExecWB(long cmdID, long cmdexecopt, VARIANT* pvaIn, VARIANT* pvaOut)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x1f6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 cmdID, cmdexecopt, pvaIn, pvaOut);
}

void ocx_WebBrowser2::ShowBrowserBar(VARIANT* pvaClsid, VARIANT* pvarShow, VARIANT* pvarSize)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x1f7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pvaClsid, pvarShow, pvarSize);
}

long ocx_WebBrowser2::GetReadyState()
{
	long result;
	InvokeHelper(DISPID_READYSTATE, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL ocx_WebBrowser2::GetOffline()
{
	BOOL result;
	InvokeHelper(0x226, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetOffline(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x226, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL ocx_WebBrowser2::GetSilent()
{
	BOOL result;
	InvokeHelper(0x227, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetSilent(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x227, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL ocx_WebBrowser2::GetRegisterAsBrowser()
{
	BOOL result;
	InvokeHelper(0x228, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetRegisterAsBrowser(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x228, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL ocx_WebBrowser2::GetRegisterAsDropTarget()
{
	BOOL result;
	InvokeHelper(0x229, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetRegisterAsDropTarget(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x229, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL ocx_WebBrowser2::GetTheaterMode()
{
	BOOL result;
	InvokeHelper(0x22a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetTheaterMode(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x22a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL ocx_WebBrowser2::GetAddressBar()
{
	BOOL result;
	InvokeHelper(0x22b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetAddressBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x22b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL ocx_WebBrowser2::GetResizable()
{
	BOOL result;
	InvokeHelper(0x22c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void ocx_WebBrowser2::SetResizable(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x22c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}
