// CUpSampleDIg.cpp: 구현 파일
//

#include "resource.h"
#include "pch.h"
#include "MFCApplication2.h"
#include "CUpSampleDIg.h"
#include "afxdialogex.h"


// CUpSampleDIg 대화 상자

IMPLEMENT_DYNAMIC(CUpSampleDIg, CDialogEx)

CUpSampleDIg::CUpSampleDIg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_UpSampleRate(0)
{

}

CUpSampleDIg::~CUpSampleDIg()
{
}

void CUpSampleDIg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT1, m_UpSampleRate);
	DDX_Text(pDX, IDC_EDIT1, m_UpSampleRate);
}


BEGIN_MESSAGE_MAP(CUpSampleDIg, CDialogEx)
END_MESSAGE_MAP()


// CUpSampleDIg 메시지 처리기
