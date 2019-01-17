//whois.c

#include <ansi.h>
#include <command.h>
inherit F_DBASE;

int check_name(object who, string arg);

int main(object me, string arg)
{
	int i;
	object *all_user, *named_user;
	
	seteuid(getuid());
	
	if( ! arg )
		return notify_fail("whois <��������>\n");
	
	all_user = users();
	
	named_user = filter_array(all_user, (:check_name:), arg);
	
	i = sizeof(named_user);
	
	switch(i){
	case 0:
		printf("���ߵ�û�˽�%s��\n", arg);
		break;
	case 1:
		printf("%s��Ӣ��������"BOLD"%s��\n"NOR,
			arg, named_user[0]->query("id"));
		break;
	default:
		printf("һ����%s��������ҽ�%s��\n", chinese_number(i), arg);
		while(i --)
			printf(BOLD"%s\n"NOR, named_user[i]->query("id"));
		break;
	}

	return 1;
	
}

int check_name(object who, string arg)
{
	if( who->query("name") == arg )
		return 1;
	return 0;
}

int help(object me)
{
    write(@HELP
ָ���ʽ��whois <��������> 
 
���ָ����Ը�����ҵ��������ֲ����Ӧ��Ӣ�ģ�䡣 
HELP
    );
	return 1;
}

