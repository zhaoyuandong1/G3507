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

}track;

extern int data[5],cflag,q,error;
 void updata();
 void xunji();
  void mode_chack();
   int PID_UPdate();
    int Get_Error() ;
#endif