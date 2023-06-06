################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../prac4b/src/leon3_bprint.c \
../prac4b/src/leon3_ev_handling.c \
../prac4b/src/leon3_hw_irqs.c \
../prac4b/src/leon3_monotonic_clk.c \
../prac4b/src/leon3_timer_unit_drv.c \
../prac4b/src/leon3_timing_service.c \
../prac4b/src/leon3_uart.c \
../prac4b/src/main.c 

S_UPPER_SRCS += \
../prac4b/src/leon3_ev_handling_asm.S 

OBJS += \
./prac4b/src/leon3_bprint.o \
./prac4b/src/leon3_ev_handling.o \
./prac4b/src/leon3_ev_handling_asm.o \
./prac4b/src/leon3_hw_irqs.o \
./prac4b/src/leon3_monotonic_clk.o \
./prac4b/src/leon3_timer_unit_drv.o \
./prac4b/src/leon3_timing_service.o \
./prac4b/src/leon3_uart.o \
./prac4b/src/main.o 

C_DEPS += \
./prac4b/src/leon3_bprint.d \
./prac4b/src/leon3_ev_handling.d \
./prac4b/src/leon3_hw_irqs.d \
./prac4b/src/leon3_monotonic_clk.d \
./prac4b/src/leon3_timer_unit_drv.d \
./prac4b/src/leon3_timing_service.d \
./prac4b/src/leon3_uart.d \
./prac4b/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
prac4b/src/%.o: ../prac4b/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

prac4b/src/%.o: ../prac4b/src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


