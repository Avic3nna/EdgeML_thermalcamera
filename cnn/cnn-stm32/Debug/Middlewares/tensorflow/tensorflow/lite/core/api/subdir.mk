################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Middlewares/tensorflow/tensorflow/lite/core/api/error_reporter.cc \
../Middlewares/tensorflow/tensorflow/lite/core/api/flatbuffer_conversions.cc \
../Middlewares/tensorflow/tensorflow/lite/core/api/op_resolver.cc \
../Middlewares/tensorflow/tensorflow/lite/core/api/tensor_utils.cc 

CC_DEPS += \
./Middlewares/tensorflow/tensorflow/lite/core/api/error_reporter.d \
./Middlewares/tensorflow/tensorflow/lite/core/api/flatbuffer_conversions.d \
./Middlewares/tensorflow/tensorflow/lite/core/api/op_resolver.d \
./Middlewares/tensorflow/tensorflow/lite/core/api/tensor_utils.d 

OBJS += \
./Middlewares/tensorflow/tensorflow/lite/core/api/error_reporter.o \
./Middlewares/tensorflow/tensorflow/lite/core/api/flatbuffer_conversions.o \
./Middlewares/tensorflow/tensorflow/lite/core/api/op_resolver.o \
./Middlewares/tensorflow/tensorflow/lite/core/api/tensor_utils.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/tensorflow/tensorflow/lite/core/api/%.o: ../Middlewares/tensorflow/tensorflow/lite/core/api/%.cc Middlewares/tensorflow/tensorflow/lite/core/api/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++17 -g3 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Middlewares/tensorflow/third_party/flatbuffers/include" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Middlewares/tensorflow" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/CMSIS/Include" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/BSP/STM32F429I-Discovery" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/BSP/Components/Common" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16  -mfloat-abi=hard -u _printf_float -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

