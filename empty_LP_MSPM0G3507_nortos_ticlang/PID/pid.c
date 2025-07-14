#include "pid.h"


























// float Velcity_Kp=1.1,  Velcity_Ki=0,  Velcity_Kd=0; //相关速度PID参数
float Velcity_Kp=4.15,  Velcity_Ki=1.2,  Velcity_Kd=0.5; //相关速度PID参数
// float Velcity_Kp=6.14,Velcity_Ki=0.2, Velcity_Kd=0.9; //相关速度PID参数
// float Velcity_Kp=8.5,  Velcity_Ki=0.2,  Velcity_Kd=0.3; //相关速度PID参数


/***************************************************************************
函数功能：电机的PID闭环控制
入口参数：左右电机的编码器值
返回值  ：电机的PWM
***************************************************************************/
int Velocity_A(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;  //定义相关变量
		static int ControlVelocityA, Last_biasA; //静态变量，函数调用结束后其值依然存在
		
		Bias=TargetVelocity-CurrentVelocity; //求速度偏差
		
		ControlVelocityA+=Velcity_Ki*(Bias-Last_biasA)+Velcity_Kp*Bias;  //增量式PI控制器
                                                                   //Velcity_Kp*(Bias-Last_bias) 作用为限制加速度
	                                                                //Velcity_Ki*Bias             速度控制值由Bias不断积分得到 偏差越大加速度越大
		Last_biasA=Bias;	
	    if(ControlVelocityA>999) ControlVelocityA=999;
	    else if(ControlVelocityA<-999) ControlVelocityA=-999;
		return ControlVelocityA; //返回速度控制值
}

/***************************************************************************
函数功能：电机的PID闭环控制
入口参数：左右电机的编码器值
返回值  ：电机的PWM
***************************************************************************/
int Velocity_B(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;  //定义相关变量
		static int ControlVelocityB, Last_biasB; //静态变量，函数调用结束后其值依然存在
		
		Bias=TargetVelocity-CurrentVelocity; //求速度偏差
		
		ControlVelocityB+=Velcity_Ki*(Bias-Last_biasB)+Velcity_Kp*Bias;  //增量式PI控制器
                                                                   //Velcity_Kp*(Bias-Last_bias) 作用为限制加速度
	                                                                 //Velcity_Ki*Bias             速度控制值由Bias不断积分得到 偏差越大加速度越大
		Last_biasB=Bias;	
	    if(ControlVelocityB>999) ControlVelocityB=999;
	    else if(ControlVelocityB<-999) ControlVelocityB=-999;
		return ControlVelocityB; //返回速度控制值
}

