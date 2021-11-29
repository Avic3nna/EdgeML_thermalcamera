################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/activations.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/add_n.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/arg_min_max.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/batch_to_space_nd.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/cast.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/ceil.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/circular_buffer.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/comparisons.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/concatenation.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/conv_common.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/depthwise_conv_common.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/dequantize.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/detection_postprocess.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/div.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/elementwise.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/elu.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/ethosu.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/exp.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/expand_dims.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/fill.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/floor.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/fully_connected_common.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/hard_swish.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/kernel_runner.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/kernel_util.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/l2_pool_2d.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/l2norm.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/leaky_relu.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/logical.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/logistic.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/maximum_minimum.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/neg.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/pack.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/pad.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/prelu.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/quantize.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/quantize_common.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/reduce.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/reshape.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/resize_nearest_neighbor.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/round.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/shape.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/softmax_common.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/space_to_batch_nd.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/split.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/split_v.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/squeeze.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/strided_slice.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/sub.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/svdf_common.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/tanh.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/transpose_conv.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/unpack.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/zeros_like.cc 

CC_DEPS += \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/activations.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/add_n.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/arg_min_max.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/batch_to_space_nd.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cast.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/ceil.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/circular_buffer.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/comparisons.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/concatenation.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/conv_common.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/depthwise_conv_common.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/dequantize.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/detection_postprocess.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/div.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/elementwise.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/elu.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/ethosu.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/exp.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/expand_dims.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/fill.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/floor.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/fully_connected_common.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/hard_swish.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/kernel_runner.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/kernel_util.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/l2_pool_2d.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/l2norm.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/leaky_relu.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/logical.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/logistic.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/maximum_minimum.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/neg.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/pack.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/pad.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/prelu.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/quantize.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/quantize_common.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/reduce.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/reshape.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/resize_nearest_neighbor.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/round.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/shape.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/softmax_common.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/space_to_batch_nd.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/split.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/split_v.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/squeeze.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/strided_slice.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/sub.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/svdf_common.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/tanh.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/transpose_conv.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/unpack.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/zeros_like.d 

OBJS += \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/activations.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/add_n.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/arg_min_max.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/batch_to_space_nd.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cast.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/ceil.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/circular_buffer.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/comparisons.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/concatenation.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/conv_common.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/depthwise_conv_common.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/dequantize.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/detection_postprocess.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/div.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/elementwise.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/elu.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/ethosu.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/exp.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/expand_dims.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/fill.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/floor.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/fully_connected_common.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/hard_swish.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/kernel_runner.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/kernel_util.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/l2_pool_2d.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/l2norm.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/leaky_relu.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/logical.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/logistic.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/maximum_minimum.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/neg.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/pack.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/pad.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/prelu.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/quantize.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/quantize_common.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/reduce.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/reshape.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/resize_nearest_neighbor.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/round.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/shape.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/softmax_common.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/space_to_batch_nd.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/split.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/split_v.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/squeeze.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/strided_slice.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/sub.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/svdf_common.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/tanh.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/transpose_conv.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/unpack.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/zeros_like.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/tensorflow/tensorflow/lite/micro/kernels/%.o: ../Middlewares/tensorflow/tensorflow/lite/micro/kernels/%.cc Middlewares/tensorflow/tensorflow/lite/micro/kernels/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/weiss/git/masteree/IAS0360_Machine_Learning_for_Embedded_Systems/IAS0360_lab_excercises/Lab_08/MNIST_mig/Drivers/BSP/STM32F429I-Discovery" -I"/home/weiss/git/masteree/IAS0360_Machine_Learning_for_Embedded_Systems/IAS0360_lab_excercises/Lab_08/MNIST_mig/Drivers/BSP/Components/Common" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

