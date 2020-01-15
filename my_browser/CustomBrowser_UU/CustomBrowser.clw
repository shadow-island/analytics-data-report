; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCustomBrowserDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "custombrowser.h"
LastPage=0

ClassCount=6
Class1=CCustomBrowserApp
Class2=CAboutDlg
Class3=CCustomBrowserDlg
Class4=CCustomModalDialog
Class5=CCustomModelessDialog
Class6=CCustomWindow

ResourceCount=6
Resource1=IDD_MODELESS_DIALOG (English (Canada))
Resource2=IDD_CUSTOMBROWSER_DIALOG (English (U.S.))
Resource3=IDD_MODAL_DIALOG (English (Canada))
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_WINDOW (English (Canada))
Resource6=IDR_CUSTOM_POPUP (English (Canada))

[CLS:CCustomBrowserApp]
Type=0
BaseClass=CWinApp
HeaderFile=CustomBrowser.h
ImplementationFile=CustomBrowser.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=CustomBrowserDlg.cpp
ImplementationFile=CustomBrowserDlg.cpp
LastObject=CAboutDlg

[CLS:CCustomBrowserDlg]
Type=0
BaseClass=CDialog
HeaderFile=CustomBrowserDlg.h
ImplementationFile=CustomBrowserDlg.cpp
LastObject=IDC_BUTTON_Next
Filter=D
VirtualFilter=dWC

[CLS:CCustomModalDialog]
Type=0
BaseClass=CDialog
HeaderFile=CustomModalDialog.h
ImplementationFile=CustomModalDialog.cpp

[CLS:CCustomModelessDialog]
Type=0
BaseClass=CDialog
HeaderFile=CustomModelessDialog.h
ImplementationFile=CustomModelessDialog.cpp

[CLS:CCustomWindow]
Type=0
BaseClass=CDialog
HeaderFile=CustomWindow.h
ImplementationFile=CustomWindow.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg

[DLG:IDD_CUSTOMBROWSER_DIALOG]
Type=1
Class=CCustomBrowserDlg

[DLG:IDD_MODAL_DIALOG]
Type=1
Class=CCustomModalDialog

[DLG:IDD_MODELESS_DIALOG]
Type=1
Class=CCustomModelessDialog

[DLG:IDD_WINDOW]
Type=1
Class=CCustomWindow

[DLG:IDD_MODAL_DIALOG (English (Canada))]
Type=1
Class=?
ControlCount=1
Control1=IDC_EXPLORER1,{8856F961-340A-11D0-A96B-00C04FD705A2},1342242816

[DLG:IDD_CUSTOMBROWSER_DIALOG (English (U.S.))]
Type=1
Class=CCustomBrowserDlg
ControlCount=2
Control1=IDC_EXPLORER1,{8856F961-340A-11D0-A96B-00C04FD705A2},1342242816
Control2=IDC_BUTTON_Next,button,1342242816

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WINDOW (English (Canada))]
Type=1
Class=?
ControlCount=1
Control1=IDC_EXPLORER1,{8856F961-340A-11D0-A96B-00C04FD705A2},1342242816

[DLG:IDD_MODELESS_DIALOG (English (Canada))]
Type=1
Class=?
ControlCount=1
Control1=IDC_EXPLORER1,{8856F961-340A-11D0-A96B-00C04FD705A2},1342242816

[MNU:IDR_CUSTOM_POPUP (English (Canada))]
Type=1
Class=?
Command1=ID_POPUP_ITEM1
Command2=ID_POPUP_ITEM2
CommandCount=2

