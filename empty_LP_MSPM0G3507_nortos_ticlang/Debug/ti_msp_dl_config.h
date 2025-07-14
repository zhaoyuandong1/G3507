/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_MOTOR */
#define PWM_MOTOR_INST                                                     TIMG6
#define PWM_MOTOR_INST_IRQHandler                               TIMG6_IRQHandler
#define PWM_MOTOR_INST_INT_IRQN                                 (TIMG6_INT_IRQn)
#define PWM_MOTOR_INST_CLK_FREQ                                         80000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_C0_PORT                                             GPIOB
#define GPIO_PWM_MOTOR_C0_PIN                                      DL_GPIO_PIN_6
#define GPIO_PWM_MOTOR_C0_IOMUX                                  (IOMUX_PINCM23)
#define GPIO_PWM_MOTOR_C0_IOMUX_FUNC                 IOMUX_PINCM23_PF_TIMG6_CCP0
#define GPIO_PWM_MOTOR_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_C1_PORT                                             GPIOB
#define GPIO_PWM_MOTOR_C1_PIN                                      DL_GPIO_PIN_7
#define GPIO_PWM_MOTOR_C1_IOMUX                                  (IOMUX_PINCM24)
#define GPIO_PWM_MOTOR_C1_IOMUX_FUNC                 IOMUX_PINCM24_PF_TIMG6_CCP1
#define GPIO_PWM_MOTOR_C1_IDX                                DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMA0)
#define TIMER_0_INST_IRQHandler                                 TIMA0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                          (1999U)




/* Defines for I2C_OLED */
#define I2C_OLED_INST                                                       I2C1
#define I2C_OLED_INST_IRQHandler                                 I2C1_IRQHandler
#define I2C_OLED_INST_INT_IRQN                                     I2C1_INT_IRQn
#define I2C_OLED_BUS_SPEED_HZ                                             400000
#define GPIO_I2C_OLED_SDA_PORT                                             GPIOB
#define GPIO_I2C_OLED_SDA_PIN                                      DL_GPIO_PIN_3
#define GPIO_I2C_OLED_IOMUX_SDA                                  (IOMUX_PINCM16)
#define GPIO_I2C_OLED_IOMUX_SDA_FUNC                   IOMUX_PINCM16_PF_I2C1_SDA
#define GPIO_I2C_OLED_SCL_PORT                                             GPIOB
#define GPIO_I2C_OLED_SCL_PIN                                      DL_GPIO_PIN_2
#define GPIO_I2C_OLED_IOMUX_SCL                                  (IOMUX_PINCM15)
#define GPIO_I2C_OLED_IOMUX_SCL_FUNC                   IOMUX_PINCM15_PF_I2C1_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_FREQUENCY                                            4000000
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_4_MHZ_9600_BAUD                                         (26)
#define UART_0_FBRD_4_MHZ_9600_BAUD                                          (3)





/* Port definition for Pin Group LED */
#define LED_PORT                                                         (GPIOB)

/* Defines for PIN_0: GPIOB.26 with pinCMx 57 on package pin 28 */
#define LED_PIN_0_PIN                                           (DL_GPIO_PIN_26)
#define LED_PIN_0_IOMUX                                          (IOMUX_PINCM57)
/* Port definition for Pin Group BUUZER */
#define BUUZER_PORT                                                      (GPIOB)

/* Defines for PIN_1: GPIOB.8 with pinCMx 25 on package pin 60 */
#define BUUZER_PIN_1_PIN                                         (DL_GPIO_PIN_8)
#define BUUZER_PIN_1_IOMUX                                       (IOMUX_PINCM25)
/* Defines for R2: GPIOA.28 with pinCMx 3 on package pin 35 */
#define TRACK_R2_PORT                                                    (GPIOA)
#define TRACK_R2_PIN                                            (DL_GPIO_PIN_28)
#define TRACK_R2_IOMUX                                            (IOMUX_PINCM3)
/* Defines for R1: GPIOB.1 with pinCMx 13 on package pin 48 */
#define TRACK_R1_PORT                                                    (GPIOB)
#define TRACK_R1_PIN                                             (DL_GPIO_PIN_1)
#define TRACK_R1_IOMUX                                           (IOMUX_PINCM13)
/* Defines for M0: GPIOB.4 with pinCMx 17 on package pin 52 */
#define TRACK_M0_PORT                                                    (GPIOB)
#define TRACK_M0_PIN                                             (DL_GPIO_PIN_4)
#define TRACK_M0_IOMUX                                           (IOMUX_PINCM17)
/* Defines for L1: GPIOB.17 with pinCMx 43 on package pin 14 */
#define TRACK_L1_PORT                                                    (GPIOB)
#define TRACK_L1_PIN                                            (DL_GPIO_PIN_17)
#define TRACK_L1_IOMUX                                           (IOMUX_PINCM43)
/* Defines for L2: GPIOB.12 with pinCMx 29 on package pin 64 */
#define TRACK_L2_PORT                                                    (GPIOB)
#define TRACK_L2_PIN                                            (DL_GPIO_PIN_12)
#define TRACK_L2_IOMUX                                           (IOMUX_PINCM29)
/* Port definition for Pin Group MOTOR */
#define MOTOR_PORT                                                       (GPIOB)

/* Defines for AIN1_A02: GPIOB.24 with pinCMx 52 on package pin 23 */
#define MOTOR_AIN1_A02_PIN                                      (DL_GPIO_PIN_24)
#define MOTOR_AIN1_A02_IOMUX                                     (IOMUX_PINCM52)
/* Defines for AIN2_B24: GPIOB.20 with pinCMx 48 on package pin 19 */
#define MOTOR_AIN2_B24_PIN                                      (DL_GPIO_PIN_20)
#define MOTOR_AIN2_B24_IOMUX                                     (IOMUX_PINCM48)
/* Defines for BIN1_B20: GPIOB.18 with pinCMx 44 on package pin 15 */
#define MOTOR_BIN1_B20_PIN                                      (DL_GPIO_PIN_18)
#define MOTOR_BIN1_B20_IOMUX                                     (IOMUX_PINCM44)
/* Defines for BIN2_B19: GPIOB.19 with pinCMx 45 on package pin 16 */
#define MOTOR_BIN2_B19_PIN                                      (DL_GPIO_PIN_19)
#define MOTOR_BIN2_B19_IOMUX                                     (IOMUX_PINCM45)
/* Defines for STBY: GPIOB.16 with pinCMx 33 on package pin 4 */
#define MOTOR_STBY_PIN                                          (DL_GPIO_PIN_16)
#define MOTOR_STBY_IOMUX                                         (IOMUX_PINCM33)
/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOA)

/* Defines for key1: GPIOA.9 with pinCMx 20 on package pin 55 */
#define KEY_key1_PIN                                             (DL_GPIO_PIN_9)
#define KEY_key1_IOMUX                                           (IOMUX_PINCM20)
/* Defines for key2: GPIOA.8 with pinCMx 19 on package pin 54 */
#define KEY_key2_PIN                                             (DL_GPIO_PIN_8)
#define KEY_key2_IOMUX                                           (IOMUX_PINCM19)
/* Port definition for Pin Group IIC_Software */
#define IIC_Software_PORT                                                (GPIOA)

/* Defines for SCL: GPIOA.1 with pinCMx 2 on package pin 34 */
#define IIC_Software_SCL_PIN                                     (DL_GPIO_PIN_1)
#define IIC_Software_SCL_IOMUX                                    (IOMUX_PINCM2)
/* Defines for SDA: GPIOA.0 with pinCMx 1 on package pin 33 */
#define IIC_Software_SDA_PIN                                     (DL_GPIO_PIN_0)
#define IIC_Software_SDA_IOMUX                                    (IOMUX_PINCM1)
/* Port definition for Pin Group GPIO_ENCODER */
#define GPIO_ENCODER_PORT                                                (GPIOA)

/* Defines for PIN_A: GPIOA.12 with pinCMx 34 on package pin 5 */
// pins affected by this interrupt request:["PIN_A","PIN_B","PIN_A1","PIN_B1"]
#define GPIO_ENCODER_INT_IRQN                                   (GPIOA_INT_IRQn)
#define GPIO_ENCODER_INT_IIDX                   (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_ENCODER_PIN_A_IIDX                             (DL_GPIO_IIDX_DIO12)
#define GPIO_ENCODER_PIN_A_PIN                                  (DL_GPIO_PIN_12)
#define GPIO_ENCODER_PIN_A_IOMUX                                 (IOMUX_PINCM34)
/* Defines for PIN_B: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_ENCODER_PIN_B_IIDX                             (DL_GPIO_IIDX_DIO13)
#define GPIO_ENCODER_PIN_B_PIN                                  (DL_GPIO_PIN_13)
#define GPIO_ENCODER_PIN_B_IOMUX                                 (IOMUX_PINCM35)
/* Defines for PIN_A1: GPIOA.15 with pinCMx 37 on package pin 8 */
#define GPIO_ENCODER_PIN_A1_IIDX                            (DL_GPIO_IIDX_DIO15)
#define GPIO_ENCODER_PIN_A1_PIN                                 (DL_GPIO_PIN_15)
#define GPIO_ENCODER_PIN_A1_IOMUX                                (IOMUX_PINCM37)
/* Defines for PIN_B1: GPIOA.24 with pinCMx 54 on package pin 25 */
#define GPIO_ENCODER_PIN_B1_IIDX                            (DL_GPIO_IIDX_DIO24)
#define GPIO_ENCODER_PIN_B1_PIN                                 (DL_GPIO_PIN_24)
#define GPIO_ENCODER_PIN_B1_IOMUX                                (IOMUX_PINCM54)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MOTOR_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_I2C_OLED_init(void);
void SYSCFG_DL_UART_0_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
