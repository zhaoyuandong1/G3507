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
float pitch =0,roll=0,yaw =0,yawi=0;
int16_t Speed, Location;		//速度，位置
int32_t Get_Encoder_countA,encoderA_cnt,Get_Encoder_countB,encoderB_cnt,PWMA,PWMB;
 int32_t motor_speeda =4,motor_speedb = 4;//电机速度控制，0为停止
 int32_t motor_mode = MOTOR_STOP;//0默认停止  1速度环  2位置环  3循迹
int cnt=0,cnt1=0,cnt2;
 uint16_t t;
 extern PID Tpid;
 int flag=0;

/*定义变量*/
// float Target=5, Actual, Out;			//目标值，实际值，输出值
// float Kp=250, Ki=0.5, Kd;					//比例项，积分项，微分项的权重
// float Error0, Error1, ErrorInt;		//本次误差，上次误差，误差积分

// float Target1=400, Actual1, Out1;			//目标值，实际值，输出值
// float Kp1=0.3, Ki1=0.3, Kd1;					//比例项，积分项，微分项的权重
// float Error01, Error11, ErrorInt1;		//本次误差，上次误差，误差积分


int main(void)
{

    SYSCFG_DL_init();
    // OLED_Init();
    
    // encoder_init();

    // MPU6050_Init();
    uart_Init();
       lc_printf("start\r\n");
    while(mpu_dmp_init())
    {
        lc_printf("dmp error\r\n");
        delay_ms(200);
    }
    
    DL_TimerG_startCounter(TIMER_0_INST);
    NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    // PId_Init(&R,13,0.91,0.2,40);
    PId_Init(&L,4.5,0.9,0.4,60);
    // PId_Init(&R,0,0,0.0,40);
     PId_Init(&R,4.5,0.9,0.4,60);
    // delay_ms(20000);
    // BEEP();
    DL_GPIO_setPins(GPIOB, MOTOR_STBY_PIN);
    // Set_PWM(999,999);// y   z

  // Set_PWM(-400,400);
  // delay_ms(500);
  // Set_PWM(0,0);
    while(1)
    {   

    // DL_GPIO_setPins(LED_PORT,  LED_PIN_0_PIN);
    // UART_PID_Adjust(1);
    // if(cflag == 0)
    //      motor_mode = MOTOR_XUNJI;
    // else if(cflag == 1)
    //        { 
    //          motor_mode =MOTOR_SPEED;
    //        }     
        //获取欧拉角
        // if( mpu_dmp_get_data(&pitch,&roll,&yaw) == 0 )
        // {
        //     // lc_printf("\r\npitch =%d,roll =%d,yaw =%d\r\n", (int)pitch, (int)roll,(int)yaw);
        //     //  lc_printf("%d,%d,%d\n",(int)pitch,(int)roll,(int)yaw);
        //     // lc_printf("\r\nroll =%d\r\n", (int)roll);
        //     // lc_printf("\r\nyaw =%d\r\n", (int)yaw);
        // }
        //  delay_ms(20);
            // error = Get_Error();
            // PWMA = 500 - PID_UPdate();
            // PWMB = 500 + PID_UPdate();
            // Set_PWM(PWMA, PWMB);
            // lc_printf("\r\n encoderA_cnt=%d\r\n", encoderA_cnt);
            // lc_printf("\r\n encoderB_cnt =%d\r\n", encoderB_cnt);
            // lc_printf("\r\nPWMA =%d,", PWMA);
            // lc_printf  // lc_printf("temp:%d,%d\n",GET_temp(),t);("\r\nPWMB\n",PWMB);
              
                //  lc_printf("%f,%f,%f\n",L.Kp,L.Ki,L.ErrorInt);
              //  lc_printf("%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%d,%d\n",L.target,L.Actual,L.out,R.target,R.Actual,R.out,get_encoder_countL(),get_encoder_countR());
            //   lc_printf("%.2f,%.2f,%.2f\n",Target,Actual,Out);
           //  lc_printf("%d,%d,%d,%d,%d\n",data[0],data[1],data[2],data[3],data[4]);
            //  lc_printf("%d,%d\n",PWMA,PWMB);
            //  delay_ms(200);
                 
           
    
            //   delay_ms(500);
        // delay_ms(20);//根据设置的采样率，不可设置延时过大,1);//6*8 “ABC”   
        // OLED_ShowString(0,0,"track",8,0);
  //  OLED_ShowString(0,0,"ABC",8,1);//6*8 “ABC”
        // OLED_ShowString(0,12,"speedB:",12,1);//6*8 “ABC”   
        // OLED_ShowNum(0,16,R2,4,12,1);//6*12 “ABC”
        // OLED_ShowNum(40,12,PWMB,4,12,1);//6*12 “ABC”
        // OLED_Refresh();
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
            encoder_update();
            updata();  
            
            mode_chack();        
           
                   //速度环
         if( motor_mode == MOTOR_SPEED )
         {
            
            PWMA = PId_calc(&R,get_encoder_countR());
            PWMB = PId_calc(&L,get_encoder_countL());  
            Set_PWM(PWMA,PWMB);
         }
        if(motor_mode == MOTOR_XUNJI)
        { 
          
            //  DL_GPIO_setPins(GPIOB, MOTOR_STBY_PIN);
             xunji();
        }
            }
            break;
            }
        default://其他的定时器中断
            break;
    }
   
 }
