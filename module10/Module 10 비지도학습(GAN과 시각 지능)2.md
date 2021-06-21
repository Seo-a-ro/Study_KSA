## Module 10: 비지도학습(GAN과 시각 지능)2 

### 2. GAN의 발전 (1): DCGAN



#### 기존 GAN의 한계

1. GAN의 결과가 불안정하다(기존 GAN은 좋은 성능이 나오질 않았음)

2. Black-box method 

   -> Neural Network 자체의 한계라고 볼 수 있다. 

   -> Neural Network는 처음부터 끝까지 어떤 형태로 그러한 결과가 나오게 되었는지 과정을 알 수 없다.

3. Generative Model 평가

   -> GAN 자체가 얼마나 정확한지 , 뛰어나는지 판단하기 어렵다. 



#### DCGAN(Deep Convolutional GAN)의 기본 원리

1. CNN
2. Transposed Convolution

->  convolution과 반대로 이미지의 크기를 키우는 역할을 하는 연산이다.

> DCGAN = GAN + Convolutional Layer 



#### DCGAN의 목표

1. Generator 가 단순 기억으로 되어있지 않다는 것을 보여줘야한다.
2.  z의 미세한 변동에 따른 generate 결과가 연속적으로 부드럽게 이어져야한다(Walking in the latent space)



#### DCGAN의 Guideline

* Discriminator 에서는 모든 pooling layers 를 strided convolutions으로 바꾸고, Generator에서는 pooling layers를 fractional-strided convolutions로 바꾼다.
* Fully-connected hidden layers 를 삭제한다.
* Generator에서 모든 활성화 함수를 ReLU로 쓰되 , 마지막 결과에서만 Tanh 사용한다.
* Discriminator에서는 모든 활성화 함수를 LeakyReLU로 쓴다. 



#### Generator 의 구조

* Transposed Convolution 연산을 통해 이미지 사이즈가 점점 커지는 형태의 Neural Network를 얻을 수 있다. 



![image-20210617234921355](https://user-images.githubusercontent.com/82528589/122727398-f23c1400-d2b1-11eb-8b85-87d7dd1ba4d9.png)



#### Discriminator의 구조

*  Generator와 거의 완벽히 대칭을 이루는 CNN구조를 이용한다. 
* CNN과 다른 점은 Image Size 가 줄어드는 방식을 사용한다. 
* DCGAN의 Discriminator는 Filter의 stride를 1이 아닌 2로 하여 이미지 사이즈가 절반으로 줄어들게 만든다.



![image-20210617235234485](https://user-images.githubusercontent.com/82528589/122727430-f8ca8b80-d2b1-11eb-9f0a-5d87eb8f46ac.png)



![image-20210617235611935](https://user-images.githubusercontent.com/82528589/122727454-0253f380-d2b2-11eb-88f1-4c3e902c0b63.png)

* DCGAN(Deep Convolutional GAN,2015)는 CNN구조로 판별자 D와 생성자 G를 구성한 GAN이다.

* 판별자 D는 이미지(예 28x28x3)를 입력으로 받아 binary classification을 수행하므로 CNN구조를 사용 했다.
* 생성자 G는 random vector z(예 (100,1))를 입력으로 받아 이미지(28x28x3)을 생성해야므로 deconvolutional network구조를 갖게된다.
* 또한 pooling layer를 사용하지 않고 stride 2이상인 convolution,deconvolution을 사용하였다.
