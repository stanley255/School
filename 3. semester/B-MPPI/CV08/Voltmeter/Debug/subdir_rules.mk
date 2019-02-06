################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
evb1.obj: ../evb1.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/Program Files/CCS_TI_v5.5/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" -vmsp --abi=eabi --include_path="C:/Program Files/CCS_TI_v5.5/ccsv5/ccs_base/msp430/include" --include_path="C:/Program Files/CCS_TI_v5.5/ccsv5/tools/compiler/msp430_4.2.1/include" --advice:power=all -g --define=__MSP430G2231__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="evb1.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main_voltmeter.obj: ../main_voltmeter.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/Program Files/CCS_TI_v5.5/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" -vmsp --abi=eabi --include_path="C:/Program Files/CCS_TI_v5.5/ccsv5/ccs_base/msp430/include" --include_path="C:/Program Files/CCS_TI_v5.5/ccsv5/tools/compiler/msp430_4.2.1/include" --advice:power=all -g --define=__MSP430G2231__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="main_voltmeter.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


