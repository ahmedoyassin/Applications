################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APP.c \
../Src/HSSD_prg.c \
../Src/MGPIO_prg.c \
../Src/MRCC_prg.c \
../Src/UART_Program.c \
../Src/UART_cfg.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/APP.o \
./Src/HSSD_prg.o \
./Src/MGPIO_prg.o \
./Src/MRCC_prg.o \
./Src/UART_Program.o \
./Src/UART_cfg.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/APP.d \
./Src/HSSD_prg.d \
./Src/MGPIO_prg.d \
./Src/MRCC_prg.d \
./Src/UART_Program.d \
./Src/UART_cfg.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/APP.o: ../Src/APP.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/APP.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/HSSD_prg.o: ../Src/HSSD_prg.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/HSSD_prg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/MGPIO_prg.o: ../Src/MGPIO_prg.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/MGPIO_prg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/MRCC_prg.o: ../Src/MRCC_prg.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/MRCC_prg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/UART_Program.o: ../Src/UART_Program.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/UART_Program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/UART_cfg.o: ../Src/UART_cfg.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/UART_cfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/main.o: ../Src/main.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/include" -I"D:/ARM/01-WorkSpace/Baraa/RTOS/Source/portable/GCC/ARM_CM3" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/include" -I"D:/Embedded ARM/02-ARM Workspace/RTOS_Test/RTOS/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

