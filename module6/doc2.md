# KSA_Module6_CNN_day2


### 딥러닝 작업 순서(general)
* 1. 데이터 전처리
* 2. 네트워크 정리
* 3. 손실함수, 옵티마이저, 성능 지표 지정
* 4. 모델 학습
* 5. 모델 평가 및 분석


### iris data 모델설계
![image](https://user-images.githubusercontent.com/82528589/118652517-a664fd80-b821-11eb-8b0b-f181d6a43d73.png)



### iris data 모델 성능평가
![image](https://user-images.githubusercontent.com/82528589/118652702-d14f5180-b821-11eb-861d-1d64b1d189dd.png)



### iris data학습 모델 그래프
![image](https://user-images.githubusercontent.com/82528589/118652610-bb419100-b821-11eb-94bf-e07e9ed3bde5.png)



## 배치정규화
* 장점
* 1. 학습을 빨리 진행할 수 있다.(학습 속도 개선)
* 2. 초깃값에 크게 의존하지 않는다.
* 3. 오버피팅을 억제한다(드롭아웃의 필요성 감소)



### 배치정규화 모델 성능평가
![image](https://user-images.githubusercontent.com/82528589/118658093-0d38e580-b827-11eb-80ad-4c456c13d84d.png)



### 배치정규화 실행 모델 그래프
![image](https://user-images.githubusercontent.com/82528589/118657859-cfd45800-b826-11eb-98ee-6ad5f102b57d.png)
![image](https://user-images.githubusercontent.com/82528589/118657918-dcf14700-b826-11eb-9212-9ba6e709473f.png)



## 드롭아웃 
* 드롭아웃은 뉴런을 임의로 삭제하면서 학습하는 방법
* 훈련 때 은닉층의 뉴런을 무작위로 골라 삭제
* 훈련 때는 데이터를 흘릴 대마다 삭제할 뉴런을 무작위로 선택 후, 시험 때는 모든 뉴런에 신호 전달 



![image](https://user-images.githubusercontent.com/82528589/118655788-d5c93980-b824-11eb-904d-9891682af06e.png)



### 드롭아웃 모델 성능평가
![image](https://user-images.githubusercontent.com/82528589/118659660-7b31dc80-b828-11eb-9521-5c9b174cf73c.png)



### 드롭아웃 실행 모델 그래프 
![image](https://user-images.githubusercontent.com/82528589/118659557-65241c00-b828-11eb-8e9c-c83a892cc1aa.png)
![image](https://user-images.githubusercontent.com/82528589/118659618-6fdeb100-b828-11eb-913e-9b973685dd45.png)



### CIFAR-10 DNN 모델설계
![image](https://user-images.githubusercontent.com/82528589/118661353-fe9ffd80-b829-11eb-9846-0ea734a03cff.png)



### CIFAR-10 DNN 모델 성능평가
![image](https://user-images.githubusercontent.com/82528589/118661555-2d1dd880-b82a-11eb-8d96-891dde764ede.png)



## CIFAR-10 DNN 학습 모델 그래프 
![image](https://user-images.githubusercontent.com/82528589/118661607-3c048b00-b82a-11eb-9976-c2628accb6b8.png)
![image](https://user-images.githubusercontent.com/82528589/118661731-5a6a8680-b82a-11eb-8472-f105557c8761.png)



### CIFAR-10 CNN 모델설계
![image](https://user-images.githubusercontent.com/82528589/118654974-11173880-b824-11eb-95f7-78c3c790bfd7.png)



### CIFAR-10 CNN 모델 성능평가
![image](https://user-images.githubusercontent.com/82528589/118654879-fb097800-b823-11eb-98ea-41bb4f32e97e.png)



## CIFAR-10 CNN 학습 모델 그래프 
![image](https://user-images.githubusercontent.com/82528589/118654833-ee851f80-b823-11eb-96ec-df7768e91323.png)


### Argumentation 
![image](https://user-images.githubusercontent.com/82528589/118662192-c816b280-b82a-11eb-8de4-bf10c42ad71d.png)
![image](https://user-images.githubusercontent.com/82528589/118662245-d238b100-b82a-11eb-9998-158f1673251b.png)

