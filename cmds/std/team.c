// team.c
// last modify by dsm 2/7/99
// last modified by yanyan.for dtsl.
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *t;
	string team_name;
	team_name=me->query_temp("team_mark/name");
	
	if( !arg ) {
		if(!team_name) return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
		write("��Ķ��������ǣ�"+team_name+"��");
		if(!pointerp(t = me->query_team()) ) 
			return notify_fail("�����ڶ����еĳ�Աֻ�����Լ���\n");
		write("�����ڶ����еĳ�Ա�У�\n  " + implode(t->name(1), "\n  ") + "��\n");
		return 1;
	}
	if( arg=="with" ) return notify_fail("�����˭��Ϊ��飿\n");
	if( arg=="form" ) return notify_fail("������֯ʲô���ͣ�\n");
	if( arg=="dismiss" ) {
		if( !team_name)
			return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
		if( !pointerp(t = me->query_team()) ) {
			write("�㽫"+team_name+"��ɢ�ˡ�\n");
			me->delete_temp("team_mark");
			return 1;
			}
		if( me->is_team_leader() ) {
			message("team", me->name(1) + "��"+team_name+"��ɢ�ˡ�\n", t, me);
			write("�㽫"+team_name+"��ɢ�ˡ�\n");
		} else {
			message("team", me->name(1) + "��������"+team_name+"��\n", t, me);
			write("��������"+team_name+"��\n");
		}
		me->delete_temp("team_mark");
		me->delete_temp("pending_team");
		me->dismiss_team();
		return 1;
	}
	if( arg=="create") {
		if (team_name) return notify_fail("��������������ڵĶ��顣\n");
		me->set_temp("team_mark/name",me->name()+"�Ķ���");
		message_vision("$N������һ�����飬��Ϊ��"+me->name()+"�Ķ��顣\n",me);
		return 1;
	
	}
	if( sscanf(arg, "create %s", arg)==1 ) {
		if (team_name) return notify_fail("��������뿪���ڵĶ��顣\n");
		me->set_temp("team_mark/name",arg);
		message_vision("$N������һ�����飬��Ϊ��"+arg+"��\n",me );
		return 1;
	
	}
	if( sscanf(arg, "with %s", arg)==1 ) {
		object ob;

		if( !(ob = present(arg, environment(me)))
		||	!living(ob)
		||	!ob->is_character()
		||	ob==me)
			return notify_fail("�����˭��Ϊ��飿\n");
		if(!team_name && me!=ob->query_temp("pending_team")) return notify_fail("����Ҫ�ȴ���һ�����顣\n");
		if( me==ob->query_temp("pending_team") ) {
			me->set_temp("team_mark",ob->query_temp("team_mark"));
			ob->add_team_member(me);
                        message_vision("$N��������$n�Ķ��顣\n", me, ob);
			return 1;
			}
		if( me->is_team_leader() ) {
			message_vision("$N����$n����"+team_name+"��\n", me, ob);
			tell_object(ob, YEL "�����Ը����룬���� team with " + me->query("id") + "\n" NOR);
			me->set_temp("pending_team", ob);
			return 1;
			}
		if( !pointerp(t = me->query_team()) ) {
			message_vision("$N����$n����"+team_name+"��\n", me, ob);
			tell_object(ob, YEL "�����Ը����룬���� team with " + me->query("id") + "\n" NOR);
			me->set_temp("pending_team", ob);
			return 1;
			}
		
			return notify_fail("ֻ�ж����������������˼��롣\n");
	}
	if( sscanf(arg, "talk %s", arg)==1 ) {
		if( !pointerp(t=me->query_team()) )
			return notify_fail("�����ڲ�û�кͱ�����ɶ��飬���߶�����ֻ����һ���ˡ�\n");
		message("team", HIW "�����顿" + me->name(1) + "��" + arg + "\n" NOR, t);
		return 1;
	}
	if( sscanf(arg, "form %s", arg)==1 ) {
		if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
			return notify_fail("�������һ����������������֯���Σ�������������������������ˡ�\n");
		if( !me->query_skill(arg, 1) )
			return notify_fail("����������ûѧ����\n");
		return SKILL_D(arg)->form_array(me);
	}
}

int help(object me)
{
	write(@HELP
����ָ��ʹ�÷���:

team create <����> -����һ�����顣���û�����ƣ�����Ĭ��ֵ(XXX�Ķ���)��
team with <ĳ��>  - ��ĳ����ɶ���. ����Ҫ˫����ͬ�����Ż���Ч��
team dismiss      - �뿪����. ���´�ָ��������, ������������ɢ��
team talk <ѶϢ>  - ����������������̸��, ������ tt <ѶϢ> �����
team form <��>  - �����������ѧ���󷨵Ļ������Խ������еĳ�Ա��֯��
                   ĳ�����Σ�������ε�״ֻ̬Ҫ����һ�ƶ��ͻ�����

ֱ���� team ָ��ʱ�����ʾ��Ŀǰ�Ƿ��м�����鼰��Ա������

ע: team �� follow �Ƕ����ģ��㲻һ��Ҫ follow ��������䡣
HELP
	);
	return 1;
}
