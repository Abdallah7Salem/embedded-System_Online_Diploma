################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/S7_segment.c \
../HAL/keypad.c \
../HAL/lcd.c 

OBJS += \
./HAL/S7_segment.o \
./HAL/keypad.o \
./HAL/lcd.o 

C_DEPS += \
./HAL/S7_segment.d \
./HAL/keypad.d \
./HAL/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/S7_segment.o: ../HAL/S7_segment.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/1 Embedded systems/STM32 Labs/Embedded Interfacing Labs/Drivers/HAL/includes" -I../Inc -I"D:/1 Embedded systems/STM32 Labs/Embedded Interfacing Labs/Drivers/STM32_F103C6_Drivers/Include_Folder" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/S7_segment.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/keypad.o: ../HAL/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/1 Embedded systems/STM32 Labs/Embedded Interfacing Labs/Drivers/HAL/includes" -I../Inc -I"D:/1 Embedded systems/STM32 Labs/Embedded Interfacing Labs/Drivers/STM32_F103C6_Drivers/Include_Folder" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/lcd.o: ../HAL/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/1 Embedded systems/STM32 Labs/Embedded Interfacing Labs/Drivers/HAL/includes" -I../Inc -I"D:/1 Embedded systems/STM32 Labs/Embedded Interfacing Labs/Drivers/STM32_F103C6_Drivers/Include_Folder" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

