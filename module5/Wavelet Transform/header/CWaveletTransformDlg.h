#pragma once


class CWaveletTransformDoc;


class CWaveletTransformDlg : public CDialog
{// Construction
	DECLARE_DYNAMIC(CWaveletTransformDlg)
public:
	CWaveletTransformDlg(CWnd* pParent = NULL); // standard constructor
	virtual ~CWaveletTransformDlg();
	CWaveletTransformDlg(CWaveletTransformDoc* pDoc, CWnd* pParent = NULL);

	// Implementation





	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	CWaveletTransformDoc* m_pDoc;

	DECLARE_MESSAGE_MAP()
public:
	int m_Level;
	float m_Error;
	float m_SNR;
	int m_FilterCheck;

	afx_msg void OnClickedButtonUpdate();

	afx_msg void OnClickedButtonArrange();

	afx_msg void OnClickedButtonEnd();

};

