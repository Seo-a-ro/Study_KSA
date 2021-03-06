# make a prediction for a new image.
from tensorflow.keras.preprocessing.image import load_img
from tensorflow.keras.preprocessing.image import img_to_array # 이미지를 배열에 넣기위해
from tensorflow.keras.models import load_model
import matplotlib.pyplot as plt
import numpy as np
from tensorflow.keras.preprocessing.image import ImageDataGenerator
import os


def search(dirname):
    img_list = []
    for (path, dir, files) in os.walk(dirname):
        for filename in files:
            ext = os.path.splitext(filename)[-1]
            if ext == '.jpg':
                img_list.append(path+'/'+filename)
    return img_list

# load and prepare the image
# 경로에서 가져온 이미즐 배열(list) 형태로 입력
def load_image(filename):
    # load the image
    img = load_img(filename, target_size=(200, 200))
    # convert to array
    img = img_to_array(img)
    # reshape into a single sample with 3 channels
    img = np.expand_dims(img, axis=0)
    # img scaling 전처리 실행
    img /= 255

    return img

img_list_1 = search('./test_img') # 해당되는 폴더 안에 jpg주소들이 저장되어잇음


# classes = np.array(['cat', 'dog'])

# 데이터 로드  및 acc 하는 부분
model = load_model('./dog_cat_final_model.h5')
model.summary()

#학습할 때 했던 코드와 똑같은 부분
test_datagen = ImageDataGenerator(rescale=1.0 / 255.0)
test_it = test_datagen.flow_from_directory('data_dog_cat/test/',
                                     class_mode='binary', batch_size=64, target_size=(200, 200))
# evaluate model
_, acc = model.evaluate_generator(test_it, steps=len(test_it), verbose=1)
print('>accuracy : %.3f' % (acc * 100.0))


# 모델을 이용해서 그림 그리기
classes = np.array(['cat', 'dog']) # 라벨이 무엇인지 array 로 표현
for i in img_list_1:
    img = load_image(i) # 이미지 가져오기
    # predict the class
    result = model.predict(img) # 모델에 대한 예측 값을 result 변수 값에 넣음
    preds_value = classes[np.argmax(result, axis=-1)] # 그림 그린곳에 string 으로 넣어 주기 위함

    tmp = "predict:" + str(preds_value)
    model_acc = "model_acc:" + str(acc * 100.0)
    # 그림 그리는 부분
    plt.figure(figsize=(10, 10))
    plt.title(tmp)
    plt.xlabel(model_acc, fontsize=20)
    plt.imshow(img[0])
    plt.show()

