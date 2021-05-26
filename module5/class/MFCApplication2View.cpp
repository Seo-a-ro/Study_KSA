
// MFCApplication2View.cpp: CMFCApplication2View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DOWN_SAMPLING, &CMFCApplication2View::OnDownSampling)
//	ON_COMMAND(ID_UP_SAMPLING, &CMFCApplication2View::OnUpSampling)
//ON_COMMAND(ID_UP_SAMPLING, &CMFCApplication2View::OnUpSampling)
ON_COMMAND(ID_UP_SAMPLING, &CMFCApplication2View::OnUpSampling)
ON_COMMAND(ID_QUANTIZATION, &CMFCApplication2View::OnQuantization)
ON_COMMAND(ID_SUM_CONSTANT, &CMFCApplication2View::OnSumConstant)
ON_COMMAND(ID_SUB_CONSTANT, &CMFCApplication2View::OnSubConstant)
ON_COMMAND(ID_MUL_CONSTANT, &CMFCApplication2View::OnMulConstant)
ON_COMMAND(ID_DIV_CONSTANT, &CMFCApplication2View::OnDivConstant)
ON_COMMAND(ID_AND_OPERATE, &CMFCApplication2View::OnAndOperate)
ON_COMMAND(ID_OR_OPERATE, &CMFCApplication2View::OnOrOperate)
ON_COMMAND(ID_XOR_OPERATE, &CMFCApplication2View::OnXorOperate)
ON_COMMAND(ID_NEGA_TRANSFORM, &CMFCApplication2View::OnNegaTransform)
ON_COMMAND(ID_GAMMA_CORRECTION, &CMFCApplication2View::OnGammaCorrection)
ON_COMMAND(ID_BINARIZATION, &CMFCApplication2View::OnBinarization)
ON_COMMAND(ID_STRESS_TRANSFORM, &CMFCApplication2View::OnStressTransform)
ON_COMMAND(ID_HISTO_STRETCH, &CMFCApplication2View::OnHistoStretch)
ON_COMMAND(ID_END_IN_SEARCH, &CMFCApplication2View::OnEndInSearch)
ON_COMMAND(ID_HISTOGRAM, &CMFCApplication2View::OnHistogram)
ON_COMMAND(ID_HISTO_EQUAL, &CMFCApplication2View::OnHistoEqual)
ON_COMMAND(ID_HISTO_SPEC, &CMFCApplication2View::OnHistoSpec)
ON_COMMAND(ID_EMBOSSING, &CMFCApplication2View::OnEmbossing)
ON_COMMAND(ID_BLURR, &CMFCApplication2View::OnBlurr)
ON_COMMAND(ID_HPF_SHARPNING, &CMFCApplication2View::OnHpfSharpning)
ON_COMMAND(ID_LPF_SHARPNING, &CMFCApplication2View::OnLpfSharpning)
ON_COMMAND(ID_SHARPNING, &CMFCApplication2View::OnSharpning)
ON_COMMAND(ID_GAUSSIAN_FILTER, &CMFCApplication2View::OnGaussianFilter)
ON_COMMAND(ID_LAPLACIAN, &CMFCApplication2View::OnLaplacian)
ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CMFCApplication2View::OnDiffOperatorHor)
ON_COMMAND(ID_HOMOGEN_OPERATOR, &CMFCApplication2View::OnHomogenOperator)
ON_COMMAND(ID_NEAREST, &CMFCApplication2View::OnNearest)
ON_COMMAND(ID_BILINEAR, &CMFCApplication2View::OnBilinear)
ON_COMMAND(ID_MEDIAN_SUB, &CMFCApplication2View::OnMedianSub)
ON_COMMAND(ID_MEAN_SUB, &CMFCApplication2View::OnMeanSub)
ON_COMMAND(ID_TRANSLATION, &CMFCApplication2View::OnTranslation)
ON_COMMAND(ID_MIRROR_HOR, &CMFCApplication2View::OnMirrorHor)
ON_COMMAND(ID_MIRROR_VER, &CMFCApplication2View::OnMirrorVer)
ON_COMMAND(ID_ROTATION, &CMFCApplication2View::OnRotation)
ON_COMMAND(ID_FRAME_SUM, &CMFCApplication2View::OnFrameSum)
ON_COMMAND(ID_FRAME_SUB, &CMFCApplication2View::OnFrameSub)
ON_COMMAND(ID_FRAME_MUL, &CMFCApplication2View::OnFrameMul)
ON_COMMAND(ID_FRAME_DIV, &CMFCApplication2View::OnFrameDiv)
ON_COMMAND(ID_FRAME_AND, &CMFCApplication2View::OnFrameAnd)
ON_COMMAND(ID_FRAME_OR, &CMFCApplication2View::OnFrameOr)
ON_COMMAND(ID_FRAME_COMB, &CMFCApplication2View::OnFrameComb)
ON_COMMAND(ID_BINARY_DILATION, &CMFCApplication2View::OnBinaryDilation)
ON_COMMAND(ID_BINARY_EROSION, &CMFCApplication2View::OnBinaryErosion)
ON_COMMAND(ID_GRAY_DILATION, &CMFCApplication2View::OnGrayDilation)
ON_COMMAND(ID_GRAY_EROSION, &CMFCApplication2View::OnGrayErosion)
ON_COMMAND(ID_HIGH_PASS_FILTER, &CMFCApplication2View::OnHighPassFilter)
ON_COMMAND(ID_LOW_PASS_FILTER, &CMFCApplication2View::OnLowPassFilter)
ON_COMMAND(ID_MAX_FILTER, &CMFCApplication2View::OnMaxFilter)
ON_COMMAND(ID_MEAN_FILTER, &CMFCApplication2View::OnMeanFilter)
ON_COMMAND(ID_MEDIAN_FILTER, &CMFCApplication2View::OnMedianFilter)
ON_COMMAND(ID_MIN_FILTER, &CMFCApplication2View::OnMinFilter)
ON_COMMAND(ID_FFT_2D, &CMFCApplication2View::OnFft2d)
//ON_COMMAND(ID_IFFT_2D, &CMFCApplication2View::OnIfft2d)
ON_COMMAND(ID_OnHpfFrequency, &CMFCApplication2View::OnOnhpffrequency)
ON_COMMAND(ID_OnLpfFrequency, &CMFCApplication2View::OnOnlpffrequency)
ON_COMMAND(ID_IFFT_2D, &CMFCApplication2View::OnIfft2d)
END_MESSAGE_MAP()

// CMFCApplication2View 생성/소멸

CMFCApplication2View::CMFCApplication2View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View 그리기

void CMFCApplication2View::OnDraw(CDC* pDC)
{
	CMFCApplication2Doc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc);
	int i, j;
	unsigned char R, G, B;

	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++) {
			R = G = B = pDoc->m_InputImage[i * pDoc->m_width + j];
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));

		}
	}
	// 축소된 영상 출력
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i * pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}

	

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCApplication2View 인쇄


void CMFCApplication2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplication2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFCApplication2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication2View 진단

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View 메시지 처리기


  void CMFCApplication2View::OnDownSampling()
{
	// TODO: Add your command handler code here
   CMFCApplication2Doc* pDoc = GetDocument(); // Doc 클래스 참조
   ASSERT_VALID(pDoc);

   pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출

   Invalidate(TRUE); // 화면 갱신
	
}



  void CMFCApplication2View::OnUpSampling()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	   // TODO: Add your command handler code here
	  CMFCApplication2Doc* pDoc = GetDocument(); // Doc 클래스 참조
	  ASSERT_VALID(pDoc);

	  pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출

	  Invalidate(TRUE); // 화면 갱신

  }




  void CMFCApplication2View::OnQuantization()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.

	  // TODO: 여기에 구현 코드 추가.
	  // TODO: Add your command handler code here
	  CMFCApplication2Doc* pDoc = GetDocument(); // Doc 클래스 참조
	  ASSERT_VALID(pDoc);

	  pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출

	  Invalidate(TRUE); // 화면 갱신
  }




  void CMFCApplication2View::OnSumConstant()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.

	  // TODO: 여기에 구현 코드 추가.
		 // TODO: Add your command handler code here
	  CMFCApplication2Doc* pDoc = GetDocument();
	  // 도큐먼트 클래스 참조
	  ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	  pDoc->OnSumConstant();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnSubConstant()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
		 // TODO: Add your command handler code here
	  CMFCApplication2Doc* pDoc = GetDocument();// 도큐먼트 클래스 참조
	  ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	  pDoc->OnSubConstant();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnMulConstant()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	  ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	  pDoc->OnMulConstant();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnDivConstant()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.

      // TODO: Add your command handler code here
	  CMFCApplication2Doc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	  ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	  pDoc->OnDivConstant();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnAndOperate()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnAndOperate();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnOrOperate()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  // TODO: Add your command handler code here
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnOrOperate();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnXorOperate()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  // TODO: Add your command handler code here
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);
	  pDoc->OnXorOperate();
	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnNegaTransform()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  // TODO: Add your command handler code here
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnNegaTransform();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnGammaCorrection()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  // TODO: Add your command handler code here
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnGammaCorrection();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnBinarization()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  // TODO: Add your command handler code here
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnBinarization();

	  Invalidate(TRUE);

  }



  void CMFCApplication2View::OnStressTransform()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnStressTransform();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnHistoStretch()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnHistoStretch();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnEndInSearch()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.

	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnEndInSearch();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnHistogram()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnHistogram();
	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnHistoEqual()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.

	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnHistoEqual();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnHistoSpec()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnHistoSpec();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnEmbossing()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnEmbossing();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnBlurr()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnBlurr();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnHpfSharpning()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnHpfSharpning();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnLpfSharpning()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnLpfSharpning();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnSharpning()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnSharpning();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnGaussianFilter()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnGaussianFilter();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnLaplacian()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnLaplacian();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnDiffOperatorHor()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnDiffOperatorHor();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnHomogenOperator()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnHomogenOperator();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnNearest()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnNearest();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnBilinear()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnBilinear();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnMedianSub()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnMedianSub();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnMeanSub()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnMeanSub();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnTranslation()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnTranslation();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnMirrorHor()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnMirrorHor();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnMirrorVer()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnMirrorVer();

	  Invalidate(TRUE);

  }


  void CMFCApplication2View::OnRotation()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnRotation();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnFrameSum()
  {
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnFrameSum();

	  Invalidate(TRUE);
	 
  }

  


  void CMFCApplication2View::OnFrameSub()
  {
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnFrameSub();

	  Invalidate(TRUE);

	 
  }




  void CMFCApplication2View::OnFrameMul()
  {
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnFrameMul();

	  Invalidate(TRUE);

	
  }



  


  void CMFCApplication2View::OnFrameDiv()
  {
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnFrameDiv();

	  Invalidate(TRUE);
  }
  


  void CMFCApplication2View::OnFrameAnd()
  {
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnFrameAnd();

	  Invalidate(TRUE);
  }
  

  


  void CMFCApplication2View::OnFrameOr()
  {
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnFrameOr();

	  Invalidate(TRUE);
  }

  


  void CMFCApplication2View::OnFrameComb()
  {
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnFrameComb();

	  Invalidate(TRUE);
  }

  


  void CMFCApplication2View::OnBinaryDilation()
  {
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnBinaryDilation();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnBinaryErosion()
  {
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnBinaryErosion();

	  Invalidate(TRUE);
}


  void CMFCApplication2View::OnGrayDilation()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnGrayDilation();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnGrayErosion()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.

	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnGrayErosion();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnHighPassFilter()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnHighPassFilter();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnLowPassFilter()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnLowPassFilter();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnMaxFilter()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnMaxFilter();

	  Invalidate(TRUE);
  }
  


  void CMFCApplication2View::OnMeanFilter()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnMeanFilter();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnMedianFilter()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnMedianFilter();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnMinFilter()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnMinFilter();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnFft2d()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnFft2d();

	  Invalidate(TRUE);
  }


  

  

  



  void CMFCApplication2View::OnOnhpffrequency()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	   // TODO: 여기에 구현 코드 추가.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnOnhpffrequency();

	  Invalidate(TRUE);
  }


  void CMFCApplication2View::OnOnlpffrequency()
  {
	  // TODO: 여기에 구현 코드 추가.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnOnlpffrequency();

	  Invalidate(TRUE);
	  
  }
 


  void CMFCApplication2View::OnIfft2d()
  {
	  // TODO: 여기에 명령 처리기 코드를 추가합니다.
	  CMFCApplication2Doc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  pDoc->OnIfft2d();

	  Invalidate(TRUE);
  }
