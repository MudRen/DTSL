//by 2001/9/29
//by baimo@dtsl
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg;
	object obj;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
	if( strlen(msg) > 20 ) return notify_fail("��Ҫ��ô����\n");
	obj = find_player(target);
	if (!obj) return notify_fail("��Ҫ����˭��������û("+target+")����˰ɡ�\n");
	CHANNEL_D->do_channel(this_object(),"sys",me->query("id")+"���ڷ������档\n");
	if (wizardp(obj))
		message("system", HIR "�����桿" + me->name(1) +HIR+"("+ me->query("id")
		+ ")��ɧ����ʦ������Ϊ����˲���Ӱ�죬�ٷ����ϳ͡�\n" NOR,users());
	else
		message("system", HIR "�����桿" + obj->name(1) +HIR+"("+ obj->query("id")
		+ ")��"+msg+"������Ϊ����˲���Ӱ�죬�ٷ����ϳ͡�\n" NOR,users());
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��alarm <ĳ��> <ѶϢ>
����������ָ���һЩΥ����Ϸ�������ҡ�
HELP
	);
	return 1;
}
