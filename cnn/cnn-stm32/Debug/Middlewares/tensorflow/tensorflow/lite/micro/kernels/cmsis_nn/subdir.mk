################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/add.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/conv.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/mul.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/pooling.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/softmax.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/svdf.cc 

CC_DEPS += \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/add.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/conv.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/mul.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/pooling.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/softmax.d \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/svdf.d 

OBJS += \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/add.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/conv.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/mul.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/pooling.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/softmax.o \
./Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/svdf.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/%.o: ../Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/%.cc Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/weiss/git/masteree/IAS0360_Machine_Learning_for_Embedded_Systems/IAS0360_lab_excercises/Lab_08/MNIST_mig/Drivers/BSP/STM32F429I-Discovery" -I"/home/weiss/git/masteree/IAS0360_Machine_Learning_for_Embedded_Systems/IAS0360_lab_excercises/Lab_08/MNIST_mig/Drivers/BSP/Components/Common" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

