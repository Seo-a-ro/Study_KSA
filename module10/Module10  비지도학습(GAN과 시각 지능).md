## Module10  비지도학습(GAN과 시각 지능)

### GAN의 기본: Vanilla GAN

#### GAN의 기본 원리

나의 행운은 적의 불행이요, 나의 불행은 적의 행운이다.  

#### GAN이란? 

* 'Generative Adversarial Netowork'의 약자이다. 

* Generative: 생성 (Generation)모델. 그럴듯한 가짜를 만들어내는 모델

* 생성 모델의 목적은 실제 데이터 분포와 근사한 것이라고 말할 수 있다. 

* Adversarial 은 GAN이 두 개의 모델을 적대적으로 경쟁시키며 발전시킨다는 뜻이다. EX> 위조지폐범과 경찰

* 생성자(Generator): 위조 지폐범 /  구분자(Discriminator): 경찰

* 생성자의 목적은 그럴듯한 가짜 데이터를 만들어서 구분자를 속이는 것이며, 구분자의 목적은 생성자가 만든 가짜 데이터와 진짜 데이터를 구분하는 것이다. 

* 이 둘을 함께 학습시키면서 진짜와 구분할 수 없는 가짜를 만들어내는 생성자를 얻을 수 있다 

  -> Adverarial Training (적대적 학습)

* 이미지의 크기가 256 x 256 픽셀이라면 RGB 컬러값까지 총 256 x 256 x 3개의 변수가 생긴다. 그 변수들의 어떤 조합은 사람 얼굴처럼 보이지만, 어떤 조합은 그렇지 않다. 얼굴 이미지의 생성 모델을 만들겠다는 것은 사람 얼굴처럼 보이는 픽셀값 조합의 분포를 찾아내겠다는 것이다. 

![image-20210616052550300](https://user-images.githubusercontent.com/82528589/122124370-28b8ff80-ce6a-11eb-963e-b3e9a7b25ac7.png)
G: 학습할 알고리즘 

θ_g: 알고리즘을 통해 나온 결과 data



#### 생성자 (Generator)

* Decoder와 유사한 구조
* 입력(latent vector)를 받아서 결과(synthesized image)를 생성하는 모듈
* Vanilla GAN에서는 convolution을 사용하지 않음 

![image-20210616053043388](https://user-images.githubusercontent.com/82528589/122124391-31a9d100-ce6a-11eb-915b-a6a3864a5ff9.png)



##### Generator 의 구조 (1) overall

* n개의 generator block으로 구성됨 (n=4)
* generator block은 낮은 해상도의 입력을 받아서 높은 해상도의 출력을 생성 

![image-20210616053247269](https://user-images.githubusercontent.com/82528589/122124452-42f2dd80-ce6a-11eb-9037-4e0de0e76edc.png)

##### Generator 의 구조 (2) generator block의 구조

* input_dim 과 output_dim을 파라미터로 받음
* linear layer 와 batch norm, ReLU함수로 구성 

```python
def gen_block(input_dim, output_dim):
    return nn.Sequential(
        nn.Linear(input_dim, output_dim),
        nn.BatchNorm1d(output_dim),
        nn.ReLU(inplace=True),
    )
```



##### Generator 의 구조 (3) generator 의 구조

* 4개의 generator block와 FC layer, sigmoid함수로 구성
* 28x28 해상도의 MNIST dataset 생성 

- 입력: z_dim =10
- 출력: im_dim =784 

```python
class Generator(nn.Module):
    def __init__(self, z_dim=10, im_dim=784, hidden_dim=128):
        super(Generator,self).__init__()
        #Build the neural network
        self.gen = nn.Sequential(
            gen_block(z_dim,hidden_dim),
            gen_block(hidden_dim,hidden_dim * 2),
            gen_block(hidden_dim * 2,hidden_dim * 4),
            gen_block(hidden_dim * 4,hidden_dim * 8),
            
            nn.Linear(hidden_dim *8, im_dim),
            nn.Sigmoid()
        )
```



#### 판별자 (discriminator)

* 입력(real data  or fake data)을 받아서 real/fake를 판정하는 모듈
* Classifier와 유사한 역할을 수행함 

![image-20210616053733403](https://user-images.githubusercontent.com/82528589/122124504-53a35380-ce6a-11eb-9790-de1d2b1533cb.png)

여기서 출력은 들어오는 입력보다 나가는 출력이 더 작아짐 



##### Discriminator 의 구조 (1) overall

* n개의 discriminator block으로 구성됨 (n=3)
* discriminator block은 높은 해상도의 입력을 받아서 낮은 해상도의 출력을 생성 

![image-20210616053927046](https://user-images.githubusercontent.com/82528589/122124555-674eba00-ce6a-11eb-861a-369220bfb344.png)



##### Discriminator 의 구조 (2) discriminator block의 구조

* input_dim 과 outpu_dim 을 parameter 로 받음
* linear layer 와 ReLU 함수로 구성

```python
def discriminator_block(input_dim, output_dim):
    return nn.Sequential(
        nn.Linear(input_dim, output_dim),
        nn.LeakyReLU(0.2,inplace=True))
```



##### Discriminator 의 구조 (3) Discriminator 의 구조

* 3개의 discriminator block와 FC layer로 구성
* 28x28 해상도의 MNIST dataset를 처리하는 discriminator 

- 입력: im_dim = 784

- 출력: 1

  ```python
  class Discriminator(nn.Module):
      def __init__(self, im_dim=784, hidden_dim=128):
          super(Discriminator, self).__init__()
          self.disc = nn.Sequential(
              discriminator_block(im_dim, hidden_dim *4),
              discriminator_block(hidden_dim * 4, hidden_dim *2),
              discriminator_block(hidden_dim * 2, hidden_dim),
              nn.Linear(hidden_dim,1)
          )
          
          def forward(self, image):
              return self.disc(image)
  
          def get_disc(self):
              return self.disc
  
  
  
  ```

  

#### loss 함수

딥러닝을 학습시킨다는 것은 최적의 가중치를 찾아간다는 것을 의미한다. 가중치는 처음에 랜덤으로 초기화되지만, 모델의 손실 함수(Loss Function)을 최소화시키는 방향으로 조금씩 업데이트된다. 이때 손실 함수 값이 역전파를 통해 각 층의 가중치에 전달되며 업데이트 방향과 크기를 결정한다. 이런 방식으로 가중치를 최적화하는 방식을 경사하강법(Gradient Descent)이라고 부른다.

![image](https://user-images.githubusercontent.com/82528589/122421407-4e0f5000-cfc7-11eb-9e67-5dc685381e80.png)

* Discriminator D는 진짜 데이터 x를 입력받았을 경우 D(x)가 1로 생성자가 잠재변수로 부터 생성한 가짜 데이터 G(z)를 입력받았을 경우 D(G(z))를 0을 예측한다.
  * Generator는 생성한 가짜 데이터 G(z)를 Discriminator 가 입력 받는 경우 (=D(G(z))) Discriminator가 이를 1로 예측하도록 하는 것을 목표로 학습한다.  	



![image-20210616055429897](https://user-images.githubusercontent.com/82528589/122125217-26a37080-ce6b-11eb-8f74-0357e49019fd.png)



##### 1. Discriminator -Gradient Ascent 최대화

* 최대값으로 파라미터를 업데이트 하는 것을 목표로 한다.
* 구분자 입장에서는 최상의 경우 (진짜 이미지1, 가짜 이미지를 0으로 출력하는 경우)
* 실제 데이터를 정확히 식별한다는것은 D(x) =1 
* 가짜 데이터를 정확히 분류하는 것은 D(G(z)) =0
* 진짜 이미지를 입력받으면 1, 가짜 이미지를 입력 받으면 0으로 출력하는 것으로 목표 손실 함수 구성한다.



##### 2. Generator - Gradient Descent 최소화

* 위 식의 최소 값으로 파라미터를 업데이트 한다.
  * 생성자 입장에서 최상의 경우(구분자가 생성자가 생성한 가짜이미지를 1로 출력한 경우) D(G(z))=1 , 이는 최소값이 된다. 



#### Training

* GAN 훈련의 어려움 
* D와 G를 동시에 훈련해야 한다. (D는 MAX, G는 MIN을 추구한다.)
* 훈련 초기에 생성되는 G(Z)는 품질이 안좋다.
* 매번 D(G(z))이 0에 가까우면, log(1-D(G(z)))이 0에 가까운 값을 갖게 된다.
* gradient descent 를 적용하기 힘들다.



###### GAN의 heuristic한 훈련 전략

* 초기에는 log(1-D(G(Z)))를 사용하지 않고 D(G(z))를 최대화 시키는 방향으로 훈련시킨다.
* D(G(z))는 log(1-D(G(z))) 보다 값이 더 크기 때문에 gradient가 소실되는 경우를 피할 수 있다. 



![image-20210616060648177](https://user-images.githubusercontent.com/82528589/122125236-2dca7e80-ce6b-11eb-8c9f-a0dde80770ca.png)

* D() :discrimination 데이터 
  처음에는 discrimination 이 잘 구분을 못한다.나중으로 갈수록 구분을 잘하게 된다.

  D(선생님)먼저 훈련을 시키면 G(학생)도 오답인것을 알고 점점 안정이된다. 
