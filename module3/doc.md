# Decision Tree Classifier 
* 의사결정 트리 분류기는 분류 및 회귀 분석에 사용되는 비모수 지도 학습 방법이다. 목표는 데이터 기능에서 유추된 간단한 의사 결정 규칙을 학습하여 대상 변수의 값을 예측하는 모델을 만드는 것이다. 

### 의사결정 트리의 장점
* 1.	이해하고 해석하는 것이 간단. 
* 2.	시각화 가능 
* 3.	수치 및 범주형 데이터를 모두 처리할 수 있음
* 4.	통계 테스트를 사용하여 모형 검증 가능

### 의사결정 트리의 단점 
* 1.	과적합 문제
* 2.	데이터의 작은 변화로 인해 완전히 다른 트리 생성 가능 -> 앙상블 내의 의사결정 트리 사용함으로써 완화
* 3.	Decision tree learners create biased trees if some classes dominate. It is therefore recommended to balance the dataset prior to fitting with the decision tree.

	의사결정 트리는 일부 계층이 많으면 편향된 트리 만들 수 있다. 따라서 의사결정 트리를 맞추기 전에 데이터 세트의 균형을 맞추는 것 권장 

# 앙상블 모델
* 1.	배깅: 분산을 최소화하는 것이 목표

* 2.	부스팅: 성능자체를 강화시키는 것이 목표
