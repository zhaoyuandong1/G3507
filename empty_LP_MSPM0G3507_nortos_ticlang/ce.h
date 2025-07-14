// #ifndef __CE_H
// #define __CE_H
// #include "stdint.h"
// typedef struct
// {
//   float kp, ki, kd; 						      // 三个静态系数
//   float change_p, change_i, change_d;	          // 三个动态参数
//   float error, last_error; 						  // 误差、之前误差
//   float max_change_i; 							  // 积分限幅
//   float output, max_output; 				      // 输出、输出限幅
//   uint32_t last_time;
//   int target;                                     // 目标
// }PID;

// typedef struct
// {
//     PID inner; 
//     PID outer; 
//     float output; 
// }CascadePID;
// extern PID speed_pid,speed_pid1;

// float pid_calc(PID *pid, float target, float current);


// #endif