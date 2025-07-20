#ifndef __SERSOR_H
#define __SERSOR_H
#include "main.h"
#define P1          DL_GPIO_readPins(TRACK_P1_PORT,TRACK_P1_PIN)
#define P2          DL_GPIO_readPins(TRACK_P2_PORT,TRACK_P2_PIN)
#define P3          DL_GPIO_readPins(TRACK_P3_PORT,TRACK_P3_PIN)
#define P4          DL_GPIO_readPins(TRACK_P4_PORT,TRACK_P4_PIN)
#define P5          DL_GPIO_readPins(TRACK_P5_PORT,TRACK_P5_PIN)
#define P6         DL_GPIO_readPins(TRACK_P6_PORT,TRACK_P6_PIN)
#define P7          DL_GPIO_readPins(TRACK_P7_PORT,TRACK_P7_PIN)
#define P8          DL_GPIO_readPins(TRACK_P8_PORT,TRACK_P8_PIN)
int Follow_Route(void);
int Follow_Route_Mode3(int stop);
int Follow_Route_Mode4(void);

int Incremental_Quantity(void);
int Incremental_Quantity3(void);
int Incremental_Quantity4(void);


#endif