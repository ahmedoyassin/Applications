################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prg.c \
../CURT1_prg.c \
../DCMOTOR_PRG.c \
../DIO_prg.c \
../EX_INT_prg.c \
../INTERRUPT_prg.c \
../TIMER_PRG.c \
../UART_prg.c \
../WDT_prg.c \
../main.c 

OBJS += \
./ADC_prg.o \
./CURT1_prg.o \
./DCMOTOR_PRG.o \
./DIO_prg.o \
./EX_INT_prg.o \
./INTERRUPT_prg.o \
./TIMER_PRG.o \
./UART_prg.o \
./WDT_prg.o \
./main.o 

C_DEPS += \
./ADC_prg.d \
./CURT1_prg.d \
./DCMOTOR_PRG.d \
./DIO_prg.d \
./EX_INT_prg.d \
./INTERRUPT_prg.d \
./TIMER_PRG.d \
./UART_prg.d \
./WDT_prg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


