from tensorflow.keras.datasets import cifar10
from tensorflow.keras.models import Sequential, Model
from tensorflow.keras.layers import Dense, Dropout, Input, Activation, Flatten
from tensorflow.keras.layers import Dropout
from tensorflow.keras.layers import Conv2D, MaxPooling2D, BatchNormalization, LeakyReLU
import matplotlib.pyplot as plt
from keras.utils import to_categorical
import numpy as np
from keras import backend as K
from tensorflow.keras.preprocessing.image import ImageDataGenerator
import os

# loss 그래프 그리기
def plot_loss(history):
    plt.plot(history.history['loss'])
    plt.plot(history.history['val_loss'])
    plt.title('Model loss')
    plt.ylabel('Loss')
    plt.xlabel('Epochs')
    plt.legend(['Train', 'val'], loc =0)

# accuracy 그래프 그리기
def plot_acc(history):
    plt.plot(history.history['accuracy'])
    plt.plot(history.history['val_accuracy'])
    plt.title('Model accuracy')
    plt.ylabel('accuracy')
    plt.xlabel('Epochs')
    plt.legend(['Train','val'], loc=0)

#변수생성
# .h5 or .hdf5 => keras 에서 대용량 파일 저장과 배포 시 많이 사용하는 확장자
model_name = 'keras_cifar10_aug_trained_model.h5'
# 경로를 가져옴
save_dir = os.path.join(os.getcwd(), 'saved_model')



# 하이퍼 파라미터 설정
batch_size = 128
num_classes = 10
epochs = 12

# 입력 이미지 사이즈 정보
img_rows, img_cols = 32, 32

(X_train, y_train), (X_test, y_test) =cifar10.load_data()

if K.image_data_format() == 'th':
    X_train =X_train.reshape(X_train.shape[0], 3, img_rows, img_cols)
    X_test = X_test.reshape(X_test.shape[0], 3, img_rows, img_cols)
    input_shape = (1, img_rows, img_cols)

else:
    X_train = X_train.reshape(X_train.shape[0], img_rows, img_cols, 3)
    X_test = X_test.reshape(X_test.shape[0], img_rows, img_cols, 3)
    input_shape = (img_rows, img_cols, 3)

NUM_CLASSES =10

X_train = X_train.astype('float32')/255
X_test = X_test.astype('float32')/255

y_train = to_categorical(y_train, NUM_CLASSES)
y_test = to_categorical(y_test, NUM_CLASSES)

# 모델 정의 (dnn unit=200 dense 총 3개로 이용하기 출력층 포함 3 개 )
input_tensor = Input(shape=input_shape)
x = Conv2D(filters=32, kernel_size=(3,3), strides=1, padding='same')(input_tensor)
x = LeakyReLU()(x)
x = Conv2D(filters=32, kernel_size=(3,3), strides=2, padding='same')(x)
x = LeakyReLU()(x)
x = Conv2D(filters=64,kernel_size=(3,3), strides=1, padding='same')(x)
x = LeakyReLU()(x)
x = Conv2D(filters=64,kernel_size=(3,3), strides=2, padding='same')(x)
x = LeakyReLU()(x)
x = Flatten()(x) # 1차원으로 쭉 핌
x = Dense(units=128)(x)
x = LeakyReLU()(x)
x = Dense(NUM_CLASSES)(x)
output_layer = Activation('softmax')(x)
model = Model(inputs=input_tensor, outputs=output_layer)
model.summary()

# 모델 컴파일
model.compile(loss='categorical_crossentropy', optimizer='adam', metrics='accuracy')

# data aug
datagen = ImageDataGenerator(
    rotation_range=0.1,
    width_shift_range=0.1,
    height_shift_range=0.1,
    horizontal_flip=True
)

# 모델 학습(aug 적용)
history = model.fit_generator(datagen.flow(X_train, y_train, batch_size=16),
                              steps_per_epoch=X_train.shape[0]/16, epochs=12,
                              validation_data=(X_test, y_test), workers=4)

# 모델 훈련
# history = model.fit(X_train, y_train, batch_size=batch_size, epochs=epochs, verbose=1, validation_split=0.2)


if not os.path.join(save_dir):
    os.makedirs(save_dir)
model_path = os.path.join(save_dir, model_name)
model.save(model_path)

# 모델 평가
score = model.evaluate(X_test, y_test, batch_size=batch_size)
print('\nTest loss', score[0])
print('Test accuracy:', score[1])

# 학습된 loss값과 accuracy를 보기위한 그래프
plt.subplot(1,2,1)
plot_loss(history)
plt.subplot(1,2,2)
plot_acc(history)
plt.show()
