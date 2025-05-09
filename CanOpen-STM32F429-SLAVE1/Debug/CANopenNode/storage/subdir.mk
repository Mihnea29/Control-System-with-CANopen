################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/mihneadorcu/Desktop/Licenta/CANopenNode/storage/CO_storage.c \
/home/mihneadorcu/Desktop/Licenta/CANopenNode/storage/CO_storageEeprom.c 

OBJS += \
./CANopenNode/storage/CO_storage.o \
./CANopenNode/storage/CO_storageEeprom.o 

C_DEPS += \
./CANopenNode/storage/CO_storage.d \
./CANopenNode/storage/CO_storageEeprom.d 


# Each subdirectory must supply rules for building sources it contributes
CANopenNode/storage/CO_storage.o: /home/mihneadorcu/Desktop/Licenta/CANopenNode/storage/CO_storage.c CANopenNode/storage/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/mihneadorcu/Desktop/Licenta/CANopenNode -I/home/mihneadorcu/Desktop/Licenta/CanOpen-STM32F429-SLAVE1/CANopenNode_STM32 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CANopenNode/storage/CO_storageEeprom.o: /home/mihneadorcu/Desktop/Licenta/CANopenNode/storage/CO_storageEeprom.c CANopenNode/storage/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/mihneadorcu/Desktop/Licenta/CANopenNode -I/home/mihneadorcu/Desktop/Licenta/CanOpen-STM32F429-SLAVE1/CANopenNode_STM32 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CANopenNode-2f-storage

clean-CANopenNode-2f-storage:
	-$(RM) ./CANopenNode/storage/CO_storage.cyclo ./CANopenNode/storage/CO_storage.d ./CANopenNode/storage/CO_storage.o ./CANopenNode/storage/CO_storage.su ./CANopenNode/storage/CO_storageEeprom.cyclo ./CANopenNode/storage/CO_storageEeprom.d ./CANopenNode/storage/CO_storageEeprom.o ./CANopenNode/storage/CO_storageEeprom.su

.PHONY: clean-CANopenNode-2f-storage

