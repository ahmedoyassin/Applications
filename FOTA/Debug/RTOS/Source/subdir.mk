################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/Source/croutine.c \
../RTOS/Source/event_groups.c \
../RTOS/Source/list.c \
../RTOS/Source/queue.c \
../RTOS/Source/stream_buffer.c \
../RTOS/Source/tasks.c \
../RTOS/Source/timers.c 

OBJS += \
./RTOS/Source/croutine.o \
./RTOS/Source/event_groups.o \
./RTOS/Source/list.o \
./RTOS/Source/queue.o \
./RTOS/Source/stream_buffer.o \
./RTOS/Source/tasks.o \
./RTOS/Source/timers.o 

C_DEPS += \
./RTOS/Source/croutine.d \
./RTOS/Source/event_groups.d \
./RTOS/Source/list.d \
./RTOS/Source/queue.d \
./RTOS/Source/stream_buffer.d \
./RTOS/Source/tasks.d \
./RTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/Source/croutine.o: ../RTOS/Source/croutine.c RTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RTOS/Source/croutine.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
RTOS/Source/event_groups.o: ../RTOS/Source/event_groups.c RTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RTOS/Source/event_groups.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
RTOS/Source/list.o: ../RTOS/Source/list.c RTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RTOS/Source/list.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
RTOS/Source/queue.o: ../RTOS/Source/queue.c RTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RTOS/Source/queue.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
RTOS/Source/stream_buffer.o: ../RTOS/Source/stream_buffer.c RTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RTOS/Source/stream_buffer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
RTOS/Source/tasks.o: ../RTOS/Source/tasks.c RTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RTOS/Source/tasks.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
RTOS/Source/timers.o: ../RTOS/Source/timers.c RTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RTOS/Source/timers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

