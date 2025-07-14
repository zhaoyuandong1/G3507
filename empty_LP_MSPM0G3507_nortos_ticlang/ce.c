// #include "ce.h"
// #include "motor.h"
//  PID speed_pid,speed_pid1;
// /****************************************************
// 功能：PID计算
// 参数：pid = pid的参数输入
//      target = 目标值
//      current = 当前值
// 返回：PID计算后的结果
// ****************************************************/
// float pid_calc(PID *pid, float target, float current)
// {
  
//     // 保存上一次误差
//     pid->last_error = pid->error;
//     // 计算新误差
//     pid->error = target - current;

//     // 计算比例项
//     float pout = pid->error ;
//     // 计算微分项（使用误差变化率）
//     float dout = pid->error - pid->last_error;

//     // 计算未限幅的输出值（用于抗积分饱和）
//     float output_unclamped = (pid->kp * pout) + (pid->ki * pid->change_i) + (pid->kd * dout);

//     // 临时保存当前积分项（用于抗积分饱和回退）
//     float last_integral = pid->change_i;

//     // 更新积分项：累加当前误差
//     pid->change_i += pid->error ;

//     // 应用积分限幅
//     if(pid->change_i > pid->max_change_i) {
//         pid->change_i = pid->max_change_i;
//     } else if(pid->change_i < -pid->max_change_i) {
//         pid->change_i = -pid->max_change_i;
//     }

//     // 计算实际输出（使用更新后的积分项）
//     pid->output = (pid->kp * pout) + (pid->ki * pid->change_i) + (pid->kd * dout);

//     // 输出限幅 + 抗积分饱和处理
//     if(pid->output > pid->max_output) {
//         pid->output = pid->max_output;
//         // 抗饱和回退：恢复之前的积分值
//         pid->change_i = last_integral;
//     } else if(pid->output < -pid->max_output) {
//         pid->output = -pid->max_output;
//         // 抗饱和回退：恢复之前的积分值
//         pid->change_i = last_integral;
//     }

//     return pid->output;
// }


// void PID_CascdeCalc(CascadePID *pid,float outerRef,float outerFdb,float innerFdb)
// {
//     PID_Calc(&pid->outer, outerRef, outerFdb);
//     PID_Calc(&pid->inner,encoderA_cnt, innerFdb);
//     pid->output = pid->inner.output;

// }
