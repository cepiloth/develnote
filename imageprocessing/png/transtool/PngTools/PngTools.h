
// PngTools.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPngToolsApp:
// �� Ŭ������ ������ ���ؼ��� PngTools.cpp�� �����Ͻʽÿ�.
//

class CPngToolsApp : public CWinApp
{
public:
	CPngToolsApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPngToolsApp theApp;