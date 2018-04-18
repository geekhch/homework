; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEmployeeView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "employee.h"
LastPage=0

ClassCount=6
Class1=CEmployeeApp
Class2=CEmployeeDoc
Class3=CEmployeeView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CEmployeeDialog
Resource3=IDD_DIALOG_EMPLOYEE

[CLS:CEmployeeApp]
Type=0
HeaderFile=employee.h
ImplementationFile=employee.cpp
Filter=N

[CLS:CEmployeeDoc]
Type=0
HeaderFile=employeeDoc.h
ImplementationFile=employeeDoc.cpp
Filter=N

[CLS:CEmployeeView]
Type=0
HeaderFile=employeeView.h
ImplementationFile=employeeView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_MENUITEM_INPUT


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=employee.cpp
ImplementationFile=employee.cpp
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
Class=CMainFrame
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
Command17=ID_MENUITEM_INPUT
Command18=ID_MENUITEM_SHOW
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
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
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG_EMPLOYEE]
Type=1
Class=CEmployeeDialog
ControlCount=18
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308354
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308354
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_STATIC,static,1342308354
Control8=IDC_EDIT3,edit,1350631552
Control9=IDC_STATIC,static,1342308354
Control10=IDC_EDIT4,edit,1350631552
Control11=IDC_STATIC,static,1342308353
Control12=IDC_EDIT5,edit,1350631552
Control13=IDC_STATIC,static,1342308353
Control14=IDC_EDIT6,edit,1350631552
Control15=IDC_STATIC,static,1342308353
Control16=IDC_STATIC,static,1342308354
Control17=IDC_EDIT7,edit,1350631552
Control18=IDC_STATIC,static,1342308352

[CLS:CEmployeeDialog]
Type=0
HeaderFile=EmployeeDialog.h
ImplementationFile=EmployeeDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

