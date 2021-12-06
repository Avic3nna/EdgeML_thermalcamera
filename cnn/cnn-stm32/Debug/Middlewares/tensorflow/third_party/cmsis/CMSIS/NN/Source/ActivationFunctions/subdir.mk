################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q15.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q7.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_relu6_s8.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_relu_q15.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_relu_q7.c 

C_DEPS += \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q15.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q7.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_relu6_s8.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_relu_q15.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_relu_q7.d 

OBJS += \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q15.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q7.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_relu6_s8.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_relu_q15.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/arm_relu_q7.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/%.o: ../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/%.c Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ActivationFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu17 -g3 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Middlewares/tensorflow/third_party/flatbuffers/include" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Middlewares/tensorflow" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/CMSIS/Include" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/BSP/STM32F429I-Discovery" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/BSP/Components/Common" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Os -ffunction-sections -Wall -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16  -mfloat-abi=hard -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

