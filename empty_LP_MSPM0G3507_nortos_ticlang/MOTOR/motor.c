#include "motor.h"
#include "ti_msp_dl_config.h"
#include <ti/driverlib/dl_timer.h>


uint32_t gpio_interrup;
extern uint32_t PWMA,PWMB;
extern int32_t motor_speed;
extern int32_t motor_mode;//0默认停止  1速度环  2位置环  3循迹

void Set_PWML(int pwm)
{
    if(pwm>0)//左轮前进
    {
        DL_GPIO_setPins(MOTOR_PORT, MOTOR_AIN2_B24_PIN);
        DL_GPIO_clearPins(MOTOR_PORT, MOTOR_AIN1_A02_PIN);
        DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,ABS(pwm),GPIO_PWM_MOTOR_C0_IDX);
    }
    else //左轮后进
    {
        DL_GPIO_setPins(MOTOR_PORT,MOTOR_AIN1_A02_PIN);
		DL_GPIO_clearPins(MOTOR_PORT,MOTOR_AIN2_B24_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,ABS(pwm),GPIO_PWM_MOTOR_C0_IDX);

    }
}
void Set_PWMR(int pwm)
{
    if(pwm>0)//右轮前进
    {
        DL_GPIO_setPins(MOTOR_PORT,MOTOR_BIN2_B19_PIN );
		DL_GPIO_clearPins(MOTOR_PORT,MOTOR_BIN1_B20_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,ABS(pwm),GPIO_PWM_MOTOR_C1_IDX);   

    }
    else 
    {
        DL_GPIO_setPins(MOTOR_PORT,MOTOR_BIN1_B20_PIN);
		DL_GPIO_clearPins(MOTOR_PORT,MOTOR_BIN2_B19_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,ABS(pwm),GPIO_PWM_MOTOR_C1_IDX);
    }
}
void Set_PWM(int pwma,int pwmb)
{
    if(pwma>0)//左轮前进
    {   DL_GPIO_clearPins(MOTOR_PORT,MOTOR_AIN2_B24_PIN );
        DL_GPIO_setPins(MOTOR_PORT, MOTOR_AIN1_A02_PIN);
        
        DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,ABS(pwma),GPIO_PWM_MOTOR_C0_IDX);
    }
    else //左轮后进
    {
        DL_GPIO_setPins(MOTOR_PORT,MOTOR_AIN2_B24_PIN);
		DL_GPIO_clearPins(MOTOR_PORT,MOTOR_AIN1_A02_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,ABS(pwma),GPIO_PWM_MOTOR_C0_IDX);

    }

    if(pwmb>0)//右轮前进
    {
        DL_GPIO_setPins(MOTOR_PORT,MOTOR_BIN2_B19_PIN);
		DL_GPIO_clearPins(MOTOR_PORT,MOTOR_BIN1_B20_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,ABS(pwmb),GPIO_PWM_MOTOR_C1_IDX);   

    }
    else 
    {
        DL_GPIO_setPins(MOTOR_PORT,MOTOR_BIN1_B20_PIN);
		DL_GPIO_clearPins(MOTOR_PORT,MOTOR_BIN2_B19_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,ABS(pwmb),GPIO_PWM_MOTOR_C1_IDX);
    }
}




