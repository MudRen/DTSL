//������ӡ��
#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
     int i;
     object weapon;
     
     if(target&&target!=me)
     return notify_fail("��ֻ�ܶ��Լ�ʹ�á�������ӡ����\n");
     
     weapon=me->query_temp("weapon");	
     if(weapon)
     return notify_fail("�������������ʹ�á�������ӡ����\n");
    if(!me->query_skill("jiuzi-zhenyan",1))
    return notify_fail("��ѧ[��������]���ʹ�á�������ӡ����\n");
    if((int)me->query("max_force")<2000)
    return notify_fail("���������Ϊ̫����!\n");
    if((int)me->query("force")<800)
    return notify_fail("�����������ʹ�ô�����!\n");
    if((int)me->query_skill("jiuzi-zhenyan",1)<140)
    return notify_fail("��ľ�������̫���ˣ�\n");
    if((int)me->query_skill("strike",1)<140)
    return notify_fail("��Ļ����Ʒ��������ң�\n");
    if(me->query("eff_kee")>=me->query("max_kee"))
    return notify_fail("������û�������ˣ�û�б�Ҫʹ�ô�����ӡ��\n");
    
    if(time()-me->query_temp("perform_busy")<30)
      return notify_fail("����ʩչ��������ӡ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    message_vision(HIR"$N"+HIR+"����һ���������������ӡ�����Ϻ�����֣�˲��ָ�Ѫɫ��\n"NOR,me);
    
    me->receive_curing("kee",me->query_skill("jiuzi-zhenyan",1)*4);
    me->add("force",-800);
    
    me->set_temp("perform_busy",time());
    return 1;   
  
}  
