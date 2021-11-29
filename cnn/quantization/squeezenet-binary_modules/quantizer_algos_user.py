###################################################################################
#   Copyright (c) 2021 STMicroelectronics.
#   All rights reserved.
#   This software is licensed under terms that can be found in the LICENSE file in
#   the root directory of this software component.
#   If no LICENSE file comes with this software, it is provided AS-IS.
###################################################################################
import numpy as np

# example for weights/bias quantization

class WeightsBiasQuantizerUser:
    """Example quantizer using the min /max value range.
    User can change the content of the functions given in example
    but the interface need to be kept unchanged"""

    def __init__(self, bits=8):
        self._min, self._max, self._bits = None, None, bits

    def estimate(self, val):
        """Get the range of the tensor and updates the estimate."""
        self._min = np.min(val) if self._min is None \
            else min(np.min(val), self._min)
        self._max = np.max(val) if self._max is None \
            else max(np.max(val), self._max)
        return self

    def get_min_max_nbits(self):
        return self._min, self._max, self._bits


# example for activations quantization
# here it is the same as for weights and bias, but the user can make it different
# provided function interface is still respected

class ActivationsQuantizerUser:
    """Example quantizer using min/max value range.
     User can change the content of the functions given in example
    but the interface need to be kept unchanged"""

    def __init__(self, bits=8):
        self._min, self._max, self._bits = None, None, bits

    def estimate(self, val):
        """Get the range of the tensor and updates the estimate."""
        self._min = np.min(val) if self._min is None \
            else min(np.min(val), self._min)
        self._max = np.max(val) if self._max is None \
            else max(np.max(val), self._max)
        return self

    def get_min_max_nbits(self):
        return self._min, self._max, self._bits

