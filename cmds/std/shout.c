// shout.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !wizardp(me) )
		if(me->query("force")<2000)
		return notify_fail("�������������������Х��\n");
	if(!wizardp(me)&&environment(me)->query("no_shout"))
	   if(stringp(environment(me)->query("no_shout")))
	     return notify_fail(environment(me)->query("no_shout"));
	   else return notify_fail("�����ֹ������Х��\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("�����ڽ�ֹ����������\n");
	if(arg==me->query_temp("last_shout_msg"))
	return notify_fail("ͬһ��̨���㺰��ô������ʲô����\n");
	if (!arg) return notify_fail("����Ҫ���ʲô��\n");
	if(!wizardp(me))
	me->add("force",-2000);
	me->set_temp("last_shout_msg",arg);
	shout( HIW + me->name() +HIW+ "������Х��" + arg + NOR + "\n");
	write(HIW + "��������Х��" + arg + NOR + "\n");
	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : shout <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�.
 
see also : tune
HELP
    );
    return 1;
}
 
