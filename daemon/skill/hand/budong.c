//��������ӡ��
#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
     int i;
     object weapon;
     
     if(target&&target!=me)
     return notify_fail("��ֻ�ܶ��Լ�ʹ�á���������ӡ����\n");
     
     weapon=me->query_temp("weapon");	
     if(weapon)
     return notify_fail("�������������ʹ�á���������ӡ����\n");
     if(me->query_temp("perform_jzzy"))
    return notify_fail("������ʹ�þ������ԡ�\n");
    if(!me->query_skill("jiuzi-zhenyan",1))
    return notify_fail("��ѧ���������ԡ����ʹ�á���������ӡ����\n");
    if((int)me->query("max_force")<2000)
    return notify_fail("���������Ϊ̫����!\n");
    if((int)me->query("force")<200)
    return notify_fail("�����������ʹ�ô�����!\n");
    if((int)me->query_skill("jiuzi-zhenyan",1)<120)
    return notify_fail("��ľ�������̫���ˣ�\n");
    if((int)me->query_skill("strike",1)<120)
    return notify_fail("��Ļ����Ʒ��������ң�\n");
    
    if(time()-me->query_temp("perform_busy")<5)
    return notify_fail("���������㣬�޷�ʩչ����������ӡ����\n");
    
    message_vision(HIC"$N"+HIC+"��ʩ����������ӡ��ֻ������ɫ�����£����ݲ�\n"+
                   "�������������Ĳ����������뾲�ĸ�ɮ������ׯ�ϣ�\n"+
                   "������һ��˵�����ķ����������϶��γ����ص�������\n"+
                   "�����������ĵ����ȡ�\n"NOR,me);
    i=me->query_skill("jiuzi-zhenyan",1)/2;
    me->add_temp("apply/armor",i);
    me->set_temp("perform_jzzy",1);
    me->add("force",-200);
    
    call_out("rid_defence",i/7,me,i);
    return 1;   
  
}  
 
void rid_defence(object me,int i)
{
  if(!me) return;
  message_vision("\n$N�����˿�������ɫ�糣��\n",me);
  me->add_temp("apply/armor",-i);
  me->delete_temp("perform_jzzy");
  me->set_temp("perform_busy",time());
  return;
}