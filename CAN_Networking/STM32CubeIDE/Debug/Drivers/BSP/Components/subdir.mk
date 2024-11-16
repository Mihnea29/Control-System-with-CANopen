################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/BSP/Components/stmpe1600/stmpe1600.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/BSP/Components/stmpe811/stmpe811.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/BSP/Components/ts3510/ts3510.c 

OBJS += \
./Drivers/BSP/Components/stmpe1600.o \
./Drivers/BSP/Components/stmpe811.o \
./Drivers/BSP/Components/ts3510.o 

C_DEPS += \
./Drivers/BSP/Components/stmpe1600.d \
./Drivers/BSP/Components/stmpe811.d \
./Drivers/BSP/Components/ts3510.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/stmpe1600.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/BSP/Components/stmpe1600/stmpe1600.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/stmpe811.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/BSP/Components/stmpe811/stmpe811.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/ts3510.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/BSP/Components/ts3510/ts3510.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components

clean-Drivers-2f-BSP-2f-Components:
	-$(RM) ./Drivers/BSP/Components/stmpe1600.cyclo ./Drivers/BSP/Components/stmpe1600.d ./Drivers/BSP/Components/stmpe1600.o ./Drivers/BSP/Components/stmpe1600.su ./Drivers/BSP/Components/stmpe811.cyclo ./Drivers/BSP/Components/stmpe811.d ./Drivers/BSP/Components/stmpe811.o ./Drivers/BSP/Components/stmpe811.su ./Drivers/BSP/Components/ts3510.cyclo ./Drivers/BSP/Components/ts3510.d ./Drivers/BSP/Components/ts3510.o ./Drivers/BSP/Components/ts3510.su

.PHONY: clean-Drivers-2f-BSP-2f-Components

