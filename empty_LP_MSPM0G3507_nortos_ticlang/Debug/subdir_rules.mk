################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/TI/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/OLED" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Hardware" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Debug" -I"C:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_01_00/source" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/MPU6050" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/PID" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Board" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/tarck" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Delay" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/UART" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/MOTOR" -DMPU6050 -DMOTION_DRIVER_TARGET_MSPM0 -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1548898625: ../empty.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/TI/ccs2020/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/empty.syscfg" -o "." -s "C:/ti/mspm0_sdk_2_05_01_00/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1548898625 ../empty.syscfg
device.opt: build-1548898625
device.cmd.genlibs: build-1548898625
ti_msp_dl_config.c: build-1548898625
ti_msp_dl_config.h: build-1548898625
Event.dot: build-1548898625

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/TI/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/OLED" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Hardware" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Debug" -I"C:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_01_00/source" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/MPU6050" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/PID" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Board" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/tarck" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Delay" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/UART" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/MOTOR" -DMPU6050 -DMOTION_DRIVER_TARGET_MSPM0 -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: C:/ti/mspm0_sdk_2_05_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/TI/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/OLED" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Hardware" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Debug" -I"C:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_01_00/source" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/MPU6050" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/PID" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Board" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/tarck" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/Delay" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/UART" -I"D:/25diansai/empty_LP_MSPM0G3507_nortos_ticlang/MOTOR" -DMPU6050 -DMOTION_DRIVER_TARGET_MSPM0 -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


