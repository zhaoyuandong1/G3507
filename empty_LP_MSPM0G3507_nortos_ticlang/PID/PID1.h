// #ifndef __PID1_H__ 
// #define __PID1_H__
// typedef struct
// {
//     float target,Actual,out;
//     float Kp,Ki,Kd;
//     float Error0,Error1,ErrorInt;  
// }PId;
// typedef struct
// {
// 	float TKp,TKi,TKd;		//PID系数
// 	float err;				//误差（测量值减去目标值）P的倍数【比例】
// 	float err_sum;			//误差的累加（I的倍数）
// 	float err_difference;	//误差的差值（D的倍数）
// 	float last_err;			//上一次误差
// }PID;
// extern PId L,R;
// void PId_Init(PId *pid,float kp,float ki,float kd,float target);
// float PId_calc(PId *pid,float Actual);
// #endif