################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/Keypad_Driver/keypad.c 

OBJS += \
./STM32_F103C6_Drivers/Keypad_Driver/keypad.o 

C_DEPS += \
./STM32_F103C6_Drivers/Keypad_Driver/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/Keypad_Driver/keypad.o: ../STM32_F103C6_Drivers/Keypad_Driver/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/1 Embedded systems/STM32 Labs/Embedded Interfacing Labs/Drivers/STM32_F103C6_Drivers/S7_segment_Driver" -I"D:/1 Embedded systems/STM32 Labs/Embedded Interfacing Labs/Drivers/STM32_F103C6_Drivers/Keypad_Driver" -I../Inc -I"D:/1 Embedded systems/STM32 Labs/Embedded Interfacing Labs/Drivers/STM32_F103C6_Drivers/LCD_Driver" -I"D:/1 Embedded systems/STM32 Labs/Embedded Interfacing Labs/Drivers/STM32_F103C6_Drivers/Include_Folder" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/Keypad_Driver/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

