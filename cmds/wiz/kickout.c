// kickout.c

#include <ansi.h>
#include <command.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string tmpstr;
	if( me!=this_player(1) ) return 0;
	if( !arg || sscanf(arg, "%s", arg)!=1 ) return notify_fail("��Ҫ��˭�߳�ȥ��\n");
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("��... ���������?\n");
                if (    !living(ob)
                ||      !ob->is_character()
                ||      ob==me )
			return notify_fail("ob error!\n");
	message_vision( HIW "$N��$n�߳��˴��ơ�\n" NOR, me,ob);
	seteuid(ROOT_UID);
        ob->save();
        destruct(ob);
	seteuid(getuid());
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : kickout <ĳ��>

ǿ��ĳ������˳����ơ�
HELP);
    return 1;
}

