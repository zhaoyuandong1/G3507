#include "uart.h"
#include "board.h"
#include "ti_msp_dl_config.h"
#include "PID1.h"
#include <stdint.h>
#include <machine/_stdint.h>

uint8_t RxBuffer[1];//串口接收缓冲
uint8_t RxLine = 0;//指令长度
uint8_t DataBuff[200];//指令内容
int  uart_data = 0;
void uart_Init(void)
{
      NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
  NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
} 

float Get_Data(void)
{
    uint8_t data_Start_Num = 0; // 记录数据位开始的地方
    uint8_t data_End_Num = 0; // 记录数据位结束的地方
    uint8_t data_Num = 0; // 记录数据位数
    uint8_t minus_Flag = 0; // 判断是不是负数
    float data_return = 0; // 解析得到的数据
    for(uint8_t i=0;i<200;i++) // 查找等号和感叹号的位置
    {
        if(DataBuff[i] == '=') data_Start_Num = i + 1; // +1是直接定位到数据起始位
        if(DataBuff[i] == '!')
        {
            data_End_Num = i - 1;
            break;
        }
    }
    if(DataBuff[data_Start_Num] == '-') // 如果是负数
    {
        data_Start_Num += 1; // 后移一位到数据位
        minus_Flag = 1; // 负数flag
    }
    data_Num = data_End_Num - data_Start_Num + 1;
    if(data_Num == 4) // 数据共4位
    {
        data_return = (DataBuff[data_Start_Num]-48)  + (DataBuff[data_Start_Num+2]-48)*0.1f +
                (DataBuff[data_Start_Num+3]-48)*0.01f;
    }
    else if(data_Num == 5) // 数据共5位
    {
        data_return = (DataBuff[data_Start_Num]-48)*10 + (DataBuff[data_Start_Num+1]-48) + (DataBuff[data_Start_Num+3]-48)*0.1f +
                (DataBuff[data_Start_Num+4]-48)*0.01f;
    }
    else if(data_Num == 6) // 数据共6位
    {
        data_return = (DataBuff[data_Start_Num]-48)*100 + (DataBuff[data_Start_Num+1]-48)*10 + (DataBuff[data_Start_Num+2]-48) +
                (DataBuff[data_Start_Num+4]-48)*0.1f + (DataBuff[data_Start_Num+5]-48)*0.01f;
    }
    if(minus_Flag == 1)  data_return = -data_return;
//    printf("data=%.2f\r\n",data_return);
    return data_return;
}

/*
 * 根据串口信息进行PID调参
 */
void UART_PID_Adjust(int num)
{
    float data_Get = Get_Data(); // 存放接收到的数据
//    printf("data=%.2f\r\n",data_Get);
    if(num == 1)//左边电机
    {
        // if(DataBuff[0]=='P' && DataBuff[1]=='1') // 位置环P
        //     pid_l_position.kp = data_Get;
        // else if(DataBuff[0]=='I' && DataBuff[1]=='1') // 位置环I
        //     pid_l_position.ki = data_Get;
        // else if(DataBuff[0]=='D' && DataBuff[1]=='1') // 位置环D
        //     pid_l_position.kd = data_Get;
         if(DataBuff[0]=='P' && DataBuff[1]=='2') // 速度环P
          L.Kp = data_Get;
        else if(DataBuff[0]=='I' && DataBuff[1]=='2') // 速度环I
            L.Ki = data_Get;
        else if(DataBuff[0]=='D' && DataBuff[1]=='2') // 速度环D
            L.Kd = data_Get;
        else if((DataBuff[0]=='S' && DataBuff[1]=='p') && DataBuff[2]=='e') //目标速度
            L.target = data_Get;
    //     else if((DataBuff[0]=='P' && DataBuff[1]=='o') && DataBuff[2]=='s') //目标位置
    //         L_Target_Position = data_Get;
    }
    else if(num == 0) // 右边电机
    {
        // if(DataBuff[0]=='P' && DataBuff[1]=='1') // 位置环P
        //     pid_r_position.kp = data_Get;
        // else if(DataBuff[0]=='I' && DataBuff[1]=='1') // 位置环I
        //     pid_r_position.ki = data_Get;
        // else if(DataBuff[0]=='D' && DataBuff[1]=='1') // 位置环D
        //     pid_r_position.kd = data_Get;
         if(DataBuff[0]=='P' && DataBuff[1]=='2') // 速度环P
            R.Kd = data_Get;
        else if(DataBuff[0]=='I' && DataBuff[1]=='2') // 速度环I
            R.Ki = data_Get;
        else if(DataBuff[0]=='D' && DataBuff[1]=='2') // 速度环D
            R.Kd = data_Get;
        else if((DataBuff[0]=='S' && DataBuff[1]=='p') && DataBuff[2]=='e') //目标速度
            R.target = data_Get;
        // else if((DataBuff[0]=='P' && DataBuff[1]=='o') && DataBuff[2]=='s') //目标位置
        //     R_Target_Position = data_Get;
    }
    
}
static void uart0_sendChar(uint8_t dat)
{
    //当串口0忙的时候等待，不忙的时候再发送传进来的字符
    while( DL_UART_isBusy(UART_0_INST) == true );

    //发送单个字符
    DL_UART_Main_transmitData(UART_0_INST, dat);
}
// static void uart0_sChar(uint8_t dat)
// {
//     //当串口0忙的时候等待，不忙的时候再发送传进来的字符
//     while( DL_UART_isBusy(UART_0_INST) == true );

//     //发送单个字符
//     DL_UART_Main_transmitData(UART_0_INST, dat);
// }
// void UART_0_INST_IRQHandler()
// {

//   switch( DL_UART_getPendingInterrupt(UART_0_INST) )
//     {
//         case DL_UART_IIDX_RX://如果是接收中断
//             //将发送过来的数据保存在变量中
//             uart_data = DL_UART_Main_receiveData(UART_0_INST);        
//                 L.Kp+=uart_data;

//             //将保存的数据再发送出去
//             uart0_sChar(uart_data);
//             break;

//         default://其他的串口中断
//             break;
//     }


// }
