#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "board.h"
#define ABS(a)   (a>0?a:(-a))


void motor_init(void);
void Set_PWM(int pwma,int pwmb);
void motor_stop();

void Set_PWML(int pwm);

void Set_PWMR(int pwm);


#endif