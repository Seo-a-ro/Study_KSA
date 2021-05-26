
// MFCApplication2Doc.h: CMFCApplication2Doc 클래스의 인터페이스
//


#pragma once


class CMFCApplication2Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CMFCApplication2Doc() noexcept;
	DECLARE_DYNCREATE(CMFCApplication2Doc)

	// 특성입니다.
public:

	// 작업입니다.
public:

	// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	// 구현입니다.
public:
	virtual ~CMFCApplication2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	// 입력영상버퍼
	unsigned char* m_InputImage;
	int m_width;
	int m_height;
	int m_size;
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	void OnDownSampling();
	unsigned char* m_OutputImage;
	int m_Re_width;
	int m_Re_height;
	int m_Re_size;
	void OnUpSampling();
	//void OnQuantization();
	void OnQuantization();
	
	void OnSumConstant();
	void OnSubConstant();
	void OnMulConstant();
	void OnDivConstant();
	void OnAndOperate();
	void OnOrOperate();
	void OnXorOperate();
	void OnNegaTransform();
	void OnGammaCorrection();
	void OnBinarization();
	void OnStressTransform();
	void OnHistoStretch();
	void OnEndInSearch();
	afx_msg void OnHistogram();
	double m_HIST[256];
	double m_Sum_Of_HIST[256];
	unsigned char m_Scale_HIST[256];

	void OnHistoEqual();
	void OnHistoSpec();
    void OnEmbossing();
	double** OnMaskProcess(unsigned char* Target, double Mask[3][3]);
	double** OnScale(double** Target, int height, int width);
	double** Image2DMem(int height, int width);
	afx_msg void OnBlurr();
	afx_msg void OnHpfSharpning();
	afx_msg void OnLpfSharpning();
	afx_msg void OnSharpning();
	afx_msg void OnGaussianFilter();
	double** m_tempImage;
	afx_msg void OnLaplacian();
	afx_msg void OnDiffOperatorHor();
	afx_msg void OnHomogenOperator();
	afx_msg double DoubleABS(double X);
	afx_msg void OnNearest();
	afx_msg void OnBilinear();
	afx_msg void OnMedianSub();
//	void OnMeanSub();
	void OnBubleSort(double* A, int MAX);
	void OnSwap(double* a, double* b);

//	afx_msg void OnUpdateMeanSub(CCmdUI* pCmdUI);
	void OnMeanSub();
	void OnTranslation();
    void OnMirrorHor();
	void OnMirrorVer();
	void OnRotation();
	afx_msg void OnFrameSum();
	afx_msg void OnFrameSub();
	afx_msg void OnFrameMul();
	afx_msg void OnFrameDiv();
	afx_msg void OnFrameAnd();
	afx_msg void OnFrameOr();
	afx_msg void OnFrameComb();
	afx_msg void OnGrayDilation();
	afx_msg void OnGrayErosion();
	afx_msg void OnBinaryDilation();
	afx_msg void OnBinaryErosion();
	afx_msg void OnMaxFilter();
	afx_msg void OnMeanFilter();
	afx_msg void OnMinFilter();
	afx_msg void OnHighPassFilter();
	afx_msg void OnLowPassFilter();
	afx_msg void OnMedianFilter();
	afx_msg void OnFft2d();

	struct Complex {
		double Re;
		double Im;
	};

	void OnFft1d(Complex *X, int N, int Log2N);
	void OnShuffle(Complex *X, int N, int Log2N);
	void OnButterfly(Complex *X, int N, int Log2N, int mode);
	int OnReverseBitOrder(int index, int Log2N);
	Complex **m_FFT;

	afx_msg void OnIfft2d();
	void Onlfft1d(Complex* X, int N, int Log2N);
	Complex** m_lFFT;
	
	
	afx_msg void OnOnhpffrequency();
	afx_msg void OnOnlpffrequency();
};
