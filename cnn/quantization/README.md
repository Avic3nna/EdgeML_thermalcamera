# Example of quantization scripts

## Overview

This package contains two typical examples of quantization scripts which must be used by the X-CUBE-AI CLI command: `quantize`.

To facilitate their usage, typical h5 models are provided with the
associated representative data set extracted from the public examples:

    https://keras.io/examples/vision/mnist_convnet/
    https://www.tensorflow.org/datasets/catalog/speech_commands


## Quantization

To quantize the pre-trained MN:wqIST model with a ss/sa integer scheme:

    $ stm32ai quantize -q cfg_mnist_ss_sa_pc.json


## License

Example is licensed under the BSD 3-Clause license.

