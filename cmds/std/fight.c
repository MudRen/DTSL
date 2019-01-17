// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;
	seteuid(getuid());
	if( environment(me)->query("no_fight")||
	 environment(me)->query("sleep_room") )
		return notify_fail("���ﲻ׼ս����\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");

        if( me->query_temp("ridee") )
          return notify_fail("�㻹����������!\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if( obj->is_fighting(me) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "�Ѿ��޷�ս���ˡ�\n"); 

	if(obj==me)	return notify_fail("�㲻�ܹ����Լ���\n");
	if( userp(obj) )
	{
	if((object)obj->query_temp("pending/fight")!=me ) {
		message_vision("\n$N����$n˵����" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�����"
			+ RANK_D->query_respect(obj) + "�ĸ��У�\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "�����Ը��ͶԷ����б��ԣ�����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� fight ָ�\n" NOR);
		write(YEL "��춶Է�������ҿ��Ƶ���������ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
		return 1;
	}
	else
                {
	                message_vision("\n$N����$n˵����" 
                        + RANK_D->query_self(me) 
                        + me->name() + "�����"
                        + RANK_D->query_respect(obj) + "�ĸ��У�\n\n", me, obj);
                me->fight_ob(obj);
                obj->fight_ob(me);
                }
	}
	else {
	if( obj->query("can_speak") ) {
		message_vision("\n$N����$n˵����" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�����"
			+ RANK_D->query_respect(obj) + "�ĸ��У�\n\n", me, obj);
		if( !userp(obj) && !obj->accept_fight(me) ) 
		{
		tell_object(me,"������" + obj->name() + "��������������\n");
		return 1;
		}
		else
		{
		me->fight_ob(obj);
		obj->fight_ob(me);
		}
	} else {
		message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}
	}
	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : fight <����>
 
���ָ��������һ������ֽ̡������ǡ��д����ա���������ʽ��ս��������
�㵽Ϊֹ�����ֻ����������������������ˣ����ǲ��������е�  NPC ��ϲ��
��ܣ���������״����ı���Ҫ��ᱻ�ܾ���
 
�������ָ��: kill

PS. ����Է���Ը����������ս������Ȼ���������� kill ָ�ʼս������
    �� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 
