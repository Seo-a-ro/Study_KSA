from tensorflow.keras.datasets import mnist
from tensorflow.keras.models import Sequential, Model
from tensorflow.keras.layers import Dense, Dropout, Input, Activation, Flatten
from tensorflow.keras.layers import Conv2D, MaxPooling2D, BatchNormalization
import matplotlib.pyplot as plt
from keras.utils import to_categorical
import numpy as np
from keras import backend as K

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

# 하이퍼파라미터 설정
batch_size = 128
num_classes = 10
epochs = 12

# 입력 이미지 사이즈 정보
img_rows, img_cols = 28, 28

#filter개수
nb_filter = 32


# 데이터 로드
(X_train, y_train),(X_test,y_test) =mnist.load_data()


if K.image_data_format() == 'th':
    X_train =X_train.reshape(X_train.shape[0], 1, img_rows, img_cols)
    X_test = X_test.reshape(X_test.shape[0], 1, img_rows, img_cols)
    input_shape = (1, img_rows, img_cols)

else:
    X_train = X_train.reshape(X_train.shape[0], img_rows, img_cols, 1)
    X_test = X_test.reshape(X_test.shape[0], img_rows, img_cols, 1)
    input_shape = (img_rows, img_cols, 1)

# 정규화
X_train = X_train.astype('float32')
X_test = X_test.astype('float32')
X_train /=255
X_test /=255

# 라벨
y_train= to_categorical(y_train, num_classes)
y_test = to_categorical(y_test,num_classes)

# 네트워크 정의
input_tensor = Input(shape=input_shape)
x = Conv2D(nb_filter, kernel_size=(3,3), padding='valid', name='Conv1')(input_tensor)
x = Activation('relu', name='relu_1')(x)
x = Conv2D(nb_filter, kernel_size=(3,3), padding='valid', name='Conv2')(x)
x = Activation('relu', name='relu_2')(x)
x = MaxPooling2D(pool_size=(2,2), name='pool_1')(x)
x = Flatten()(x) # 1차원으로 쭉 핌
x = Dense(units=128, name='hidden_1')(x)
x = Activation('relu', name='relu_3')(x)
x = Dense(units=10, name='hidden_2')(x)
output_tensor = Activation('softmax',name='output_tensor')(x)
model = Model(inputs= input_tensor, outputs= output_tensor)
model.summary()

model.compile(loss='categorical_crossentropy', optimizer='adam', metrics='accuracy')

# model 학습
history = model.fit(X_train, y_train, batch_size=batch_size,
                    epochs=epochs, verbose=1, validation_split=0.2)

# predict
print("Test start")
score = model.evaluate(X_test,y_test, batch_size=batch_size)
print('\nTest loss:', score[0])
print('test Accuracy:', score[1])

# 학습된 loss값과 accuracy를 보기위한 그래프
plot_loss(history)
plt.show()
plot_acc(history)
plt.show()