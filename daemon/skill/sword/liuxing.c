//��ת����
//���ǻ���
//by rzy 02.09.23

#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
	int i;
	int last_time;
	object weapon;
	weapon=me->query_temp("weapon");
	
	if(!me->is_fighting(target))
		return notify_fail("�����ǻ��衹Ҫ��ս����ʩչ��\n");
	if(!weapon || weapon->query("skill_type")!="sword")
		return notify_fail("�����ǻ��衹Ҫ�ý���ʩչ��\n");
	if(weapon->query("flag")==1)
        	return notify_fail("�ϵ��ı���������ʹ���ˣ�\n");
	if(me->query_temp("perform_lx"))
		return notify_fail("������ʹ�á����ǻ��衹��\n");
	if(!me->query_skill("jiuzhuan-jianjue",1))
		return notify_fail("�㻹û��ѧ�ᡸ��ת��������\n");
	if((int)me->query_skill("jiuxuan-dafa",1)<110)
		return notify_fail("��ġ������󷨡��������ң�\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("���������Ϊ̫����!\n");
	if((int)me->query("force")<500)
		return notify_fail("��Ŀǰ������״��̫���ˣ�\n");
	if((int)me->query_skill("jiuzhuan-jianjue",1)<110)
		return notify_fail("��ġ���ת������̫���ˣ�\n");
	if((int)me->query_skill("sword",1)<120)
		return notify_fail("��Ļ��������������ң�\n");
	if(time()-me->query_temp("perform_busy_liuxing")<10)
		return notify_fail("���ʩ�ù������ǻ��衹��������δƽ����\n");
	if(me->query_skill("yijian-shu",1)<100)
		return notify_fail("����Ľ�����Ϊ̫���ˣ�\n");
    
	message_vision(HIW"\n$N"+HIW+"�ᵯ��һ������"+weapon->name()+HIW+"��˳��һĨ��"+weapon->name()+HIW+"����һ������֮�����������콣�⣬������\n"+
                   "$N"+HIW+"����Ӱ����һ�����⣬�����������ǣ������޷�ֱ�ӡ�\n"NOR,me);
		i=me->query_skill("jiuzhuan-jianjue",1)/3;
		me->add_temp("apply/armor",i);
		me->set_temp("perform_lx",1);
		me->add("force",-200);
    
    last_time=me->query_skill("jiuzhuan-jianjue",1)/3;
    if(last_time>=70) last_time=70;
    
	call_out("rid_defence",last_time,me,i);
	return 1;   
  }  
 
void rid_defence(object me,int i)
{
	if(!me) return;
	message_vision(HIY"\n$N"+HIY+"�����ϵĹ�â����ɢȥ����Ӱ���ܿ����ˡ�\n"NOR,me);
	me->add_temp("apply/armor",-i);
	me->delete_temp("perform_lx");
	me->set_temp("perform_busy_liuxing",time());
	return;
}