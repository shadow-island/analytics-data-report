; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=_UudoinView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "uudoin.h"
LastPage=0

ClassCount=8
Class1=_UudoinApp
Class2=_UudoinDoc
Class3=_UudoinView
Class4=_MainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=dialog_id
Class7=dialog_sign_up
Resource2=IDR_MAINFRAME
Class8=_Dialog_Control
Resource3=IDD_DIALOG

[CLS:_UudoinApp]
Type=0
HeaderFile=uudoin.h
ImplementationFile=uudoin.cpp
Filter=N

[CLS:_UudoinDoc]
Type=0
HeaderFile=uudoinDoc.h
ImplementationFile=uudoinDoc.cpp
Filter=N

[CLS:_UudoinView]
Type=0
HeaderFile=uudoinView.h
ImplementationFile=uudoinView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=_UudoinView


[CLS:_MainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=_MainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=uudoin.cpp
ImplementationFile=uudoin.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=_MainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=_MainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=_MainFrame
Command1=ID_FILE_PRINT
Command2=ID_APP_ABOUT
Command3=ID_BUTTON_auto
Command4=ID_BUTTON_run
Command5=ID_BUTTON_step
Command6=ID_BUTTON_Control
Command7=ID_BUTTON_next
Command8=ID_BUTTON_js
Command9=ID_BUTTON_End
Command10=ID_BUTTON_History
Command11=ID_BUTTON_GetRose
CommandCount=11

[CLS:dialog_id]
Type=0
HeaderFile=dialog_id.h
ImplementationFile=dialog_id.cpp
BaseClass=CDialog
Filter=D
LastObject=dialog_id
VirtualFilter=dWC

[CLS:dialog_sign_up]
Type=0
HeaderFile=dialog_sign_up.h
ImplementationFile=dialog_sign_up.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EXPLORER1
VirtualFilter=dWC

[DLG:IDD_DIALOG]
Type=1
Class=_Dialog_Control
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:_Dialog_Control]
Type=0
HeaderFile=_Dialog_Control.h
ImplementationFile=_Dialog_Control.cpp
BaseClass=CDialog
Filter=D
LastObject=_Dialog_Control
VirtualFilter=dWC

