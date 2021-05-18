import numpy as np
import pandas as pd
from sklearn import datasets
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Input
import matplotlib.pyplot as plt
from keras.utils import to_categorical
from sklearn.utils import shuffle

# loss 그래프 그리기
def plot_loss(history):
    plt.plot(history.history['loss'])
    plt.plot(history.history['val_loss'])
    plt.title('Model loss')
    plt.ylabel('loss')
    plt.xlabel('Epochs')
    plt.legend(['train','val'], loc=0)

# accuracy 그래프 그리기
def plot_acc(history):
    plt.plot(history.history['accuracy'])
    plt.plot(history.history['val_accuracy'])
    plt.title('Model accuracy')
    plt.ylabel('accuracy')
    plt.xlabel('Epochs')
    plt.legend(['train','val'],loc=0)


# 데이터 불러오기
iris=datasets.load_iris()
x = iris.data
y = iris.target
# print(x)
# print(y)


#label 카테고리화
dataset_x = iris.data
dataset_y = to_categorical(iris.target)


# 랜덤으로 섞기
dataset_x, dataset_y = shuffle(dataset_x,dataset_y)


#데이터 나누기
X_train = dataset_x[:120]
X_test = dataset_x[120:]

y_train = dataset_y[:120]
y_test = dataset_y[120:]

# 모델링
model=Sequential()
model.add(Dense(64,input_shape=(4,),activation='relu'))
model.add(Dense(64,activation='relu'))
model.add(Dense(3,activation='softmax'))

model.compile(loss='categorical_crossentropy', optimizer='Adam', metrics=['accuracy'])
model.summary()


# 학습
# validation 값을 만들어주지 않았으므로 값을 그냥 넣어줌
history = model.fit(X_train,y_train,validation_data=(X_test,y_test),epochs=10)
print('\n')
print('test start')
# verbose = 1 이면 test data 진행율을 나타냄
score = model.evaluate(X_test, y_test, verbose=1)
print('test_loss:',score[0])
print('test_acc:',score[1])


# 학습된 loss값과 accuracy를 보기위한 그래프
plt.subplot(1,2,1)
plot_loss(history)
plt.subplot(1,2,2)
plot_acc(history)
plt.show()
