 #include "PID.h"
//����PID����
#define VV_KPVALUE          17        //����
#define VV_KIVALUE          5        //΢��
#define VV_KDVALUE          1         //����
#define VV_MAX              7999     //�������ֵ����PWM������ֵ
#define VV_MIN              0         
#define VV_DEADLINE         0x08      //�ٶ�PID������������Χ
/***********
//PID�㷨
***********/

static PID sPID;                      //���PID���� �ṹ��
PID *sptr=&sPID;

void PIDInit(void)
{
  sptr->Vi_Ref=200;              //�ٶ��趨ֵ
  sptr->Vi_FeedBack= 0;               //�ٶȷ���ֵ
  sptr->Vi_PreError=0;                //ǰһ�Σ��ٶ����
  sptr->Vi_PreDerror=0;               //ǰһ���ٶ����֮��
  
  sptr->V_Kp=VV_KPVALUE;
  sptr->V_Ki=VV_KIVALUE;
  sptr->V_Kd=VV_KDVALUE;
  
  sptr->Vl_PreU=0;                    //����������ֵ
}
//pid
signed long speed_pid(int v)
{
  signed long error,d_error,dd_error;
  sptr->Vi_FeedBack=v;
  error=(signed long)(sptr->Vi_Ref-sptr->Vi_FeedBack); //����ƫ��
  
  d_error=error - sptr->Vi_PreError;
  dd_error =d_error - sptr->Vi_PreDerror;
  
  sptr->Vi_PreError= error;           //�洢��ǰƫ��
  sptr->Vi_PreDerror=d_error;        //�洢��ǰ���֮��
  
  sptr->Vl_PreU+=(signed long)(sptr->V_Kp*d_error+sptr->V_Ki*error+sptr->V_Kd*dd_error);
  //�ٶ�PID����
  
  if(sptr->Vl_PreU >= VV_MAX)         //�ٶ�PID����ֹ����������
    sptr->Vl_PreU=VV_MAX;
  else if(sptr->Vl_PreU <= VV_MIN)
    sptr->Vl_PreU = VV_MIN;           //�ٶ�PID����ֹ����������
  else;
  
    return (sptr->Vl_PreU);           //���ص���ռ�ձ� 
}
