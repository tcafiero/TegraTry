################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/class/A.cpp \
../src/class/B.cpp \
../src/class/C.cpp \
../src/class/D.cpp \
../src/class/F.cpp \
../src/class/G.cpp \
../src/class/H.cpp \
../src/class/I.cpp 

OBJS += \
./src/class/A.o \
./src/class/B.o \
./src/class/C.o \
./src/class/D.o \
./src/class/F.o \
./src/class/G.o \
./src/class/H.o \
./src/class/I.o 

CPP_DEPS += \
./src/class/A.d \
./src/class/B.d \
./src/class/C.d \
./src/class/D.d \
./src/class/F.d \
./src/class/G.d \
./src/class/H.d \
./src/class/I.d 


# Each subdirectory must supply rules for building sources it contributes
src/class/%.o: ../src/class/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-none-linux-gnueabi-g++ -I"C:\workspace\TegraTry\src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


