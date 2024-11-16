################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_can.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c \
/home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_can.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_cortex.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma_ex.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_gpio.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr_ex.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sram.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_uart.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.o 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_can.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_cortex.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma_ex.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_gpio.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr_ex.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sram.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_uart.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_can.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_can.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_cortex.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma_ex.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_gpio.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr_ex.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sram.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_uart.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.o: /home/mihneadorcu/Desktop/Licenta/CAN_Networking/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_STM324x9I_EVAL -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../../Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/BSP/STM324x9I_EVAL -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F4xx_HAL_Driver

clean-Drivers-2f-STM32F4xx_HAL_Driver:
	-$(RM) ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_can.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_can.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_can.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_can.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_cortex.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_cortex.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_cortex.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_cortex.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma_ex.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma_ex.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma_ex.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma_ex.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_gpio.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_gpio.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_gpio.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_gpio.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr_ex.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr_ex.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr_ex.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr_ex.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sram.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sram.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sram.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sram.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_uart.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_uart.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_uart.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_uart.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.cyclo ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.su

.PHONY: clean-Drivers-2f-STM32F4xx_HAL_Driver

