################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../CC3220SF_LAUNCHXL_TIRTOS.cmd 

SYSCFG_SRCS += \
../uartecho.syscfg 

C_SRCS += \
../INA219.c \
../i2c.c \
../main_tirtos.c \
../uartecho.c \
./syscfg/Board.c 

GEN_FILES += \
./syscfg/Board.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./INA219.d \
./i2c.d \
./main_tirtos.d \
./uartecho.d \
./syscfg/Board.d 

OBJS += \
./INA219.obj \
./i2c.obj \
./main_tirtos.obj \
./uartecho.obj \
./syscfg/Board.obj 

GEN_MISC_FILES += \
./syscfg/Board.h 

GEN_MISC_DIRS__QUOTED += \
"syscfg\" 

OBJS__QUOTED += \
"INA219.obj" \
"i2c.obj" \
"main_tirtos.obj" \
"uartecho.obj" \
"syscfg\Board.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\Board.h" 

C_DEPS__QUOTED += \
"INA219.d" \
"i2c.d" \
"main_tirtos.d" \
"uartecho.d" \
"syscfg\Board.d" 

GEN_FILES__QUOTED += \
"syscfg\Board.c" 

C_SRCS__QUOTED += \
"../INA219.c" \
"../i2c.c" \
"../main_tirtos.c" \
"../uartecho.c" \
"./syscfg/Board.c" 

SYSCFG_SRCS__QUOTED += \
"../uartecho.syscfg" 


