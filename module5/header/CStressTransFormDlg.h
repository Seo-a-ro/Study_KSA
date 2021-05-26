#pragma once


// CStressTransFormDlg 대화 상자

class CStressTransFormDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStressTransFormDlg)

public:
	CStressTransFormDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CStressTransFormDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_StarPoint;
	int m_EndPoint;

	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
};
