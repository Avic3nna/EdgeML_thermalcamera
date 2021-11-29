###################################################################################
#   Copyright (c) 2021 STMicroelectronics.
#   All rights reserved.
#   This software is licensed under terms that can be found in the LICENSE file in
#   the root directory of this software component.
#   If no LICENSE file comes with this software, it is provided AS-IS.
###################################################################################

# import the necessary libraries to access/pre-process your database and prepare input vectors for your Keras network
#######################################################################################################################
import os
import numpy as np
import pandas as pd
import tensorflow as tf
# from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.utils import to_categorical
from sklearn.model_selection import train_test_split

###############################################################################################
# wrapper function
###############################################################################################
def create_test_generator(quant_test_set_dir, evaluation_test_set_dir, quant_test_ratio, batch_size):

    ########## MNIST example
    #x_testset,y_testset = load_mnist(quant_test_set_dir)
    x_testset,y_testset = load_data(quant_test_set_dir)

    # quantization test-set
    quant_test_set_size = int(np.floor(len(x_testset)*quant_test_ratio))
    np.random.seed(10)
    random_partition_quant_test_set = np.random.permutation(len(x_testset))
    list_idx_input_quant = random_partition_quant_test_set[:quant_test_set_size]

    ####################################################################################################
    # Example with GenericInputBatchGenerator
    ####################################################################################################
    quant_datagen = GenericInputBatchGenerator(input=x_testset[list_idx_input_quant],
                                               labels=y_testset[list_idx_input_quant],
                                               batch_size=batch_size, shuffle=False)
    quant_test_set_labeled = quant_datagen.flow_labeled()
    # quant_test_set_labeled = None if no labels
    quant_test_set_unlabeled = quant_datagen.flow_unlabeled()
    quant_nsteps = len(quant_datagen)

    ####################################################################################################
    # Example with keras API ImageDataGenerator, very practical for 4D tensors inputs (batch, H, W, C)
    ####################################################################################################
    # quant_datagen = ImageDataGenerator(validation_split=quant_test_ratio-0.0001)
    # quant_test_set_labeled = quant_datagen.flow(x_testset, y_testset, batch_size=batch_size, shuffle=False, subset="validation")
    # #quant_test_set_labeled = None if no labels
    # quant_test_set_unlabeled = quant_datagen.flow(x_testset, batch_size=batch_size, subset="validation")
    # quant_nsteps = len(quant_test_set_unlabeled)

    # evaluation test-set

    ####################################################################################################
    # Example with GenericInputBatchGenerator
    ####################################################################################################
    list_idx_input_eval = []
    [list_idx_input_eval.append(idx) for idx in np.arange(len(x_testset)) if idx not in list_idx_input_quant]
    eval_datagen = GenericInputBatchGenerator(input=x_testset[list_idx_input_eval], labels=y_testset[list_idx_input_eval],
                                              batch_size=batch_size, shuffle=False)
    eval_test_set_labeled = eval_datagen.flow_labeled()
    # eval_test_set_labeled = None if no labels
    eval_nsteps = len(eval_datagen)


    return quant_test_set_labeled, quant_test_set_unlabeled, quant_nsteps, eval_test_set_labeled, eval_nsteps


class GenericInputBatchGenerator:

    def __init__(self, input, labels, batch_size=32, shuffle=True):
        'Initialization'
        self.batch_size = batch_size
        self.x = input
        self.y = labels
        self.shuffle = shuffle
        # self.on_epoch_end()

    def __len__(self):
        'Denotes the number of batches per epoch'
        return int(np.ceil(len(self.x) / float(self.batch_size)))

    # Example from Keras site (https://keras.io/models/sequential/)in case data needs to be read from files
    # def generate_arrays_from_file(path):
    #     while True:

    # with open(path) as f:
    #     for line in f:
    #         # create numpy arrays of input data
    #         # and labels, from each line in the file
    #         x1, x2, y = process_line(line)
    #         yield ({'input_1': x1, 'input_2': x2}, {'output': y})

    def flow_labeled(self):
        while True:
            for idx in range(0, self.__len__()):
                batch_x = self.x[idx * self.batch_size:(idx + 1) * self.batch_size]
                # example: batch_x[i,] = np.load('data/' + idx * self.batch_size + '.npy') in case need to read in file
                batch_y = self.y[idx * self.batch_size:(idx + 1) * self.batch_size]

                yield (np.array(batch_x), np.array(batch_y))

    def flow_unlabeled(self):
        while True:
            for idx in range(0, self.__len__()):
                batch_x = self.x[idx * self.batch_size:(idx + 1) * self.batch_size]
                # example: batch_x[i,] = np.load('data/' + idx * self.batch_size + '.npy') in case need to read in file

                yield (np.array(batch_x))


def load_mnist(test_dir):

    MNIST_SHAPE = (28, 28, 1)
    N_CLASSES = 10

    fdata_set = os.path.join(test_dir,'mnist.npz')
    if not os.path.isfile(fdata_set):
        print('Upload the nmist data set with Keras service...')
        mnist_ = tf.keras.datasets.mnist
        _, (x_test, y_test) = mnist_.load_data()
    else:    
        print('Use the data set {}'.format(fdata_set))
        arrays = np.load(os.path.join(fdata_set))
        x_test, y_test = arrays['x_test'], arrays['y_test']

    msize = min(1000, len(x_test))
    np.random.seed(2)  # deterministic results
    rchoice = np.random.choice(len(x_test), size=msize,
                                   replace=False) 

    x_test, y_test = x_test[rchoice], y_test[rchoice] 

    x_test = x_test.reshape((-1, ) + MNIST_SHAPE).astype('float32') / 255
    y_test = to_categorical(y_test, N_CLASSES)

    print('x_test', x_test.shape)
    print('y_test', y_test.shape)

    return x_test, y_test


def load_data(test_dir):

    SHAPE = (32, 32, 1)
    N_CLASSES = 2

    df = pd.read_json('../data/labelled_data/prepared-samples-binary.json')

    y = df['label'].to_numpy()
    X = np.array(df['data'].to_list())
    X = np.expand_dims(X, axis=3)

    # Create train / val / test split
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)
    X_val, X_test, y_val, y_test = train_test_split(X_test, y_test, test_size=0.5, random_state=0)

    msize = min(1000, len(x_test))
    np.random.seed(2)  # deterministic results
    rchoice = np.random.choice(len(x_test), size=msize,
                                   replace=False) 

    x_test, y_test = x_test[rchoice], y_test[rchoice] 

    x_test = x_test.reshape((-1, ) + SHAPE).astype('float32') / 255
    y_test = to_categorical(y_test, N_CLASSES)

    print('x_test', x_test.shape)
    print('y_test', y_test.shape)

    return x_test, y_test

