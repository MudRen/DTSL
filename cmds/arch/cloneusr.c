//Cracked by Kafei
//cloneusr.c

inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object user, where;
	string msg;
	if (!arg) return notify_fail("ʲô��\n");
	me = this_player();

	where = environment(me);

	seteuid(arg);
	if (getuid() == ROOT_UID)
		user = new(USER_OB);
	else
		user = new("/kungfu/skill/yanxing-dao/copy/user.c");
	user->set("id", arg);
	user->set("master_id", arg);
	if (!user->restore())
		return notify_fail("û�������ҡ�\n");;
	export_uid(user);
	seteuid(getuid());
	user->set_name(user->name(), ({arg}));
	user->setup();
	if( !stringp(msg = me->query("env/msg_clone")) )
		if ( where->query("outdoors") )
                	msg = "$n�첽���˹�����\n";
		else
			msg = "$n���˹�����\n";

	message_vision(msg + "\n", me, user);
	user->move(where);
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ��cloneusr [id]

������������������һ����ҵģ������
���סʹ�ù�����ذѣ����������� ����
HELP
        );
        return 1;
}
