// force.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, cmd;
	object ob;

	if( me != this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("ָ���ʽ��force <ĳ��> to <ָ��>\n");
	if( !(ob = present(dest, environment(me))) )
		return notify_fail("����û�� " + dest + "��\n");
	if( !living(ob) )
		return notify_fail("����������ִ�����\n");
	if( wiz_level(me) <= wiz_level(ob) )
		return notify_fail("��û��ǿ��" + ob->name() + "ִ��ָ���Ȩ����\n");
	if( userp(ob) )
		log_file("FORCE_PLAYER", sprintf("[%s] %s forces %s to %s\n",  
			ctime(time()), geteuid(me), geteuid(ob), cmd));
	message("warn",HIM"\n���� ������"+me->name()+"("+me->query("id")+")�� "+ctime(time())+" ʹ����FORCE���\n\n"+NOR,users());
	
	return ob->force_me(cmd);
}

int help(object me)
{
	write(@Help
ָ���ʽ��force <ĳ��> to <ָ��>

ǿ��ĳ����ĳ��, �������ʦ�ȼ�����ȶԷ���, ���ұ�������ͬһ�������
Help
	);
	return 1;
}
