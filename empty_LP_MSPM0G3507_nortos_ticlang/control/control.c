#include "control.h"

#define  Limit		999			//PWM波限幅


//速度环PID
#define   Kp1   	3
#define   Ki1     	0
#define   Kd1  		0.4


// //陀螺仪PID
// #define   Kp3       3.5
// #define   Ki3       0
// #define   Kd3  	    0.5

//陀螺仪PID
#define   Kp3       2
#define   Ki3       0
#define   Kd3  	    0


float Speed_Middle = 90;			                    //中值速度
int Motor_Left, Motor_Right;		                    //左右电机占空比


 float Yaw;
extern volatile int mode;
extern volatile int flag;
extern volatile int32_t EncoderA_VEL, EncoderB_VEL;     //编码器测得当前速度	

void ce(void)
{
      float TargetA, TargetB;                         //目标速度
    float bias1, bias2, bias;                       //巡线、陀螺仪偏差
    //  lc_printf("%f,  ",Yaw);
     bias =GYRO_Control(Yaw, 45);
    // bias = Yaw;
    //    lc_printf("%f,%f\n",bias,Yaw);
     TargetA = Speed_Middle - bias ;
    TargetB = Speed_Middle  + bias;
    // lc_printf("  %f,%f\n",TargetA,TargetB);
    Motor_Left  = (int)PWM_Limit(PID_A(get_encoder_countL(),TargetA), Limit, -Limit);
    Motor_Right = (int)PWM_Limit(PID_B(get_encoder_countR(),TargetB), Limit, -Limit);
    lc_printf("  %d,%d\n",Motor_Right,Motor_Left);
    Set_PWM(Motor_Right,Motor_Left);
}

void  Control(void)
{
    float TargetA, TargetB;                         //目标速度
    float bias1, bias2, bias;                       //巡线、陀螺仪偏差

    /* 模式一、二 */
    if(mode == 1 || mode == 2)
    {
        if(flag == 1)       bias = GYRO_Control(Yaw, 0);
        else if(flag == 2)  bias = Incremental_Quantity();
        else if(flag == 3){
            float MyYaw;
            if(Yaw > 0) MyYaw = Yaw - 180;
            else MyYaw = Yaw + 180;
            bias = GYRO_Control(MyYaw, 2);        
        }
        else if(flag == 4) bias = Incremental_Quantity();
    }
        /* 模式三、四 */
    else if(mode == 3 || mode == 4)
    {
        if(flag == 1)       bias = GYRO_Control(Yaw, 0);
        else if(flag == 2)  bias = Incremental_Quantity();
        else if(flag == 3){
            float MyYaw;
            if(Yaw > 0) MyYaw = Yaw - 180;
            else MyYaw = Yaw + 180;
            // if(mode ==3)
            bias = GYRO_Control(Yaw, -115);
            // else   bias = GYRO_Control(Yaw, -115);      
        }
        else if(flag == 4) bias = Incremental_Quantity4();    
    }


    TargetA = Speed_Middle - bias;
    TargetB = Speed_Middle + bias;

    Motor_Left  = (int)PWM_Limit(PID_A(get_encoder_countL(),TargetA), Limit, -Limit);
    Motor_Right = (int)PWM_Limit(PID_B(get_encoder_countR(),TargetB), Limit, -Limit);
    lc_printf("%d,%d\n",bias,Motor_Left);
    Set_PWM(Motor_Right,Motor_Left);
}

float GYRO_Control(float now,float target)
{
	static float Bias, Last_bias, Last2_bias, Pwm;
	Bias = target-now;
	Pwm += Kp3 * (Bias - Last_bias) + Ki3 * Bias + Kd3 * (Bias - 2 * Last_bias + Last2_bias);

	Last_bias = Bias;
	Last2_bias = Last_bias;
	return Pwm;
}

/*=================== 增量式PID控制设计 ===================*/
//左A轮PID
float PID_A(float Encoder,float Target)
{
	static float Bias, Last_bias, Last2_bias, Pwm;
	Bias = Target - Encoder;
	Pwm += Kp1 * (Bias - Last_bias) + Ki1 * Bias + Kd1 * (Bias - 2 * Last_bias + Last2_bias);

	Last_bias = Bias;
	Last2_bias = Last_bias;
	return Pwm;
}

//右B轮PID
float PID_B(float Encoder,float Target)
{
	static float Bias, Last_bias, Last2_bias, Pwm;
	Bias = Target-Encoder;
	Pwm += Kp1 * (Bias - Last_bias) + Ki1 * Bias + Kd1 * (Bias - 2 * Last_bias + Last2_bias);

	Last_bias = Bias;
	Last2_bias = Last_bias;
	return Pwm;
}

/* 
    函数功能：限幅 + 绝对值函数
    IN: 输入值
    max: 最大值
    min: 最小值
    OUT: 输出值
*/
float PWM_Limit(float IN,float max,float min)
{
	float OUT = IN;
	if(OUT > max) OUT = max;
	if(OUT < min) OUT = min;
	return OUT;
}