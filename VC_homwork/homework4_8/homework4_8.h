
// homework4_8.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Chomework4_8App:
// �йش����ʵ�֣������ homework4_8.cpp
//

class Chomework4_8App : public CWinApp
{
public:
	Chomework4_8App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Chomework4_8App theApp;