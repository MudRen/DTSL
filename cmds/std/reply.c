// reply.c
// Last modified by Gmm@Jianghu 1999-8-21

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud;
	object obj;

	if( !arg || arg=="" )
		return notify_fail("��Ҫ�ش�ʲ�᣿\n");
        if(environment(me)->query("no_tell")&&!wizardp(me))
	  if(stringp(environment(me)->query("no_tell")))
	    return notify_fail(environment(me)->query("no_tell"));
	  else return notify_fail("���ﲻ׼������\n");
	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("�ղ�û���˺���˵������\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("�ղź���˵�����������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");
	if(obj->query("env/block_tell"))
	return notify_fail("�Է����ڲ���ͱ���˵����\n");
	write("��ش�" + obj->name(1) + "��"+BCYN+HIY + arg + "\n" NOR);
	tell_object(obj, sprintf("%s�ش��㣺"+BCYN+HIY+"%s\n"NOR,
		me->name(1), arg ));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��reply <ѶϢ>

����������ָ��͸ղ��� tell ����˵����ʹ����˵����

see also : tell
HELP
	);
	return 1;
}
