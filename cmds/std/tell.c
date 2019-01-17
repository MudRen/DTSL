// tell.c
// Last modified by Gmm@Jianghu 1999-8-21

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;
int help(object me);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	string name, refuse_name;
	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
	if(environment(me)->query("no_tell")&&!wizardp(me))
	  if(stringp(environment(me)->query("no_tell")))
	    return notify_fail(environment(me)->query("no_tell"));
	  else return notify_fail("���ﲻ׼������\n");
	if( sscanf(target, "%s@%s", target, mud)==2 )
	{
		GTELL->send_gtell(mud, target, me, msg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}
	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
	if(obj->query("env/block_tell"))
	return notify_fail("�Է����ڲ���ͱ���˵����\n");
	name = (string) me->query("id");
	refuse_name = (string) obj->query("env/no_tell");
	if( refuse_name == "all" || refuse_name == name)
	return notify_fail("�����ѹر��ˣԣţ̣�Ƶ����\n");
	write("�����" + obj->name(1) + "��"+BCYN+HIY + msg + "\n" NOR);
	tell_object(obj, sprintf("%s�����㣺"+BCYN+HIY+"%s\n" NOR, me->name(1)+"("+me->query("id")+")", msg));
	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;
	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIY "%s(%s@%s)�����㣺%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIY "%s@%s �����㣺%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

����������ָ��������ط���ʹ����˵����

�������ָ�reply
HELP
	);
	return 1;
}
