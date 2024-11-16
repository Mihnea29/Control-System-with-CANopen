################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/mihneadorcu/Desktop/Licenta/CAN_Loopback/Drivers/BSP/STM32446E_EVAL/stm32446e_eval.c 

OBJS += \
./Drivers/BSP/STM32446E_EVAL/stm32446e_eval.o 

C_DEPS += \
./Drivers/BSP/STM32446E_EVAL/stm32446e_eval.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32446E_EVAL/stm32446e_eval.o: /home/mihneadorcu/Desktop/Licenta/CAN_Loopback/Drivers/BSP/STM32446E_EVAL/stm32446e_eval.c Drivers/BSP/STM32446E_EVAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM32446E_EVAL -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM32446E_EVAL -I../../Drivers/BSP/Components/Common -I../../Utilities/Log -I../../Utilities/Fonts -I../../Utilities/CPU -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32446E_EVAL

clean-Drivers-2f-BSP-2f-STM32446E_EVAL:
	-$(RM) ./Drivers/BSP/STM32446E_EVAL/stm32446e_eval.cyclo ./Drivers/BSP/STM32446E_EVAL/stm32446e_eval.d ./Drivers/BSP/STM32446E_EVAL/stm32446e_eval.o ./Drivers/BSP/STM32446E_EVAL/stm32446e_eval.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32446E_EVAL

