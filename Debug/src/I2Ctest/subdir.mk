################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/I2Ctest/i2c8Bit.cpp \
../src/I2Ctest/mcp23017test.cpp 

OBJS += \
./src/I2Ctest/i2c8Bit.o \
./src/I2Ctest/mcp23017test.o 

CPP_DEPS += \
./src/I2Ctest/i2c8Bit.d \
./src/I2Ctest/mcp23017test.d 


# Each subdirectory must supply rules for building sources it contributes
src/I2Ctest/%.o: ../src/I2Ctest/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-none-linux-gnueabi-g++ -I"C:\workspace\TegraTry\src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


