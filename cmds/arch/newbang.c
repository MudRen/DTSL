// newbang.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string bangname;
	string wiz_status;

	string tmpstr;

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s %s", arg, bangname)!=2 )
		return notify_fail("argument error!\n");

	wiz_status=SECURITY_D->get_status(me) ;

	if (wiz_status != "(admin)") 
		return notify_fail("you r not admin!\n");


                if( !(ob = present(arg, environment(me)))
                ||      !living(ob)
                ||      !ob->is_character()
                ||      ob==me )
			return notify_fail("ob error!\n");
	ob->set("marks/����",bangname);
	tmpstr = "marks/" + bangname ;
	ob->set(tmpstr,"����");
	message_vision( HIW "\n$N�Ѿ��Ѷ�������$n\n\n" NOR, me,ob);	
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : promote <ĳ��> (Ȩ�޵ȼ�)

��������Ȩ�޵ȼ�, (player) (immortal) (apprentice) (wizard)
(arch) (admin)
һ�� admin ������Ȩ�����κεȼ�, �� arch ֻ�������� arch��
HELP
    );
    return 1;
}
