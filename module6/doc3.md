# KSA_Module6_CNN_day3

## cat & dog classification (개와 고양이 분류 실습) 
## 데이터 전처리 & Augmentation
### augmentation

* 모델이 적은 이미지에서 최대한 많은 정보를 뽑아내서 학습 할 수 있도록 우선 이미지를 증대시키는 방법. 
* 이미지를 사용할 때 마다 임의의 변형을 가함으로써 훨씬 더 많은 이미지를 보고 공부하는 것과 같은 학습 효과를 낼 수 있음.
* agumentation을 통해 과적합(overfitting)되는 것을 방지하고 새로운 이미지도 잘 분류할 수 있게 도움을 줌 
* ImageDataGenerator 클래스를 이용 
* generator 생성할 때 flow(data, label) , flow_from_directory(directory) 두가지 함수 사용
* fit_generator, evaluate_generator 함수를 이용하여 generator로 이미지를 불러와서 모델을 학습 시킴 

### augmentation 옵션 
* rotation_range: 이미지 회전 범위 (degrees)
* width_shift, height_shift: 그림을 수평 또는 수직으로 랜덤하게 평행 이동시키는 범위 (원본 가로, 세로 길이에 대한 비율 값)
* rescale: 원본 영상은 0-255의 RGB 계수로 구성되는데, 이 같은 입력값은 모델을 효과적으로 학습시키기에 너무 높습니다 (통상적인 learning rate를 사용할 경우). 그래서 이를 1/255로 스케일링하여 0-1 범위로 변환시켜줍니다. 이는 다른 전처리 과정에 앞서 가장 먼저 적용됩니다.
* shear_range: 임의 전단 변환 (shearing transformation) 범위
* zoom_range: 임의 확대/축소 범위
* horizontal_flip: True로 설정할 경우, 50% 확률로 이미지를 수평으로 뒤집습니다. 원본 이미지에 수평 비대칭성이 없을 때 효과적입니다. 즉, 뒤집어도 자연스러울 때 사용하면 좋습니다.
* fill_mode 이미지를 회전, 이동하거나 축소할 때 생기는 공간을 채우는 방식

![image](https://user-images.githubusercontent.com/82528589/119216583-706c9580-bb0f-11eb-8680-b85fd41425ea.png)

### data preprocessiong
* test, train 데이터로만 나뉘어있는 파일을 코드를 이용하여 train 데이터를 train 과 validation으로 나눔 

![image](https://user-images.githubusercontent.com/82528589/119216774-9e060e80-bb10-11eb-9cb8-90a739825d42.png)
![image](https://user-images.githubusercontent.com/82528589/119216790-b70ebf80-bb10-11eb-90f6-9c41bfb6724e.png)

## 사용한 모델 
![image](https://user-images.githubusercontent.com/82528589/119217081-b9721900-bb12-11eb-9e1d-4fd380e385cb.png)

## TEST 예측 
![image](https://user-images.githubusercontent.com/82528589/119217061-a52e1c00-bb12-11eb-8477-fc5058a041bd.png)

