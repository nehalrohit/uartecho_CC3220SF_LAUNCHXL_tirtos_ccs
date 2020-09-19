################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./INA219.obj" \
"./i2c.obj" \
"./main_tirtos.obj" \
"./uartecho.obj" \
"./syscfg/Board.obj" \
"./LIS2HH12/lis2hh12.obj" \
"./LIS2HH12/lis2hh12_reg.obj" \
"./MLX90614/mlx90614.obj" \
"./Nextion-Library/nextion/NexButton.obj" \
"./Nextion-Library/nextion/NexHardware.obj" \
"./Nextion-Library/nextion/NexNumber.obj" \
"./Nextion-Library/nextion/NexPage.obj" \
"./Nextion-Library/nextion/NexProgressBar.obj" \
"./Nextion-Library/nextion/NexSlider.obj" \
"./Nextion-Library/nextion/NexText.obj" \
"./Nextion-Library/nextion/NexTouch.obj" \
"./Nextion-Library/nextion/Serial.obj" \
"./Nextion-Library/util/Utilities.obj" \
"./TMP/TMP275.obj" \
"../CC3220SF_LAUNCHXL_TIRTOS.cmd" \
-l"ti/display/lib/display.aem4" \
-l"ti/grlib/lib/ccs/m4/grlib.a" \
-l"third_party/spiffs/lib/ccs/m4/spiffs.a" \
-l"ti/drivers/lib/drivers_cc32xx.aem4" \
-l"third_party/fatfs/lib/ccs/m4/fatfs.a" \
-l"ti/dpl/lib/dpl_cc32xx.aem4" \
$(GEN_CMDS__FLAG) \
-l"ti/devices/cc32xx/driverlib/ccs/Release/driverlib.a" \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include LIS2HH12/subdir_vars.mk
-include MLX90614/subdir_vars.mk
-include Nextion-Library/nextion/subdir_vars.mk
-include Nextion-Library/util/subdir_vars.mk
-include TMP/subdir_vars.mk
-include subdir_rules.mk
-include LIS2HH12/subdir_rules.mk
-include MLX90614/subdir_rules.mk
-include Nextion-Library/nextion/subdir_rules.mk
-include Nextion-Library/util/subdir_rules.mk
-include TMP/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.out \

EXE_OUTPUTS__QUOTED += \
"uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.out" \

BIN_OUTPUTS += \
uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.hex \

BIN_OUTPUTS__QUOTED += \
"uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.out"

# Tool invocations
uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me --opt_for_speed=5 --define=sensor --define=Nextion_Tft -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on -z -m"uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.map" -i"/source" -i"/kernel/tirtos/packages" -i"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/lib" --diag_wrap=off --display_error_number --warn_sections --xml_link_info="uartecho_CC3220SF_LAUNCHXL_tirtos_ccs_linkInfo.xml" --rom_model -o "uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/bin/armhex"  -o "uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "INA219.obj" "i2c.obj" "main_tirtos.obj" "uartecho.obj" "syscfg\Board.obj" "LIS2HH12\lis2hh12.obj" "LIS2HH12\lis2hh12_reg.obj" "MLX90614\mlx90614.obj" "Nextion-Library\nextion\NexButton.obj" "Nextion-Library\nextion\NexHardware.obj" "Nextion-Library\nextion\NexNumber.obj" "Nextion-Library\nextion\NexPage.obj" "Nextion-Library\nextion\NexProgressBar.obj" "Nextion-Library\nextion\NexSlider.obj" "Nextion-Library\nextion\NexText.obj" "Nextion-Library\nextion\NexTouch.obj" "Nextion-Library\nextion\Serial.obj" "Nextion-Library\util\Utilities.obj" "TMP\TMP275.obj" 
	-$(RM) "INA219.d" "i2c.d" "main_tirtos.d" "uartecho.d" "syscfg\Board.d" "LIS2HH12\lis2hh12.d" "LIS2HH12\lis2hh12_reg.d" "MLX90614\mlx90614.d" "Nextion-Library\nextion\NexButton.d" "Nextion-Library\nextion\NexHardware.d" "Nextion-Library\nextion\NexNumber.d" "Nextion-Library\nextion\NexPage.d" "Nextion-Library\nextion\NexProgressBar.d" "Nextion-Library\nextion\NexSlider.d" "Nextion-Library\nextion\NexText.d" "Nextion-Library\nextion\NexTouch.d" "Nextion-Library\nextion\Serial.d" "Nextion-Library\util\Utilities.d" "TMP\TMP275.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/bin/armobjcopy -O binary --only-section .text --only-section .const --only-section .cinit --only-section .resetVecs uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.out uartecho_CC3220SF_LAUNCHXL_tirtos_ccs.bin
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

