//ɫ�ս���
//ɫ�־�
//by rzy 02.09.21

#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
	int i;
	object weapon;
	weapon=me->query_temp("weapon");
	
	if(!me->is_fighting(target))
		return notify_fail("��ɫ�־���Ҫ��ս����ʩչ��\n");
	if((int)me->query("PKS",1)>=5)
         return notify_fail("���������أ��޷�ʹ�ô˾�����\n");
	if(!weapon || weapon->query("skill_type")!="sword")
		return notify_fail("��ɫ�־���Ҫ�ý���ʩչ��\n");
	if(weapon->query("flag")==1)
        	return notify_fail("�ϵ��ı���������ʹ���ˣ�\n");
	if(me->query_temp("perform_se"))
		return notify_fail("������ʹ�á�ɫ�־�����\n");
	if(!me->query_skill("sekong-jianfa",1))
		return notify_fail("���ᡸɫ�ս��������ʹ�á�ɫ�־�����\n");
	if((int)me->query_skill("qingxin-force",1)<110)
		return notify_fail("��ġ��������ƾ����������ң�\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("���������Ϊ̫����!\n");
	if((int)me->query("force")<500)
		return notify_fail("��Ŀǰ������״��̫���ˣ�\n");
	if((int)me->query_skill("sekong-jianfa",1)<110)
		return notify_fail("��ġ�ɫ�ս�����̫���ˣ�\n");
	if((int)me->query_skill("sword",1)<110)
		return notify_fail("��Ļ��������������ң�\n");
	if(time()-me->query_temp("perform_busy_se")<10)
		return notify_fail("���ʩ�ù���ɫ�־�����������δƽ����\n");
    
	message_vision(HIC"\n$N"+HIC+"�������̬���ϱ仯������"+weapon->name()+HIC+"΢΢̽ǰ��������㽣�⣬ת�ۼ��㽣�⻯��������꣬\n"+
                   "$N"+HIC+"�����ڹ����б��ģ�����壬ȴƾ�������ص���������ɫ�־������ַ�Χ�ڵ�һ�ж������ \n"+
                   "ͬ���ɾ��������������޷����ţ�\n"NOR,me);
		i=me->query_skill("sekong-jianfa",1)/5;
		me->add_temp("apply/armor",i);
		me->set_temp("perform_se",1);
		me->add("force",-200);

	call_out("rid_defence",i,me,i);
	return 1;   
  }  
 
void rid_defence(object me,int i)
{
	if(!me) return;
	message_vision(HIC"\n�������ɢȥ��$N"+HIC+"�������������ɱ��ˡ�\n"NOR,me);
	me->add_temp("apply/armor",-i);
	me->delete_temp("perform_se");
	me->set_temp("perform_busy_se",time());
	return;
}