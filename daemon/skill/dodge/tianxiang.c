
#include <ansi.h>
inherit SSERVER;

int perform(object me,object target)
{
  
  int dodge;
  string msg;
 
  if( me->query_skill("jiuying-dodge",1)<150)
  return notify_fail("�����ӥ���軹�����ң��޷�ʩչ�����衹��\n");
  if( me->query_skill("dodge",1)<150)
  return notify_fail("��Ļ����Ṧ�������ң��޷�ʩչ�����衹��\n");
 
  if(me->query_temp("perform_tianxiang"))
  return notify_fail("������ʹ�á����衹��\n");
  if(time()-me->query_temp("perform_tianxiang_busy")<10)
      return notify_fail("����ʩչ�����衹��Ҫ������������֧�֣�����Ϊ������������У�\n");
  if(me->query("force")<200)
  return notify_fail("����������㣡\n");
  
  me->add("force",-200);
  
  msg=HIY"\n$N"+HIY+"����ͻȻ�鶯�������������Ϸ��е���ӥһ�㣡\n"NOR;
  
     message_vision(msg,me);
  dodge=me->query_skill("jiuying-dodge",1)/5;
  me->set_temp("perform_tianxiang",1);
  me->add_temp("apply/dodge",dodge);
  
  call_out("perform2",dodge*3/6,me,dodge);
  
  return 1;
}

void perform2(object me,int dodge)
{
   if(!me)
    return;
    
   message_vision("\n$N�ջ�����ӥ���衣\n",me);
   
   me->delete_temp("perform_tianxiang");
   me->add_temp("apply/dodge",-dodge);
   me->set_temp("perform_tianxiang_busy",time());
   
   return;
}
