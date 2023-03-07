################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Case.cpp \
../src/Map.cpp \
../src/Player.cpp \
../src/Sokoban.cpp 

CPP_DEPS += \
./src/Case.d \
./src/Map.d \
./src/Player.d \
./src/Sokoban.d 

OBJS += \
./src/Case.o \
./src/Map.o \
./src/Player.o \
./src/Sokoban.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Case.d ./src/Case.o ./src/Map.d ./src/Map.o ./src/Player.d ./src/Player.o ./src/Sokoban.d ./src/Sokoban.o

.PHONY: clean-src

