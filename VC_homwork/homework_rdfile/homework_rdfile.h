
// homework_rdfile.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Chomework_rdfileApp:
// �йش����ʵ�֣������ homework_rdfile.cpp
//

class Chomework_rdfileApp : public CWinApp
{
public:
	Chomework_rdfileApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Chomework_rdfileApp theApp;