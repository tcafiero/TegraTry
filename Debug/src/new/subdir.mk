################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/new/CallbackTimer.cpp \
../src/new/pTF.cpp \
../src/new/pTM.cpp 

OBJS += \
./src/new/CallbackTimer.o \
./src/new/pTF.o \
./src/new/pTM.o 

CPP_DEPS += \
./src/new/CallbackTimer.d \
./src/new/pTF.d \
./src/new/pTM.d 


# Each subdirectory must supply rules for building sources it contributes
src/new/%.o: ../src/new/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-none-linux-gnueabi-g++ -I"C:\workspace\TegraTry\src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


