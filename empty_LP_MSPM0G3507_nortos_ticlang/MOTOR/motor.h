#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "board.h"
#define ABS(a)   (a>0?a:(-a))

typedef struct {
    volatile long long temp_count; //保存实时计数值
    volatile long long temp_count1; //保存实时计数值
    int count;         						 //根据定时器时间更新的计数值
    int count1;

} ENCODER_RES;
extern int32_t Get_Encoder_countA,Get_Encoder_countB,encoderA_cnt,encoderB_cnt;

void motor_init(void);
void Set_PWM(int pwma,int pwmb);
void motor_stop();
void encoder_init(void);


//获取编码器的值
int get_encoder_countL(void);

//获取编码器的值
int get_encoder_countR(void);



void encoder_update(void);

void Set_PWML(int pwm);

void Set_PWMR(int pwm);


#endif