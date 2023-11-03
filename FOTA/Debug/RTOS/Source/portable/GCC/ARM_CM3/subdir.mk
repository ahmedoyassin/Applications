################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/Source/portable/GCC/ARM_CM3/port.c 

OBJS += \
./RTOS/Source/portable/GCC/ARM_CM3/port.o 

C_DEPS += \
./RTOS/Source/portable/GCC/ARM_CM3/port.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/Source/portable/GCC/ARM_CM3/port.o: ../RTOS/Source/portable/GCC/ARM_CM3/port.c RTOS/Source/portable/GCC/ARM_CM3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RTOS/Source/portable/GCC/ARM_CM3/port.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

