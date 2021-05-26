// CQuantizationDIg.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "CQuantizationDIg.h"
#include "afxdialogex.h"


// CQuantizationDIg 대화 상자

IMPLEMENT_DYNAMIC(CQuantizationDIg, CDialogEx)

CQuantizationDIg::CQuantizationDIg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_QuantBit(0)
{

}

CQuantizationDIg::~CQuantizationDIg()
{
}

void CQuantizationDIg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_QuantBit);
	DDV_MinMaxInt(pDX, m_QuantBit, 1, 8);
}


BEGIN_MESSAGE_MAP(CQuantizationDIg, CDialogEx)
END_MESSAGE_MAP()


// CQuantizationDIg 메시지 처리기
