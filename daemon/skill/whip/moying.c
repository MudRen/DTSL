//ħӰ
//by rzy 02.09.23
//modify by yanyan 2003.11.14

#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
	int i;
	int last_time;
	object weapon;
	weapon=me->query_temp("weapon");
	
	if(!me->is_fighting(target))
		return notify_fail("������ħӰ��Ҫ��ս����ʩչ��\n");
	if(!weapon || weapon->query("skill_type")!="whip")
		return notify_fail("����û�б��ӣ����ʩչ������ħӰ����\n");
	if(weapon->query("flag")==1)
        	return notify_fail("�ϵ��ı���������ʹ���ˣ�\n");
	if(me->query_temp("perform_moying"))
		return notify_fail("������ʹ�á�����ħӰ����\n");
	if(!me->query_skill("tianmo-dai",1))
		return notify_fail("�㻹û��ѧ�ᡸ��ħ������\n");
	if((int)me->query_skill("tianmo-dafa",1)<110)
		return notify_fail("��ġ���ħ�󷨡��������ң�\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("���������Ϊ̫����!\n");
	if((int)me->query("force")<500)
		return notify_fail("��Ŀǰ������״��̫���ˣ�\n");
	if((int)me->query_skill("tianmo-dai",1)<110)
		return notify_fail("��ġ���ħ����̫���ˣ�\n");
	if((int)me->query_skill("whip",1)<120)
		return notify_fail("��Ļ����޷��������ң�\n");
	if(time()-me->query_temp("perform_busy_moying")<10)
		return notify_fail("���ʩ�ù�������ħӰ����������δƽ����\n");
	
	message_vision(HIB"\n$N"+HIB+"һ�����е�"+weapon->name()+HIB+"����������һ����"+weapon->name()+HIB+"��������һ����ת������\n"+
                   "$N"+HIB+"�������𽥼ӿ죬������ĥ������\n"NOR,me);
	i=me->query_skill("tianmo-dai",1)/3;
	me->add_temp("apply/dodge",i);
	me->set_temp("perform_moying",1);
	me->set_temp("perform_busy",time()-7);//��ֹ����ʩչ����������pfm
	me->add("force",-200);
    
    last_time=me->query_skill("tianmo-dai",1)/3;
    if(last_time>=70) last_time=70;
    
	call_out("rid_defence",last_time,me,i);
	return 1;   
  }  
 
void rid_defence(object me,int i)
{
	if(!me) return;
	message_vision(HIB"\n$N"+HIB+"��Ц��һ��������������������\n"NOR,me);
	me->add_temp("apply/dodge",-i);
	me->delete_temp("perform_moying");
	me->set_temp("perform_busy_moying",time());
	return;
}