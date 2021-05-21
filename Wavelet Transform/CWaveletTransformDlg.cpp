#include "pch.h"
#include "CWaveletTransformDlg.h"
#include "afxdialogex.h"
#include "WaveletTransform.h"
#include "WaveletTransformDoc.h"
#include "CArrangeDlg.h" 

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
//#endif

//    CWaveletTransformDlg dialog
// CWaveletTransformDlg ��ȭ ����

IMPLEMENT_DYNAMIC(CWaveletTransformDlg, CDialog)

CWaveletTransformDlg::CWaveletTransformDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_Level(0)
	, m_Error(0)
	, m_SNR(0)
	, m_FilterCheck(0)
{
	m_pDoc = NULL;

}
CWaveletTransformDlg::CWaveletTransformDlg(CWaveletTransformDoc* pDoc, CWnd* pParent /*=NULL*/) : CDialog(IDD_DIALOG1, pParent)
{
	m_pDoc = pDoc; // Doc Ŭ���� ����
	m_Level = 1; // Wavelet ���� ���� �ʱ�ȭ
	m_Error = 0.0f; // MSE �ʱ�ȭ
	m_SNR = 0.0f; // SNR �ʱ�ȭ
	m_FilterCheck = 0; // Filter Check �ʱ�ȭ
}
CWaveletTransformDlg::~CWaveletTransformDlg()
{

}



void CWaveletTransformDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Level);
	DDX_Text(pDX, IDC_EDIT2, m_Error);
	DDX_Text(pDX, IDC_EDIT3, m_SNR);
	DDX_Radio(pDX, IDC_RADIO1, m_FilterCheck);

}


BEGIN_MESSAGE_MAP(CWaveletTransformDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CWaveletTransformDlg::OnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_ARRANGE, &CWaveletTransformDlg::OnClickedButtonArrange)
	ON_BN_CLICKED(ID_BUTTON_END, &CWaveletTransformDlg::OnClickedButtonEnd)
END_MESSAGE_MAP()


// CWaveletTransformDIg �޽��� ó����


void CWaveletTransformDlg::OnClickedButtonUpdate()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_pDoc->m_Level = m_Level;

	// ��ȭ���ڿ��� �Է¹��� ���� ���� Doc Ŭ������ ����
	m_pDoc->OnWaveletEncode(); // ���̺귿 ��ȯ

	m_pDoc->OnWaveletDecode();// ���̺귿 ����ȯ
	m_pDoc->OnSNR();// ��ȣ �� ������ 

	UpdateData(FALSE); // ��� ������Ʈ 

}


void CWaveletTransformDlg::OnClickedButtonArrange()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	   // ��ư�� ������ ���� ���� ���
	CArrangeDlg dlg;
	//dlg.m_tempImage = new unsigned char* [m_pDoc->m_Size];
	dlg.Width = m_pDoc->m_Width;
	dlg.Height = m_pDoc->m_Height;
	dlg.m_tempImage = m_pDoc->m_ArrangeImage;

	UpdateData(TRUE);

	dlg.DoModal(); // ���� ������ ���� ��ȭ���� ���
}




void CWaveletTransformDlg::OnClickedButtonEnd()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialog::OnOK();

}