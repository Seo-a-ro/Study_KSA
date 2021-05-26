// CStressTransFormDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "CStressTransFormDlg.h"
#include "afxdialogex.h"


// CStressTransFormDlg 대화 상자

IMPLEMENT_DYNAMIC(CStressTransFormDlg, CDialogEx)

CStressTransFormDlg::CStressTransFormDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, m_StarPoint(0)
	, m_EndPoint(0)
{

}

CStressTransFormDlg::~CStressTransFormDlg()
{
}

void CStressTransFormDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_StarPoint);
	DDV_MinMaxInt(pDX, m_StarPoint, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_EndPoint);
	DDV_MinMaxInt(pDX, m_EndPoint, 0, 255);
}


BEGIN_MESSAGE_MAP(CStressTransFormDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CStressTransFormDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CStressTransFormDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CStressTransFormDlg 메시지 처리기




void CStressTransFormDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CStressTransFormDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
