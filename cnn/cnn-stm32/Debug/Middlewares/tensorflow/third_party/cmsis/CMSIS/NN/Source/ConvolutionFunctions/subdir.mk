################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_s8.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_s8.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_u8_basic_ver1.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s8.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16_reordered.c \
../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.c 

C_DEPS += \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_s8.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_s8.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_u8_basic_ver1.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s8.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16_reordered.d \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.d 

OBJS += \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_s8.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_s8.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_u8_basic_ver1.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s8.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16_reordered.o \
./Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/%.o: ../Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/%.c Middlewares/tensorflow/third_party/cmsis/CMSIS/NN/Source/ConvolutionFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu17 -g3 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Middlewares/tensorflow" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Middlewares/tensorflow/third_party/flatbuffers/include" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/CMSIS/Include" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/BSP/STM32F429I-Discovery" -I"/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/BSP/Components/Common" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I/home/weiss/git/ias0360-final-project/cnn/cnn-stm32/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Os -ffunction-sections -Wall -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16  -mfloat-abi=hard -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

