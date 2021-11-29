################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Middlewares/tensorflow/tensorflow/lite/micro/memory_planner/greedy_memory_planner.cc \
../Middlewares/tensorflow/tensorflow/lite/micro/memory_planner/linear_memory_planner.cc 

CC_DEPS += \
./Middlewares/tensorflow/tensorflow/lite/micro/memory_planner/greedy_memory_planner.d \
./Middlewares/tensorflow/tensorflow/lite/micro/memory_planner/linear_memory_planner.d 

OBJS += \
./Middlewares/tensorflow/tensorflow/lite/micro/memory_planner/greedy_memory_planner.o \
./Middlewares/tensorflow/tensorflow/lite/micro/memory_planner/linear_memory_planner.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/tensorflow/tensorflow/lite/micro/memory_planner/%.o: ../Middlewares/tensorflow/tensorflow/lite/micro/memory_planner/%.cc Middlewares/tensorflow/tensorflow/lite/micro/memory_planner/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/weiss/git/masteree/IAS0360_Machine_Learning_for_Embedded_Systems/IAS0360_lab_excercises/Lab_08/MNIST_mig/Drivers/BSP/STM32F429I-Discovery" -I"/home/weiss/git/masteree/IAS0360_Machine_Learning_for_Embedded_Systems/IAS0360_lab_excercises/Lab_08/MNIST_mig/Drivers/BSP/Components/Common" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

