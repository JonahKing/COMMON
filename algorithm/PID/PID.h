typedef struct PID                    //�����㷨��������
{
  signed int Vi_Ref;                  //�ٶ�PID���ٶ��趨��Velocity
  signed int Vi_FeedBack;             //�ٶ�PID���ٶȷ���ֵ ��m*50

  signed long Vi_PreError;            //�ٶ�PID ,ǰһ�Σ��ٶ�����Vi_Ref- Vi_FeedBack
  signed long Vi_PreDerror;           //�ٶ�PID ,ǰһ���ٶ����֮�PreDerror- Vi_PreError

  unsigned int V_Kp;                  //�ٶ�PID����Ka=KP
  unsigned int V_Ki;                  //�ٶ�PID����Kb=Kp*(T/Ti)
  unsigned int V_Kd;                  //�ٶ�PID����

  signed long Vl_PreU;                //����������ֵ
}PID;
extern void PIDInit(void);
extern signed long speed_pid(int v);
extern PID *sptr;

