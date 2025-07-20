#ifndef __TRACK_H__
#define __TRACK_H__

#include "ti_msp_dl_config.h"
#include "motor.h"
#define  L2 !DL_GPIO_readPins(TRACK_L2_PORT,TRACK_L2_PIN)
#define  L1 !DL_GPIO_readPins(TRACK_L1_PORT,TRACK_L1_PIN)
#define  M0 !DL_GPIO_readPins(TRACK_M0_PORT,TRACK_M0_PIN)
#define  R1 !DL_GPIO_readPins(TRACK_R1_PORT,TRACK_R1_PIN)
#define  R2 !DL_GPIO_readPins(TRACK_R2_PORT,TRACK_R2_PIN)

typedef struct {
float kp,ki,kd;
int error,last_error;
int integral,output;
float time;
}track;

extern int data[5],cflag,q,error;
extern track x;
 void updata();
 void xunji();
  void mode_chack();
float PID_UPdate(track *track1,float error,float time);
void PId_Init_tack(track *track2,float kp,float ki,float kd);
    int Get_Error() ;
#endif