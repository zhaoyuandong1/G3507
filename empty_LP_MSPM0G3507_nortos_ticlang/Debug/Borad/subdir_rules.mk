################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Borad/%.o: ../Borad/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"F:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"F:/Tiproject/intcar/intcar/empty_LP_MSPM0G3507_nortos_ticlang/OLED" -I"F:/Tiproject/intcar/intcar/empty_LP_MSPM0G3507_nortos_ticlang" -I"F:/Tiproject/intcar/intcar/empty_LP_MSPM0G3507_nortos_ticlang/Debug" -I"C:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_01_00/source" -I"F:/Tiproject/intcar/intcar/empty_LP_MSPM0G3507_nortos_ticlang/MPU6050" -I"F:/Tiproject/intcar/intcar/empty_LP_MSPM0G3507_nortos_ticlang/PID" -I"F:/Tiproject/intcar/intcar/empty_LP_MSPM0G3507_nortos_ticlang/Board" -gdwarf-3 -MMD -MP -MF"Borad/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


