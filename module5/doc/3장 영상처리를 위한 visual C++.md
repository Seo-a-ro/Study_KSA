### 3장 영상처리를 위한 visual C++

#### 영상파일 포맷의 종류

**BMP, JPEG, RAW, GIF, PSD, TIFF**  등

BMP, JPEG 파일 포맷

* 영상의 색상정보, 해상도 등을 알수 있는 정보가 헤더(Header)에 포함되어 있음 -> 추가 작업이 필요해 프로그램이 더 복잡해짐.

RAW 파일 포맷

* 헤더 정보 없이 완전한 데이터로만으로 구성 -> 복잡한 헤더 정보 해석할 필요가 없어 영상처리가 복잡하지 않음.
* 헤더 정보가 없어 영상의 색상 정보나 해상도 정보를 사용자가 미리 알아야 하는 단점이 있음

##### OnOpenDocument 함수 :영상 데이터를 파일에서 읽어 오기 

##### OnDraw 함수 : 영상 데이터 출력

 

#### 다운샘플링 (Down Sampling)

* 디지털 영상을 축소하는 가장 간단한 방법
* 다운 샘플링은 원 영상의 값을 일정한 좌표 단위로 버리는 것. 디지털 영상은 2차원이므로 수평축 샘플링과 수직충 샘플링이 모두 되어야 함. 

![image-20210525110954604](https://user-images.githubusercontent.com/82528589/119754169-0d964800-bedb-11eb-91cb-de6c144675fa.png)


<실행결과 >

![image-20210525111604898](https://user-images.githubusercontent.com/82528589/119754211-1b4bcd80-bedb-11eb-89de-b2f4ef347792.png)





#### 업 샘플링(Up Sampling)

* 영상을 확대할 때는 먼저 일정한 배열 간격으로 재배열해야 하는 것.
* 단순 업 샘플링을 사용하여 영상을 확대하면 영상의 품질이 현저히 떨어짐.
* 영상을 확대해도 선명한 품질을 얻고 싶다면 업 샘플링으로 얻은 데이터와 원본 영상의 데이터를 이용하여 보간(Interpolation)을 해야함 
![image-20210525111856890](https://user-images.githubusercontent.com/82528589/119754229-230b7200-bedb-11eb-8fac-095a11c4ebbd.png)

<실행결과 >
![image-20210525112019405](https://user-images.githubusercontent.com/82528589/119754261-2dc60700-bedb-11eb-89de-b47b10a1503a.png)




#### 양자화

* 표본화된 화소의 밝기나 색상을 정해진 몇 단계의 값으로 근사화하는 과정.
* 화소의 밝기나 색상이 숫자로 표현되어 화소는 양자하된 표본 값을 갖게 됨.
* 밝기나 색상이 몇 단계로 표현되느냐는 양자화 비트로 결정됨 
* 양자화 레벨의 수는 2bit로 계산되므로, NM을 계산하는 pow함수를 사용.
![image-20210525112249289](https://user-images.githubusercontent.com/82528589/119754345-51894d00-bedb-11eb-8391-1f28edf0f750.png)

<실행결과>

![image-20210525113404084](https://user-images.githubusercontent.com/82528589/119754392-6239c300-bedb-11eb-98cc-92bad983d56c.png)

