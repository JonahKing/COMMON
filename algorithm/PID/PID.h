typedef struct PID                    //定义算法核心数据
{
  signed int Vi_Ref;                  //速度PID，速度设定，Velocity
  signed int Vi_FeedBack;             //速度PID，速度反馈值 ，m*50

  signed long Vi_PreError;            //速度PID ,前一次，速度误差。即Vi_Ref- Vi_FeedBack
  signed long Vi_PreDerror;           //速度PID ,前一次速度误差之差，PreDerror- Vi_PreError

  unsigned int V_Kp;                  //速度PID，，Ka=KP
  unsigned int V_Ki;                  //速度PID，，Kb=Kp*(T/Ti)
  unsigned int V_Kd;                  //速度PID，，

  signed long Vl_PreU;                //电机控制输出值
}PID;
extern void PIDInit(void);
extern signed long speed_pid(int v);
extern PID *sptr;

