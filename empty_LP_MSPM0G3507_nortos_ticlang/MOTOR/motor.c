#include "motor.h"
#include "ti_msp_dl_config.h"
#include <ti/driverlib/dl_timer.h>

#define ENCODER_PPR_MOTOR   450.0f      // 电机轴编码器分辨率：400 PPR
// 每度对应的脉冲数
#define PULSE_PER_DEG       (ENCODER_PPR_MOTOR / 360.0f)     
// 45° 对应的脉冲数
#define PULSES_45_DEG       ((uint32_t)(PULSE_PER_DEG * 45.0f + 0.5f))

uint32_t gpio_interrup;
extern uint32_t PWMA,PWMB;
extern int32_t motor_speed;
extern int32_t motor_mode;//0默认停止  1速度环  2位置环  3循迹
static ENCODER_RES motor_encoder;


//编码器初始化
void encoder_init(void)
{
	//编码器引脚外部中断
	NVIC_ClearPendingIRQ(GPIOB_INT_IRQn);
	NVIC_EnableIRQ(GPIOB_INT_IRQn);
}

//获取编码器的值
int get_encoder_countR(void)
{
	return (-motor_encoder.count);
}

//获取编码器的值
int get_encoder_countL(void)
{
	return motor_encoder.count1;
}


void encoder_update(void)
{
	motor_encoder.count = motor_encoder.temp_count;
    motor_encoder.count1 = motor_encoder.temp_count1;


	motor_encoder.temp_count = 0;//编码器计数值清零
    motor_encoder.temp_count1 = 0;//编码器计数值清零
}

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





//外部中断处理函数
void GROUP1_IRQHandler(void)
{
	uint32_t gpio_status;

	//获取中断信号情况
	gpio_status = DL_GPIO_getEnabledInterruptStatus(GPIO_ENCODER_PORT, GPIO_ENCODER_PIN_A_PIN | GPIO_ENCODER_PIN_B_PIN | GPIO_ENCODER_PIN_A1_PIN |GPIO_ENCODER_PIN_B1_PIN);
	//编码器A相上升沿触发
	if((gpio_status & GPIO_ENCODER_PIN_A_PIN) == GPIO_ENCODER_PIN_A_PIN)
	{
		//如果在A相上升沿下，B相为低电平
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B_PIN))
		{
			motor_encoder.temp_count--;
		}
		else
		{
			motor_encoder.temp_count++;
		}
	}//编码器B相上升沿触发
	else if((gpio_status & GPIO_ENCODER_PIN_B_PIN)==GPIO_ENCODER_PIN_B_PIN)
	{
		//如果在B相上升沿下，A相为低电平
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A_PIN))
		{
			motor_encoder.temp_count++;
		}
		else
		{
			motor_encoder.temp_count--;
		}
	}

    if((gpio_status & GPIO_ENCODER_PIN_A1_PIN) == GPIO_ENCODER_PIN_A1_PIN)
	{
		//如果在A相上升沿下，B相为低电平
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B1_PIN))
		{
			motor_encoder.temp_count1--;
		}
		else
		{
			motor_encoder.temp_count1++;
		}
	}//编码器B相上升沿触发
	else if((gpio_status & GPIO_ENCODER_PIN_B1_PIN)==GPIO_ENCODER_PIN_B1_PIN)
	{
		//如果在B相上升沿下，A相为低电平
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A1_PIN))
		{
			motor_encoder.temp_count1++;
		}
		else
		{
			motor_encoder.temp_count1--;
		}
	}
	//清除状态
	DL_GPIO_clearInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A_PIN|GPIO_ENCODER_PIN_B_PIN |GPIO_ENCODER_PIN_A1_PIN | GPIO_ENCODER_PIN_B1_PIN);
}
