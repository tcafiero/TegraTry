################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/new/IVIradioSubsystem/pTF.cpp 

OBJS += \
./src/new/IVIradioSubsystem/pTF.o 

CPP_DEPS += \
./src/new/IVIradioSubsystem/pTF.d 


# Each subdirectory must supply rules for building sources it contributes
src/new/IVIradioSubsystem/%.o: ../src/new/IVIradioSubsystem/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-none-linux-gnueabi-g++ -I"C:\workspace\TegraTry\src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


