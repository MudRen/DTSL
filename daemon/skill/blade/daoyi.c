//����
#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
     int i;
     int last_time;
     object weapon;
     
     
     weapon=me->query_temp("weapon");	
    if(!weapon||weapon->query("skill_type")!="blade")
    return notify_fail("�����޵������ʹ�á����⡹��\n");
        if(weapon->query("flag")==1)
                return notify_fail("�ϵ��ı������ʹ�ã�\n");
     if(me->query_temp("perform_tdbj"))
    return notify_fail("������ʹ���쵶�˾���\n");
    if(!me->query_skill("tiandao-bajue",1))
    return notify_fail("��ѧ���쵶�˾������ʹ�á����⡹��\n");
    if(!me->is_fighting())
    return notify_fail("�����⡹ֻ����ս����ʹ�ã�\n");
    if((int)me->query("max_force")<1200)
    return notify_fail("���������Ϊ̫����!\n");
    if((int)me->query("force")<200)
    return notify_fail("�����������ʹ�ô�����!\n");
    if((int)me->query_skill("tiandao-bajue",1)<100)
    return notify_fail("����쵶�˾�̫���ˣ�\n");
    if((int)me->query_skill("blade",1)<100)
    return notify_fail("��Ļ��������������ң�\n");
    if(me->query_skill("wangdao-jue",1)<100)
    return notify_fail("�����������Ϊ̫���ˣ�\n");
    if(me->query_skill("tiangang-sanjue",1)<100)
    return notify_fail("������������Ϊ̫���ˣ�\n");
    
    if(time()-me->query_temp("perform_busy_daoyi")<15)
    return notify_fail("���������㣬�޷�ʩչ�����⡹��\n");
    
message_vision(HIC"$N"+HIC+"��������������"+weapon->name(me)+HIC+"ֱָ$n"+HIC+"���쵶�˾��ĵ��ⱻ$N"+HIC+"���ӵ����쾡�£�\n"NOR,me,target);
    i=me->query_skill("tiandao-bajue",1)/10;
    me->add_temp("apply/damage",i);
    me->set_temp("perform_tdbj",1);
    me->add("force",-200);
    
    last_time=me->query_skill("tiandao-bajue",1)/3;
    if(last_time>=70) last_time=70;
    
    call_out("rid_attack",last_time,me,i);
    return 1;   
  
}  
 
void rid_attack(object me,int i)
{
  if(!me) return;
  message_vision(HIB"\n$N"+HIB+"�߶�������������ɢ���޷��ڱ��ֵ���ľ����ˡ�\n"NOR,me);
  me->add_temp("apply/damage",-i);
  me->delete_temp("perform_tdbj");
  me->set_temp("perform_busy_daoyi",time());
  return;
}
