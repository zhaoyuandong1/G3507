#ifndef __PID_H__
#define __PID_H__

#include "ti_msp_dl_config.h"

int Velocity_A(int TargetVelocity, int CurrentVelocity);
int Velocity_B(int TargetVelocity, int CurrentVelocity);


#endif