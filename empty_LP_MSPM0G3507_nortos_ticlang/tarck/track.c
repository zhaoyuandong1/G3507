#include "track.h"
#include "board.h"
#include "stdio.h"
// #include <cstdint>

 int data[5];
int cflag=0,q;

float PID_UPdate(track *track1,float error,float time)
{
 track1->error = error;
 track1->time = time;
 track1->integral +=track1->error * track1->time;

 if(track1->integral > 500) 
 track1->integral = 500;
 else if(track1->integral < -500)
 track1->integral = -500;

 track1->output =track1->kp*track1->error+track1->ki*track1->integral+track1->kd*(track1->error - track1->last_error);
 track1->last_error =track1->error;

	 if(track1->output > 999) 
	 track1->output = 999;
	 else if(track1->output < -999)
	 track1->output = -999;
	 return track1->output;
}
void PId_Init_tack(track *track2,float kp,float ki,float kd)
{
    track2->kp =kp;
    track2->ki =ki;
    track2->kd =kd;
}

 int Get_Error() {
  if(data[2]==0) return 0;      // M0=1 → 居中
  else if(data[1]==0) return -50; // L1=1 → 偏左
  else if(data[3]==0) return 50;  // R1=1 → 偏右
  else if(data[0]==0) return -100;// L2=1 → 严重偏左
  else if(data[4]==0) return 100; // R2=1 → 严重偏右
  else return 0;                   // 默认值（脱轨处理）
}


 void updata()
 {  
            data[0] = L2;
            data[1] = L1;
            data[2] = M0;
            data[3] = R1;
            data[4] = R2;    

 }


 void xunji()
 {
    if ( data[4] ==1 & data[3] ==1 & data[2] ==0 & data[1] == 1 & data[0] == 1 )//0 0 1 0 0 
	{
		Set_PWM(500,500);

	}
	if ( data[4] ==1 & data[3] ==0 & data[2] ==0 & data[1] == 0 & data[0] == 1 )//0 1 1 1 0 
	{
		Set_PWM(500,500);
	}

	if ( data[4] ==1 & data[3] ==1 & data[2] ==0 & data[1] == 0 & data[0] == 1 )//0 0 1 1 0 右偏小 
	{
		Set_PWM(400,215);
	}
	if (data[4] ==1 & data[3] ==1 & data[2] ==1 & data[1] == 1 & data[0] == 0  )//0 0 0 0 1 右偏大 
	{
		Set_PWM(500,150);
	}
	if (data[4] ==1 & data[3] ==1 & data[2] ==1 & data[1] == 0 & data[0] == 1  )//0 0 0 1 0 右偏大 
	{
		Set_PWM(500,150);
	}
	if ( data[4] ==1 & data[3] ==1 & data[2] ==1 & data[1] == 0 & data[0] == 0 )//0 0 0 1 1 右偏大 
	{
		Set_PWM(400,215);
	}
	if (data[4] ==1 & data[3] ==1 & data[2] ==0 & data[1] == 1 & data[0] ==0  )//0 0 1 0 1 右偏大 
	{
		Set_PWM(400,215);
	}
    if ( data[4] ==1 & data[3] ==1 & data[2] ==0 & data[1] == 0 & data[0] == 1 )//0 0 1 1 0 右偏大 
	{
		Set_PWM(400,215);
	}
	if ( data[4] ==1 & data[3] ==1 & data[2] ==0 & data[1] == 0 & data[0] == 0 )//0 0 1 1 1 右偏大 
	{
		Set_PWM(400,215);
	}

	if ( data[4] ==1 & data[3] ==0 & data[2] ==0 & data[1] == 1 & data[0] == 1)//0 1 1 0 0 左偏小 
	{
		Set_PWM(165,420);
	}
	if ( data[4] ==0 & data[3] ==1 & data[2] ==1 & data[1] == 1 & data[0] == 1 )//1 0 0 0 0 左偏大 
	{
		
		Set_PWM(140,530);
	}
	if (data[4] ==1 & data[3] ==0 & data[2] ==1 & data[1] == 1 & data[0] == 1 )//0 1 0 0 0 左偏大 
	{
		Set_PWM(140,500);
	}
	if (data[4] ==0 & data[3] ==0 & data[2] ==1 & data[1] == 1 & data[0] == 1)//1 1 0 0 0 左偏大 
	{
		Set_PWM(165,420);
	}
	if (data[4] ==0 & data[3] ==1 & data[2] ==0 & data[1] == 1 & data[0] == 1 )//1 0 1 0 0 左偏大 
	{
		Set_PWM(155,450);
	}
	if (data[4] ==0 & data[3] ==0 & data[2] ==0 & data[1] == 1 & data[0] == 1 )//1 1 1 0 0 左偏大 
	{
		Set_PWM(165,420);
	}
	if ( data[4] ==0 & data[3] ==0 & data[2] ==0 & data[1] == 0 & data[0] == 0)//1 1 1 1 1 停车 
	{
		Set_PWM(400,400);
		
	}
        
 }
 void mode_chack()
 {
	if ( data[4] ==1 & data[3] ==1 & data[2] ==1 & data[1] == 1 & data[0] == 1)//1 1 1 1 1 停车 
	{
		cflag=1;
	}
	if ( data[4] ==0 || data[3] ==0 || data[2] ==0 || data[1] == 0 || data[0] == 0)//1 1 1 1 1 停车 
	{
		cflag =0;
	}
 }

 
// 传感器宏定义（根据实际硬件）
// #define L2 !(DL_GPIO_readPins(TRACK_L2_PORT,TRACK_L2_PIN))
// #define L1 !(DL_GPIO_readPins(TRACK_L1_PORT,TRACK_L1_PIN))
// #define M0 !(DL_GPIO_readPins(TRACK_M0_PORT,TRACK_M0_PIN))
// #define R1 !(DL_GPIO_readPins(TRACK_R1_PORT,TRACK_R1_PIN))
// #define R2 !(DL_GPIO_readPins(TRACK_R2_PORT,TRACK_R2_PIN))

// #define L1 DL_GPIO_readPins(TRACK_L1_PORT,TRACK_L1_PIN)
// #define M0 DL_GPIO_readPins(TRACK_M0_PORT,TRACK_M0_PIN)
// #define R1 DL_GPIO_readPins(TRACK_R1_PORT,TRACK_R1_PIN)
// #define R2 DL_GPIO_readPins(TRACK_R2_PORT,TRACK_R2_PIN)
// //定义pid结构体
// struct PID 
// {
//     float kp;
//     float ki;
//     float kd;
// };
// typedef struct PID _PID;
// _PID TurnPdate = 
// {
//     .kp=125,
//     .ki=0,
//     .kd=-34
// };
// _PID spdPdate = 
// {
//     .kp=-125,
//     .ki=-6,
//     .kd=0
// };
// int PositionPID(float deviation,_PID pid)
// {
// 	float Position_KP=pid.kp,Position_KI=pid.ki,Position_KD=pid.kd;
// 	static float Bias,Pwm,Integral_bias,Last_Bias;
// 	Bias=deviation;                         		         //计算偏差
// 	Integral_bias+=Bias;	                                 //求出偏差的积分
// 	Pwm=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias); //位置式PID控制器
// 	Last_Bias=Bias;                                      	 //保存上一次偏差 
// 	return Pwm;    
// }

// int PositionPIDToSpd(float deviation,_PID pid)
// {
// 	float Position_KP=pid.kp,Position_KI=pid.ki,Position_KD=pid.kd;
// 	static float Bias,Pwm,Integral_bias,Last_Bias,pwmKI=0;
// 	Bias=deviation;                         		         //计算偏差
// 	Integral_bias+=Bias;	                                 //求出偏差的积分
// 	pwmKI=Position_KI*Integral_bias;
// 	if(pwmKI>420) Integral_bias=420/Position_KI;
// 	Pwm=Position_KP*Bias+pwmKI+Position_KD*(Bias-Last_Bias);       //位置式PID控制器
// 	Last_Bias=Bias;                                      	 //保存上一次偏差 
// 	return Pwm;    
// }

// int ChangeTraceTurn(int TraceDate)
// {
// 	int pwm=0;
// 	int bias;
// 	bias=TraceDate;
// 	pwm=PositionPID(bias,TraceDate);
// 	if(pwm>420)		pwm=420;//限幅
// 	else if(pwm<-420)  pwm=-420;
// 	return pwm;
// }

// int ChangeSpeedMotorL(int NowEncodeSpdL,float TarSpdL)
// {
// 	int pwm=0;
// 	int bias;
// 	int TarEncodeSpdL;
// 	// TarEncodeSpdL=(int)((TarSpdL*ACircleEncoder)/(WheelOneCircleDis*125)+0.5f);//根据目标速度求出目标编码器速度
// 	bias=NowEncodeSpdL-TarEncodeSpdL;
// 	pwm=PositionPIDToSpd(bias,spdPdate);
// 	if(pwm>420)		pwm=420;//限幅
// 	else if(pwm<-420)  pwm=-420;
// 	return pwm;
// }

// int ChangeSpeedMotorR(int NowEncodeSpdR,float TarSpdR)
// {
// 	int pwm=0;
// 	int bias;
// 	int TarEncodeSpdR;
// 	// TarEncodeSpdR=(int)((TarSpdR*ACircleEncoder)/(WheelOneCircleDis*125)+0.5f);//根据目标速度求出目标编码器速度
// 	bias=NowEncodeSpdR-TarEncodeSpdR;
// 	pwm=PositionPIDToSpd(bias,spdPdate);
// 	if(pwm>420)		pwm=420;//限幅
// 	else if(pwm<-420)  pwm=-420;
// 	return pwm;
// }
