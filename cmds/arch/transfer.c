// bboard.c


inherit F_CLEAN_UP;
inherit F_SAVE;

int main(object me, string arg)
{
        object user;
	string srcstr, dststr;
	string status;

	status = wizhood(me);
	if( me!=this_player(1) || wiz_level(me) < wiz_level(status) )
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
	
	if (!arg) return 0;
        if (sscanf(arg, "%s %s", srcstr, dststr)!=2) return 0;

	// login data

        seteuid(getuid());
	user = new(LOGIN_OB);
	if( (string)user->set("id", srcstr) != srcstr ) 
		return notify_fail("Failed setting user name.\n");
	if (! user->restore())	return notify_fail("û�������ҡ�\n");
	export_uid(user);

	if( (string)user->set("id", dststr) != dststr ) 
		return notify_fail("Failed setting user name.\n");
        if (!user->save()) return notify_fail("�浵ʧ�ܣ�\n");
	destruct(user);

	// user data

        seteuid(getuid());
	user=new(USER_OB);
        if( (string)user->set("id", srcstr) != srcstr ) 
		return notify_fail("Failed setting user name.\n");
        if (!user->restore())  return notify_fail("û�������ҡ�\n");
        export_uid(user);
        user->setup();

	if( (string)user->set("id", dststr) != dststr ) 
		return notify_fail("Failed setting user name.\n");
	if (!user->save()) return notify_fail("�浵ʧ�ܣ�\n");
        destruct(user);

        tell_object(me, 
		"��� "+srcstr+" ���ݳɹ�ת������� "+dststr+" ��\n");
	return 1;
}	

int help(object me)
{
write(@HELP

ָ���ʽ��transfer <source_id> <dest_id>

��һ����ҵ�����(login, user)ת������һ����ҡ�

HELP
        );
    return 1;
}

