
// homework_db.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Chomework_dbApp:
// �йش����ʵ�֣������ homework_db.cpp
//

class Chomework_dbApp : public CWinApp
{
public:
	Chomework_dbApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Chomework_dbApp theApp;