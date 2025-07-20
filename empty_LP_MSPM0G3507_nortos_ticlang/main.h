#ifndef __MAIN_H
#define __MAIN_H

#include "ti_msp_dl_config.h"
#include "board.h"
#include "stdio.h"
#include "motor.h"
#include "track.h"
#include "oled.h"
#include "Delay.h"
#include "pid.h"
#include <stdint.h>
#include <mpu6050.h>
#include "inv_mpu.h"
#include "PID1.h"
#include "uart.h"
#include "hardware.h"
#include "JY61P.h"
#include "control.h"
#include "sersor.h"
#include "bsp_gyro.h"

#define LED_High        DL_GPIO_setPins(LED_PORT, LED_PIN_0_PIN)
#define LED_Low         DL_GPIO_clearPins(LED_PORT, LED_PIN_0_PIN)

#endif