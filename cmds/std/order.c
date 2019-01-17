// order.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }
string *check_cmds=({
"sleep","suicide -f","suicide","quit","enroll","adopt","bai",
"exercise","repirate","learn","practice","study","remove",
"wield","wear","unwield","give","get","power","order","exert",
"perform"});

int main(object me, string arg)
{
	string dest, cmd;
	object ob;

	if( me != this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("ָ���ʽ��order <ĳ��> to <ָ��>\n");
	if( !(ob = present(dest, environment(me))) )
		return notify_fail("����û�� " + dest + "��\n");
	if( !living(ob) )
		return notify_fail("����������ִ�����\n");
	if(!userp(ob))
	return notify_fail("��ֻ��������ҡ�\n");
	if(!me->query("shili"))
	return notify_fail("�㻹���ȼ���һ�������ʹ���������ɣ�\n");
	if(me->query("shili/name")!=ob->query("shili/name"))
	return notify_fail("���ǲ���һ�������ģ��޷�����Է���\n");
	if(!me->query("shili/leader")&&ob->query("shili/power")&&
	me->query("shili/power")>=ob->query("shili/power"))
	return notify_fail("�����Ȩ���޷�����Է���\n");
	if(ob->query("shili/leader"))
	return notify_fail("�������·����𣿣�\n");
	if(!me->query("shili/leader")&&ob->query("shili/wide")&&
	me->query("shili/wide")!=ob->query("shili/wide"))
	return notify_fail("���ǲ�ͬ��һ����Χ���޷�����Է���\n");
	if( wiz_level(ob) )
		return notify_fail("����ʦ��Ҳ���������... ...��\n");
	if(!userp(ob))
	return notify_fail("��ֻ��������ҡ�\n");
	if(sizeof(check_cmds)>sizeof(check_cmds-({cmd})))
	return notify_fail("���ָ���ֹʹ�ã�\n");
	if(ob->is_busy())
	return notify_fail("�Է���æ���أ�\n");
	if(ob->is_fighting())
	return notify_fail("�ȶԷ���������˵�ɣ�\n");
	if( userp(ob) )
		log_file("FORCE_PLAYER_BANGHUI", sprintf("[%s] %s forces %s to %s\n",  
			ctime(time()), geteuid(me), geteuid(ob), cmd));
	return ob->force_me(cmd);
}

int help(object me)
{
	write(@Help
ָ���ʽ��order <ĳ��> to <ָ��>

ǿ��ĳ����ĳ��,��������һ�����ģ���������Ҫ��ͬһ���ط�
��ͬʱ��ĵȼ��ȶԷ��ߡ���
Help
	);
	return 1;
}
