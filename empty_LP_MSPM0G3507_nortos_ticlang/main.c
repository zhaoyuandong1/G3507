/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "main.h"
#define  Limit		999						//PWM波限幅，百分比制
// float pitch =0,roll=0,yaw =0,yawi=0;
// int Yaw;
// int16_t Speed, Location;		//速度，位置
int32_t Get_Encoder_countA,encoderA_cnt,Get_Encoder_countB,encoderB_cnt,PWMA,PWMB;
 int32_t motor_mode = MOTOR_STOP;//0默认停止  1速度环  2位置环  3循迹
int cnt=0,cnt1=0,cnt2;

/* USER CODE BEGIN PV */
volatile int flag = 1;                                  //flag状态位：0-暂停；1-AB段；2-BC段；3-CD段；4-DA段；
volatile int mode = 3;                                  //mode状态位：0-暂停；1-模式一... ...；
volatile int flag_en = 1;                               //flag_en状态位：0-不使能；1-使能

volatile uint32_t EncoderA_Port, EncoderB_Port;         //编码器端口
volatile int32_t EncoderA_CNT = 0, EncoderB_CNT = 0;    //编码器计数值
volatile int32_t EncoderA_VEL = 0, EncoderB_VEL = 0;    //马达速度

extern float Pitch, Roll, Yaw;                          //姿态角

volatile float LED_CNT = 0.0;
volatile bool flag_LED = 0;
void LED_Sound(void);
// int flag=1,n=1,whiteflag=0,whiteflag1=0;         //白色区域计数标志位；白色区域计数值；陀螺仪模式标志位
// int timebegin=0,timenum=0;          //陀螺仪模式启动延时标志位；延时计数值
// int timebegin1=0,timenum1=0;          //陀螺仪模式启动延时标志位；延时计数值
// int ledbegin=0,lednum=0,ledflag=0,ledflag1=0,ledflag2=0;        //声光模块延时标志位；延时计数值；声光模块启动标志位
// int m;
//  extern PID Tpid;
// float CurrentA, CurrentB;			//编码器测得当前速度
// float targetA=0, targetB=0;			//当前目标速度
// float Speed_Middle=90;				//中值速度
/*定义变量*/
// float Target=5, Actual, Out;			//目标值，实际值，输出值
// float Kp=250, Ki=0.5, Kd;					//比例项，积分项，微分项的权重
// float Error0, Error1, ErrorInt;		//本次误差，上次误差，误差积分

// float Target1=400, Actual1, Out1;			//目标值，实际值，输出值
// float Kp1=0.3, Ki1=0.3, Kd1;					//比例项，积分项，微分项的权重
// float Error01, Error11, ErrorInt1;		//本次误差，上次误差，误差积分

// int myabs(int a)                                                //自定义绝对值函数
// {
// 	int temp;
// 	if(a < 0)  temp = -a;
// 	else temp = a;
// 	return temp;
// }

// void Control_AB(void)                       //模式一
// {
//     int Motor_Left, Motor_Right;            //电机赋值
//     float bias;                             //差速值

//     bias = Yaw;                             //直接将陀螺仪偏差值作为差速值
//     targetA = Speed_Middle + bias;                //基于基准值给电机差速
// 	targetB = Speed_Middle - bias;
//     CurrentA = get_encoder_countL();       //左轮当前转速
// 	CurrentB = get_encoder_countR();      //右轮当前转速
// 	Motor_Left  = (int)PWM_Limit(PID_A(CurrentA,targetA),Limit, -Limit);
// 	Motor_Right = (int)PWM_Limit(PID_A(CurrentB,targetB),Limit, -Limit);		//PWM限幅
//     // if(L2 == 0 || L1 == 0 || M0 == 0 || R1 == 0  || R2 == 0  )
//     // DL_GPIO_clearPins(GPIOB, MOTOR_STBY_PIN);
//      lc_printf("%f    ",bias);
//     lc_printf("%f,%f    ",targetA,targetB);
//     lc_printf("%d,%d\n",Motor_Left,Motor_Right);
// 	Set_PWM( Motor_Right,Motor_Left);
// }

// void Control_ABCDA(void)                    //模式二
// {
// 	int Motor_Left, Motor_Right;            //电机赋值
//     float bias;                             //差速值
//       if(m==6)                                //m为模式切换计数值，用于判断是否跑完全程
//     {
//       DL_GPIO_clearPins(GPIOB, MOTOR_STBY_PIN);
//     }

//     // if (ledflag==1) DL_GPIO_setPins(GPIO_LED_PORT,GPIO_LED_PIN_LED_PIN);    //声光模块驱动判断
//     // else DL_GPIO_clearPins(GPIO_LED_PORT,GPIO_LED_PIN_LED_PIN);

//     if (data[0]==1 && data[1]==1 && data[2]==1 && data[3]==1 && data[4]==1 ) timebegin=1;  //给小车一个出弯延时，使转向时小车中心位于点上
//     else whiteflag=0;
    
//     if (whiteflag==1)           //在白色区域时，小车根据陀螺仪返回值走直线
//     {
//         ledflag2=0;
//         if(ledflag1==0)
//         {
//             ledflag1=1;
//             ledbegin=1;
//             m++;
//         }

//         if (n%2==0)
//         {
//             if(Yaw<0) bias = 180 - myabs(Yaw);      //当走过白色区域为偶数时，须将+180和-180转化为0+和0-
//             else bias = Yaw - 180;
//         }
//         else if(n%2==1)
//         {
//             bias = Yaw;                         //当走过白色区域为奇数时，不需要转化
//         }
//         flag=0;
//     }
//     else if(whiteflag==0)       //在黑线区域小车根据灰度返回值循迹
//     {
//         ledflag1=0;
//         if(ledflag2==0)
//         {
//             ledflag2=1;
//             ledbegin=1;
//             m++;
//         }

//         if(flag==0)
//         {
//             flag=1;
//             n=n+1;
//         }
//         bias = Get_Error();         //差速为灰度返回值
//         whiteflag=0;
//     }
    
//     targetA = Speed_Middle+bias;
// 	targetB = Speed_Middle-bias;
//     CurrentA = get_encoder_countL();       //左轮当前转速
// 	CurrentB = get_encoder_countR();      //右轮当前转速
// 	Motor_Left  = (int)PWM_Limit(PID_A(CurrentA,targetA),Limit, -Limit);
// 	Motor_Right = (int)PWM_Limit(PID_B(CurrentB,targetB),Limit, -Limit);		//PWM限幅
// 	 lc_printf("%f,%d   ", Yaw,m);
//     lc_printf("%f,%f    ",targetA,targetB);
//     lc_printf("%d,%d\n",Motor_Left,Motor_Right);
//     Set_PWM( Motor_Right,Motor_Left );
// }



int main(void)
{
    // Kp1 = 5;
    // Ki1 = 0;
    // Kd1 = 0;
    SYSCFG_DL_init();
    //  SysTick_Init();
    //   MPU6050_Init();
    encoder_init();
    uart_Init();
    jy61pInit();
    // Interrupt_Init();
    //  lc_printf("start\r\n");
    // while(mpu_dmp_init())
    // {
    //     lc_printf("dmp error\r\n");
    //     delay_ms(200);
    // }
    
    DL_TimerG_startCounter(TIMER_0_INST);
    NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    // PId_Init(&R,13,0.91,0.2,40);
    // PId_Init(&L,4.5,0.9,0.4,60);
    // PId_Init(&R,0,0,0.0,40);
    //  PId_Init(&R,4.5,0.9,0.4,60);
    // PId_Init_tack(&x,9,0,0);
    // delay_ms(20000);
    BEEP();
    DL_GPIO_setPins(GPIOB, MOTOR_STBY_PIN);
    // Set_PWM(500,700);// y   z

//   Set_PWM(-400,400);
  // delay_ms(500);
  // Set_PWM(0,0);
    //  delay_ms(15000);
    //  Yaw = (int)get_angle();
    //    ce();
    //    delay_ms(1000);
    //    Set_PWM(0,0);
    while(1)
{ 

            // error = Get_Error();
            // PWMA = 500+ PID_UPdate(&x,error,0.01);
            // PWMB = 500- PID_UPdate(&x,error,0.01);
            // delay_ms(20000);
         
           Yaw = (int)get_angle();
            // lc_printf("%d,%d,%d,%d,%d,%d,%d,%d\n",P1,P2,P3,P4,P5,P6,P7,P8);   
            //   ce();
            // Control_AB();
            // yaw =yaw +20;
            // yaw = yaw + 22;
            // lc_printf("%f  ,", yaw);  
            // Control_ABCDA();
            // Set_PWM(PWMA, PWMB);
            if(flag_en)         //使能控制开启
            {
                Follow_Route(); //路径控制总函数函数
                // /* LED闪烁 */
                LED_Sound();
            }
            
           

    }
}

 void TIMER_0_INST_IRQHandler(void)
 {
      switch( DL_TimerG_getPendingInterrupt(TIMER_0_INST) )
    {
        case DL_TIMER_IIDX_ZERO://如果是0溢出中断
         {
            cnt++;
          
            //  cnt1++; 
            //  cnt2++;
            //  if(cnt1==800)
            // {  
            //     motor_mode = MOTOR_STOP;
            //     Set_PWM(600,0);
            //     delay_ms(500);
            // }
            //   if(cnt2==1600)
            // {  
            //   motor_mode = MOTOR_STOP;
            //    delay_ms(1000);
            //    Set_PWM(500,0);
            //      delay_ms(500);
            //     // Set_PWM(500,550);
            //     //  delay_ms(500);

            // }
            if(cnt == 10)
            {

            cnt = 0;
            // encoder_update(); 
          
            // Read_Encoder();
              if(flag == 0 || flag_en == 0 || mode == 0)      Set_PWM(0,0);
             else if(flag_en)                                Control();
            // updata();  
            
        //    if(timebegin==1)
        //     {
        //         if (timenum==5)
        //         {
        //             whiteflag=1;
        //             timebegin=0;
        //             timenum=0;
        //         }
        //         timenum++;

        //     }
            
        //         if (ledbegin==1)
        //     {
        //         ledflag=1;
        //         if (lednum==10)
        //         {
        //             ledflag=0;
        //             ledbegin=0;
        //             lednum=0;
        //         }
        //         lednum++;
        //     }



            // mode_chack();        
           
        //            //速度环
        //  if( motor_mode == MOTOR_SPEED )
        //  {
            
        //     // PWMA = PId_calc(&R,get_encoder_countR());
        //     // PWMB = PId_calc(&L,get_encoder_countL());  
        //     Set_PWM(PWMA,PWMB);
        //  }
        // if(motor_mode == MOTOR_XUNJI)
        // { 
          
        //     //  DL_GPIO_setPins(GPIOB, MOTOR_STBY_PIN);
        // //      xunji();
        // }
            }
            break;
            }
        default://其他的定时器中断
            break;
    }
   
 }

void LED_Sound(void)
{
    if(flag_LED)
    {
        LED_High;
        BEEP();
        LED_CNT  = LED_CNT + 1;
        if(LED_CNT >= 1) 
        {
            LED_Low;
            LED_CNT = 0;
            flag_LED = 0;
        }
    }
}