################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me --opt_for_speed=1 --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/LIS2HH12" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/TMP" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/MLX90614" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/Nextion-Library/nextion" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/Nextion-Library/util" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/Debug__opt_for_speed__1" --include_path="/source" --include_path="/source/ti/posix/ccs" --include_path="C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/include" --define=sensor --define=Nextion_Tft -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/Debug__opt_for_speed__1/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-604832015: ../uartecho.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs1000/ccs/utils/sysconfig_1.4.0/sysconfig_cli.bat" -o "syscfg" --compiler ccs "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/Board.c: build-604832015 ../uartecho.syscfg
syscfg/Board.h: build-604832015
syscfg/: build-604832015

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me --opt_for_speed=1 --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/LIS2HH12" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/TMP" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/MLX90614" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/Nextion-Library/nextion" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/Nextion-Library/util" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/Debug__opt_for_speed__1" --include_path="/source" --include_path="/source/ti/posix/ccs" --include_path="C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.0.LTS/include" --define=sensor --define=Nextion_Tft -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/DNK125/workspace_v10/uartecho_CC3220SF_LAUNCHXL_tirtos_ccs/Debug__opt_for_speed__1/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


