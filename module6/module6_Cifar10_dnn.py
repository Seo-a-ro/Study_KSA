from tensorflow.keras.datasets import cifar10
from tensorflow.keras.models import Sequential, Model
from tensorflow.keras.layers import Dense, Dropout, Input, Activation, Flatten
from tensorflow.keras.layers import Dropout
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

# 하이퍼 파라미터 설정
batch_size = 128

epochs = 12
NUM_CLASSES =10

(X_train, y_train), (X_test, y_test) =cifar10.load_data()

CLASSES = np.array(['airplane', 'automobile', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck'])



# # 변수두기
# actual_single = CLASSES[y_train]
# plt.imshow(X_train[20], interpolation='bicubic')
# temp = "Labels:"+str(actual_single[20])
# plt.title(temp, fontsize=30)
# plt.tight_layout()
# plt.show()


#정규화
X_train = X_train.astype('float32')/255
X_test = X_test.astype('float32')/255

# 라벨
y_train = to_categorical(y_train, NUM_CLASSES)
y_test = to_categorical(y_test, NUM_CLASSES)



# 모델 정의 (dnn unit=200 dense 총 3개로 이용하기 출력층 포함 3 개 )
input_layer = Input(shape=(32,32,3)) #32 by 32
x = Flatten()(input_layer)
x= Dense(units=200, activation='relu')(x)
x= Dense(units=200, activation='relu')(x)
output_layer = Dense(NUM_CLASSES, activation='softmax')(x)
model = Model(inputs=input_layer, outputs=output_layer)
model.summary()


# 모델 컴파일
model.compile(loss='categorical_crossentropy', optimizer='adam', metrics='accuracy')


# 모델 훈련
history = model.fit(X_train, y_train, batch_size=batch_size, epochs=epochs, verbose=1, validation_split=0.2)

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
