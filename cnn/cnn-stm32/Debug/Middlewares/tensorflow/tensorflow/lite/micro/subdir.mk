################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Middlewares/tensorflow/tensorflow/lite/micro/all_ops_resolver.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/memory_helpers.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/micro_allocator.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/micro_error_reporter.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/micro_interpreter.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/micro_profiler.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/micro_string.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/micro_time.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/micro_utils.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/recording_micro_allocator.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/recording_simple_memory_allocator.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/simple_memory_allocator.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/system_setup.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/test_helpers.cc 

CC_DEPS += \
./Middlewares/tensorflow/tensorflow/lite/micro/all_ops_resolver.d \
./Middlewares/tensorflow/tensorflow/lite/micro/memory_helpers.d \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_allocator.d \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_error_reporter.d \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_interpreter.d \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_profiler.d \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_string.d \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_time.d \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_utils.d \
./Middlewares/tensorflow/tensorflow/lite/micro/recording_micro_allocator.d \
./Middlewares/tensorflow/tensorflow/lite/micro/recording_simple_memory_allocator.d \
./Middlewares/tensorflow/tensorflow/lite/micro/simple_memory_allocator.d \
./Middlewares/tensorflow/tensorflow/lite/micro/system_setup.d \
./Middlewares/tensorflow/tensorflow/lite/micro/test_helpers.d 

OBJS += \
./Middlewares/tensorflow/tensorflow/lite/micro/all_ops_resolver.o \
./Middlewares/tensorflow/tensorflow/lite/micro/memory_helpers.o \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_allocator.o \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_error_reporter.o \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_interpreter.o \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_profiler.o \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_string.o \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_time.o \
./Middlewares/tensorflow/tensorflow/lite/micro/micro_utils.o \
./Middlewares/tensorflow/tensorflow/lite/micro/recording_micro_allocator.o \
./Middlewares/tensorflow/tensorflow/lite/micro/recording_simple_memory_allocator.o \
./Middlewares/tensorflow/tensorflow/lite/micro/simple_memory_allocator.o \
./Middlewares/tensorflow/tensorflow/lite/micro/system_setup.o \
./Middlewares/tensorflow/tensorflow/lite/micro/test_helpers.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/tensorflow/tensorflow/lite/micro/%.o: ../Middlewares/tensorflow/tensorflow/lite/micro/%.cc Middlewares/tensorflow/tensorflow/lite/micro/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++17 -g3 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Middlewares/tensorflow" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Middlewares/tensorflow/third_party/flatbuffers/include" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/CMSIS/Include" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/BSP/STM32F429I-Discovery" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/BSP/Components/Common" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16  -mfloat-abi=hard -u _printf_float -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

