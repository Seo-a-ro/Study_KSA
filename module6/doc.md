# KSA_Module6_CNN
### Pycharm 설치
### 아나콘다 prompt에서 가상환경 설정하기 
* codna info --envs  // 가상환경 목록 보기
* codna create -n [가상환경명] python =3.7 // 가상환경 방 만들기 
* activate Module6 //가상환경 활성화
* conda install tensorflow=2.1
* pip install matplotlib //matplotlib 패키지 설치
* conda remove -n[가상환경명] --all // 가상환경 지우기 
* conda isntall tensorflow=2.1 -> tensorflow 2.1 버전 (cpu)설치 
* conda list // 패키지 설치 한 list 보기 
* pip freeze // pip 로 설치한 패키지 list 보기 

### 딥러닝 작업 순서(general)
* 1. 데이터 전처리
* 2. 네트워크 정리
* 3. 손실함수, 옵티마이저, 성능 지표 지정
* 4. 모델 학습
* 5. 모델 평가 및 분석

### Mnist DNN(심층신경망) 모델 설계 및 컴파일
![layer_dnn](https://user-images.githubusercontent.com/82528589/118530578-c512b800-b77f-11eb-91a3-065e9cd3f95c.PNG)


### DNN 모델 성능평가
![dnn_loss_acc](https://user-images.githubusercontent.com/82528589/118530256-68170200-b77f-11eb-97b2-5b10ec489fbb.PNG)


### Mnist DNN 학습 모델 그래프
![loss_dnn](https://user-images.githubusercontent.com/82528589/118530641-d8258800-b77f-11eb-8be1-5c4afed04fdb.PNG)
![acc_dnn이게원본](https://user-images.githubusercontent.com/82528589/118530698-e8d5fe00-b77f-11eb-8270-cff6bbca1dab.PNG)


### CNN 모델 성능평가
![cnn_acc](https://user-images.githubusercontent.com/82528589/118530755-f7bcb080-b77f-11eb-8938-af1f24923e28.PNG)


### Mnist CNN 학습 모델 그래프 
![손실함수](https://user-images.githubusercontent.com/82528589/118530990-466a4a80-b780-11eb-9e86-37e626ca74e1.PNG)
![정확도](https://user-images.githubusercontent.com/82528589/118531044-55e99380-b780-11eb-9065-eaa04320e47d.PNG)


