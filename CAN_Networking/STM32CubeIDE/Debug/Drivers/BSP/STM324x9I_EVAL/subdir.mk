################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval_io.c 

OBJS += \
./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval.o \
./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval_io.o 

C_DEPS += \
./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval.d \
./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval_io.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval.c Drivers/BSP/STM324x9I_EVAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval_io.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval_io.c Drivers/BSP/STM324x9I_EVAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM324x9I_EVAL

clean-Drivers-2f-BSP-2f-STM324x9I_EVAL:
	-$(RM) ./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval.cyclo ./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval.d ./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval.o ./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval.su ./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval_io.cyclo ./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval_io.d ./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval_io.o ./Drivers/BSP/STM324x9I_EVAL/stm324x9i_eval_io.su

.PHONY: clean-Drivers-2f-BSP-2f-STM324x9I_EVAL

