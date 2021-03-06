## Module11 . RNN 

### 01. 자연어 처리 소개 

---

##### 자연어 처리란? 

* 자연어(Natural Language): 사람들의 사회생활에서 자연스럽게 발생하여 쓰이는 언어 
  
  * 컴퓨터에게 명령을 하기 위해 정제한 단어들과 반대되는 의미로 쓰인다. 
  
* **자연어 처리(Natural Language process ; NLP): 자연어를 그대로 컴퓨터로 처리하는 학문 분야**
  * 언어학적 측면: 언어의 규칙성이나 변화 양상 등을 파악한다. 
  * 전산학적 측면: 자연어를 입출력으로 사용하는 컴퓨터 프로그램에 사용되는 처리과정 
  
 ![image-20210624233004315](https://user-images.githubusercontent.com/82528589/123282272-4f9bc380-d545-11eb-861e-74acd47fae47.png)
  
  
  
  
  
  * 자연어 이해(Natural Language understanding , NLU) : 사람이 이해하는 자연어를 컴퓨터가 이해할 수 있는 값으로 바꾸는 과정이다. 
  * 자연어 생성(Natural Language generation, NLG): 컴퓨터가 이해할 수 있는 값을 사람이 이해하도록 바꾸는 과정 이다.( 컴퓨터가 이해하는 것은 숫자바께 없다. )



##### 자연어 처리의 응용 분야 

* 언어학적인 활용: 전산 언어학에서 언어를 분석하는데 사용 
* 전산학적인 활용: 
  - 기계번역(NLP의 꽃이라 할 수 있다. 소스텍스트 -> 타겟 텍스트 )
  - 음성인식
  - 개인비서 서비스
  - 날씨 정보 요약
  - 인공지능 스피커
* 자연어 처리의 연구 분야 

![image-20210624201214717](https://user-images.githubusercontent.com/82528589/123282315-56c2d180-d545-11eb-89bd-0d4312988eeb.png)

---

### 02. 자연어 처리가 어려운 이유

* 많이 알려진것에 비해 정확도가 크게 높지 않다. 

  * 번역기가 많이 사용되어도 전적으로 번역기에만 의지하지는 않는다.

  * 개인 비서 서비스도 원하지 않는 응답을 많이 하여 사용률이 높지 않다. 

    

* 자연어는 숫자와 다르다.

  * 숫자는 누가 보아도 항상 같은 상태를 가리킨다.

  * 언어의 특징 때문에 자연어 처리는 복잡하고 불확실하다. 

    

* 자연어 처리를 어렵게 하는 다섯가지 요인

  1. 언어의 중의성
  2.  규칙의 예외
  3. 언어의 유연성과 확장성
  4. 바꾸어 말하기
  5. 단어 간 유사도 측정



##### 단어 간 유사도 측정

* 이산적인 값을 갖는 자연어는 사람 입장에서 인지가 쉬울 수 있지만 기계 입장에서 매우 어려운 값
* One-Hot 인코딩으로 표현된 값은 유사도나 모호성을 표현하지 못한다. 
  * 서로 다른 one-hot 벡터끼리 유사도 및 거리는 모두 동일
  * 사람의 언어 체계는 계층적 구조를 가짐
* 높은 차원으로 표현되어 sparse vector 가 됨
* 딥러닝에서는 단어 임베딩(word embedding)을 통해 해결 
![image-20210624233614091](https://user-images.githubusercontent.com/82528589/123282341-5de9df80-d545-11eb-9754-c781c56550a4.png)



---

### 03. 한국어 자연어 처리가 어려운 이유 

1. 교착어: 어근과 접사에 의해 단어의 기능이 결정되는 언어의 형태 

* 형태론적 관점의 언어 분류 

  

| 종류   | 대표 언어                 | 특징                                                         |
| ------ | ------------------------- | ------------------------------------------------------------ |
| 교착어 | 한국어, 일본어, 몽골어    | 어간에 접사가 붙어 단어를 이루고 의미와 문법적 기능이 정해짐 |
| 굴절어 | 라틴어, 독일어 , 러시아어 | 단어의 형태가 변함으로써 문법적 기능이 정해짐                |
| 고립어 | 영어, 중국어              | 어순에 따라 단어의 문법적 기능이 정해짐                      |



2. 모호한 띄어쓰기 
   - 우리말은 아직 띄어쓰기 정착 단계 
   - 띄어쓰기는 어느 정도 틀려도 의사소통에 문제가 없기 때문 
3. 평서문과 의문문의 차이 부재 & 주어 부재

    - 영어는 문법이 있어서 표현이 아예 달라 인식하기 쉽지만, 한국어는 어려움

![image-20210624221649075](https://user-images.githubusercontent.com/82528589/123282372-6510ed80-d545-11eb-8101-e42deb5260ad.png)

4. 한자 기반의 언어 & 단어 중의성 
  - 한자(표의 문자) -> 한글(표음 문자) 로 감싸 안음 (wrapping)
  -  표의 문자: 의미 또는 사물의 형상을 글씨로 표현
  -  표음 문자: 사람이 말하는 음성 , 소리를 글씨로 표현 
  -  다른 문자에 비해 한글 체계는 늦게 만들어짐
  -  효율성을 극대화했기 때문에 한국어 자연어처리는 더욱 



---

### 04. 자연어처리 연구의 패러다임

##### 1. 규칙 기반

* 언어의 문법적 규칙을 사전에 정의하고 이에 기반하여 자연어를 처리 

* 초창기의 자연어 처리 연구에 많이 사용됨

  * 1954년: 영어- 러시아어 번역기
  * 1960년: 대화형 시스템(SHRDLU ELIZA)

* 규칙 기반 자연어처리 예시

  * 기계 번역: 형태소 등의 단위로 문장을 분해하고, 그 사이에서 찾아낸 규칙을 사용하여 번역
  * 명령 인식: 목적어와 동사 등이 문장에서 위치하는 규칙을 이용하여 대상과 행동 등을 이해 

* 뚜렷한 한계가 존재하여 더 이상 사용되지 않음

  * 어순이 정형화되어 있지 않은 언어라면(한국어), 분석의 한계가 있음
  * 규칙을 미리 지정하는 것이 큰 부담
  * 규칙을 적용할 단위로 분해하는 작업의 정확도가 낮음 

  

##### 2. 통계 기반

* 규칙 사전 정의를 통계적으로 처리 
  * 어떤 규칙이 언어에 있다면 어구나 단어 사이에 통계적으로 유의미한 값이 도출된다고 가정 
*  컴퓨터 성능이 발전하여 대량 데이터를 빨리 처리할 수 있게 되면서 발전함
  * 통계적 분석을 위해서는 사전에 수집된 대량의 문장들(코퍼스)을  처리해야 함 
*  **조건부 확률이라는 수학 개념이 가장 핵심** 
  - 어떤 사건이 이미 일어난 것을 가정하고, 그 상황에서 다른 사건이 일어날 확률
  - 어떤 단어가 나타날 확률을 앞뒤의 단어들을 기반으로 계산 하는 것 
* 통계 기반 분석의 한계 
  * 복잡한 규칙을 처리하기 어려움
  * 여전히 사람 손이 많이 가는 통계 분석 자료를 활용함 



##### 3. 딥러닝 기반

* 알고리즘(Algorithm)
  * (일반적인)알고리즘: 어떤 상황에서 어떻게 어떤 값을 계산해야 하는지를 사전에 지정한 연산의 흐름
  * 어떤 데이터가 들어올 지 예측이 가능해야 하고 , 개발자 역시 그 처리법을 명확히 알고 있어야 함
* 기계학습(Machine Learning)
  * 입력으로 들어올 데이터를 대입하여 알고리즘이 스스로 연산의 가중치를 학습하게 함
  * 프로그램 작성 후 바로 사용하지 않고 학습하는 과정이필요(train & inference)
  * 학습 완료된 가중치는 저장 후 나중에 다시 활용 가능
* 신경망(Neural network)
  * 기계 학습 종류의 일종으로 신경계 구성 형태를 모티브로 만든 구조
  * 여러 입력에 가중치를 곱하여 합하고, 활성 함수에 통과한 후 전달
  * 입력, 출력을 제외한 층을 은닉층이라고 함 
* 딥러닝
  * 신경망 구조의 은닉층 수를 매우 많이 추가한 것
  * 은닉층 개수에 대한 정해진 기준은 없지만, 연산의 가중치나 흐름이 무엇을 의미하는 지 개발자조차 알 수 없음
  * 하지만 여러 복잡한 특징을 처리하게 되어 각광받는 중 
* 딥러닝 기반 자연어 처리
  * 모델을 구성하는 것이 중요함
  * 문장 전체를 고려하는 모델을 만들고 싶다면, 모든 단어에 적용되는 연결을 하나 만듦
  * 통계적 분석에 비해 고차원적인 분석이 가능해 자연어처리의 성능이 비약적으로 상승함 

---

### 05. 딥러닝을 사용하는 자연어처리 연구

##### 1. 딥러닝을 사용하는 자연어 처리의 연구 순서

1. 어떤 목적으로 자연어처리를 도입하는 것인지 결정(Task)
2. 목적과 관련한 코퍼스(자료) 구축 (Data collection, preprocessing)
3. 코퍼스로 학습할 모델 구조 작성(Design)
4. 준비된 코퍼스를 이용해 모델 학습 (Train)
5. 완성된 모델을 검증하고 실전에 투입(Inference)

* 주로 2,3 단계에서 성능 개선 진행됨 



##### 2. 단어 임베딩(word embedding)

* 자연어로 이루어진 문장을 컴퓨터가 입력 받을 수 있도록 하는 문장의 전처리 과정(모델의 일부)
* 다양한 방법이 존재하나, 단어간 연관성 등을 유지하는 벡터화 방법이 많이 쓰임
* 문법적으로만 사용되는 단어는 (조사, be 동사 등) 일반적으로 삭제 
* 사전에 임베딩된 단어 사전을 사용하여 연구를 진행하는 경우가 많음 

![image-20210624225044550](https://user-images.githubusercontent.com/82528589/123282395-6cd09200-d545-11eb-93a5-62c1d16f9cfd.png)

##### 3. 코퍼스 , 모델

* 코퍼스(Corpus)

  * 매우 많은 문장을 정제하여 모은 것
  * Corpora(복수형)
  * 통계기반 & 딥러닝 기반 자연어처리에 가장 핵심인 자료
  * 연구 필요성에 따라 문장 성분을 문장에 기입하거나 대응되는 번역문과 쌍을 구성하는 등, 연구에 사용할(모델이 학습해야 할) 정보를 함께 기입
  * 포함된 언어 숫자에 따라 
  * Parallel corpus: 대응되는 문장 쌍이 labeling 되어 있는 형태 

* 모델 (Model)

  * 딥러닝 기반 연구의 핵심
  * 연구의 목적에 맞게 모델이 어떤 부분을 읽고, 어떤 형식으로 출력하는 지 결정
  * 감정분석인 경우 분류(classification)모델, 번역인 경우 생성 (generation)모델 등 
  * 성능이 매우 좋은 모델은 출력 부분에 변화를 주어 다른 작업에 사용되기도 함 

  ---

  ### 06. 딥러닝을 사용하는 다른 연구 분야와 자연어 처리 비교 

  ##### 1. 자연어 처리 vs 이외분야 

| 자연어 처리                                                  | 다른 분야(ex> 컴퓨터 비전 )                           |
| ------------------------------------------------------------ | ----------------------------------------------------- |
| - 이산적인 값을 다룸 (단어 , 문장)                           | - 연속적인 값을 다룸(영상, 음성)                      |
| - 분류 문제로 접근 가능 p(x=단어)                            | - 문제에 따라 접근 방식이 다름                        |
| - 샘플의 확률 값을 구할 수 있음 P(X= 단어)                   | - 샘플의 확률 값을 구할 수 없음 P(X=영상)             |
| -문장 생성(자연어 생성)(Auto-regressive 속성 지님/ GAN 적용불가) | - 영상 생성(Auto-regressive 속성없음/ GAN 적용 가능 ) |

##### 2. 자연어처리의 필수 조건

* 언어적 지식 필요 (Domain Knowledge)
  * ex> 한국어의 언어적 특성은 무엇인가? 
* 어려운 전처리 과정 
  * 문제에 따른 정제 과정 필요 
