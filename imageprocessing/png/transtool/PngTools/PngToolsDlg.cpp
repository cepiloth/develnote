
// PngToolsDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "PngTools.h"
#include "PngToolsDlg.h"
#include "afxdialogex.h"

#include "ChunkUtils.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPngToolsDlg 대화 상자



CPngToolsDlg::CPngToolsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPngToolsDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPngToolsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPngToolsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CPngToolsDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CPngToolsDlg::OnBnClickedButton1)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_CRC, &CPngToolsDlg::OnBnClickedButtonCrc)
END_MESSAGE_MAP()


// CPngToolsDlg 메시지 처리기

BOOL CPngToolsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPngToolsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPngToolsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPngToolsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPngToolsDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CPngToolsDlg::OnBnClickedButton1()
{
	// 객체생성자에 TRUE를 인자로 넘기면 "열기" 대화상자가 만들어지고 FALSE를 인자로 넘기면
	// "저장" 대화상자가 만들어집니다.
	CFileDialog dlg(TRUE);
	// 파일 대화상자 실행
	if(dlg.DoModal() == IDOK){
		CString path = dlg.GetPathName();

		CRect rect;
		GetDlgItem(IDC_BITMAP_ANT0)->GetWindowRect(rect);

		CDC *dc = GetDC();
		CDC memDC;

		HANDLE m_hImage;
		BITMAP bmpInfo;

		memDC.CreateCompatibleDC(dc);

		CImage image;

		image.Load(path);
		m_hImage = (HBITMAP)image;
		HBITMAP bmpOld = (HBITMAP)memDC.SelectObject(m_hImage);

		GetObject(m_hImage, sizeof(BITMAP), &bmpInfo);

		dc->StretchBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &memDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);

		memDC.SelectObject(bmpOld);
		memDC.DeleteDC();
		dc->DeleteDC();

	}  
}


void CPngToolsDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CPngToolsDlg::OnBnClickedButtonCrc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog dlg(TRUE);
	// 파일 대화상자 실행
	if(dlg.DoModal() == IDOK){
		CString path = dlg.GetPathName();
	}
}
