## KSA_Module6_CNN_day5

### Architecture

#### AlexNet

ILSVRC(ImageNet Large-Scale Visual Recognition Challenge)의 2012년 대회에서 제프리 힌튼 교수팀의 AlexNet이 top5 test error 기준 15.4%를 기록해 2위(26.2%)를 큰 폭으로 따돌리고 1위를 차지함. top5 test error란 모델이 예측한 최상위 5개 범주 가운데 정답이 없는 경우의 오류율을 나타냄.

* AlexNet 아키텍처의 주요 특징

  ![img](https://i.imgur.com/CwIvlUW.png)

  - conv layer, max-pooling layer, dropout layer 5개
  - fully connected layer 3개
  - nonlinearity function : ReLU
  - batch stochastic gradient descent

#### ResNet

ResNet은 2015년 ILSVRC에서 오류율 3.6%로 1등을 차지함.

층이 깊어질 수록 역전파되는 gradient가 중간에 죽어서 학습이 잘 되지 않는 문제 (gradient vanishing)가 발생함. 

![image-20210524205105446](C:\Users\aro\AppData\Roaming\Typora\typora-user-images\image-20210524205105446.png)

이러한 문제를 해결하기 위해서 스킵 연결을 시도함. 이 구조가 층의 깊이에 비례해 성능을 향상시킬 수 있게 한 핵심임.(하지만 층을 깊게 하는 데는 여전히 한계가 있음)  스킵연결이란 입력 데이터를 합성곱 계층을 건너뛰어 출력에 바로 더하는 구조를 말함.  스킵 연결은 층이 깊어져도 학습을 효율적으로 할 수 있도록 해주는데, 이는 역전파 때 스킵 연결이 신호 감쇠를 막아주기 때문임.

![img](https://i.imgur.com/fse3Ntq.png)



#### VGGNet

VGG는 합성곱 계층과 풀링 계층으로 구성된 기본적인 CNN.

층의 깊이에 따라서 'VGG16' 과 'VGG19'로 구분함.

VGG는 3X3의 작은 필터를 사용한 합성곱 계층을 연속으로 거친다는 것임. 합성곱 계층을 2~4회 연속으로 풀링 계층을 두어 크기를 절바능로 줄이는 처리를 반복함. 그리고 마지막에는 완전 연결 계층을 통과시켜 결과를 출력함.

![image-20210524205008199](C:\Users\aro\AppData\Roaming\Typora\typora-user-images\image-20210524205008199.png)



#### DenseNet

 ResNet에서 한발 더 나아가 전체 네트워크의 모든 층과 통하는 지름길을 만들었음.

![img](https://i.imgur.com/EITg2BX.png)





