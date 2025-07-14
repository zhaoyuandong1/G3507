#include "PID1.h"

PId L,R;
 PID Tpid = {-245,0,-2300,0,0,0,0};
void PId_Init(PId *pid,float kp,float ki,float kd,float target)
{
    pid->Kp = kp;
    pid->Ki = ki;
    pid->Kd = kd;
    pid->target =target;
}

float PId_calc(PId *pid,float speed)
{
            pid->Actual =speed;
            pid->Error1 =pid->Error0;
            pid->Error0 = pid->target - pid->Actual;
            pid->ErrorInt += pid->Error0;
           
            
			/*积分限幅*/
			if (pid->ErrorInt > 600) {pid->ErrorInt = 600;}		//限制误差积分最大为500
			if (pid->ErrorInt < -600) {pid->ErrorInt = -600;}		//限制误差积分最小为-500
			
             pid->out = pid->Kp * pid->Error0 + pid->Ki * pid->ErrorInt + pid->Kd * (pid->Error0 - pid->Error1);
            if(pid->out >999) pid->out = 999;
            if(pid->out <-999) pid->out =-999;
            return pid->out;
}

int yaw_PD_value(float yaw_measure,float yaw_calcu)//测量的，目标的
{
	Tpid.err = yaw_measure - yaw_calcu;    											//误差
	float out;
	
	if(Tpid.err> 180) Tpid.err = Tpid.err - 360;                   					//不是舍弃误差，而是转换一下 （对角度进行处理）  
	if(Tpid.err<-180) Tpid.err = Tpid.err + 360;        
	
	Tpid.err_sum +=Tpid.err;														//误差累加
	Tpid.err_difference = Tpid.err - Tpid.last_err;									//转向偏差
	Tpid.last_err = Tpid.err;                                     					//此次误差记录为“上次误差”
	out=Tpid.TKp*Tpid.err + Tpid.TKi*Tpid.err_sum + Tpid.TKd*Tpid.err_difference;	//P*（误差）+ I*误差的累加 + D*误差的差值
	
	// if(out>720)																	//限幅
	// {
	// 	out=720;
	// }else if(out<-720)
	// {
	// 	out=-720;
	// }
	
	return out;
}