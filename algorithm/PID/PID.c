 #include "PID.h"
//定义PID参数
#define VV_KPVALUE          17        //比例
#define VV_KIVALUE          5        //微分
#define VV_KDVALUE          1         //积分
#define VV_MAX              7999     //返回最大值，是PWM的周期值
#define VV_MIN              0         
#define VV_DEADLINE         0x08      //速度PID，设置死区范围
/***********
//PID算法
***********/

static PID sPID;                      //电机PID控制 结构体
PID *sptr=&sPID;

void PIDInit(void)
{
  sptr->Vi_Ref=200;              //速度设定值
  sptr->Vi_FeedBack= 0;               //速度反馈值
  sptr->Vi_PreError=0;                //前一次，速度误差
  sptr->Vi_PreDerror=0;               //前一次速度误差之差
  
  sptr->V_Kp=VV_KPVALUE;
  sptr->V_Ki=VV_KIVALUE;
  sptr->V_Kd=VV_KDVALUE;
  
  sptr->Vl_PreU=0;                    //电机控制输出值
}
//pid
signed long speed_pid(int v)
{
  signed long error,d_error,dd_error;
  sptr->Vi_FeedBack=v;
  error=(signed long)(sptr->Vi_Ref-sptr->Vi_FeedBack); //计算偏差
  
  d_error=error - sptr->Vi_PreError;
  dd_error =d_error - sptr->Vi_PreDerror;
  
  sptr->Vi_PreError= error;           //存储当前偏差
  sptr->Vi_PreDerror=d_error;        //存储当前误差之差
  
  sptr->Vl_PreU+=(signed long)(sptr->V_Kp*d_error+sptr->V_Ki*error+sptr->V_Kd*dd_error);
  //速度PID计算
  
  if(sptr->Vl_PreU >= VV_MAX)         //速度PID，防止调节最高溢出
    sptr->Vl_PreU=VV_MAX;
  else if(sptr->Vl_PreU <= VV_MIN)
    sptr->Vl_PreU = VV_MIN;           //速度PID，防止调节最低溢出
  else;
  
    return (sptr->Vl_PreU);           //返回调节占空比 
}
