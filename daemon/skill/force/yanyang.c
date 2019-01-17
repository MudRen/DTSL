//������
//����
//modefied by subzero 02/09/21

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill,lvl;

	if ((int)me->query_skill("yanyang-dafa", 1) < 160)
		return notify_fail("�����������Ϊ��������������ǿ�Լ��Ĺ�������\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("���������Ϊ̫��������ɡ�\n");
	if( (int)me->query("force") < 500 ) 
		return notify_fail("�������������\n");
	if (me->query_temp("xs/yanyang"))
		return notify_fail("���Ѿ������������ӹ�������\n"); 

	skill = me->query_skill("yanyang-dafa",1)/4;
	lvl = me->query_skill("yanyang-dafa",1)/20;
          if(wizardp(me)) tell_object(me,sprintf("add damage: %d\n",skill));

	message_vision(HIR"\n$NǱ�������󷨱鲿ȫ����ɫ����������һ��ĺ��Σ�\n" NOR, me);

        me->add_temp("apply/damage", skill);
	me->set_temp("xs/yanyang", 1);
        me->add("force", -300);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}
void remove_effect(object me, int amount)
{
	if(!me)
	 return;
	 
	if ( (int)me->query_temp("xs/yanyang") ) {
                me->add_temp("apply/damage", -amount);
		me->delete_temp("xs/yanyang");
		message_vision(RED"$N"+RED+"���Ϻ����ȥ��һ���ָֻ��糣��\n" NOR, me);
	}
}
