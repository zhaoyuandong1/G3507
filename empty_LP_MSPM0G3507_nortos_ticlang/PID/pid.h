#ifndef __PID_H__
#define __PID_H__

#include "ti_msp_dl_config.h"
extern float Kp1,Ki1,Kd1;
float PID_A(float Encoder,float Target);
float PID_B(float Encoder,float Target);
float PWM_Limit(float IN,float max,float min);              //pwm限幅

#endif