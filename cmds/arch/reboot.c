// reboot.c

#include <login.h>
#include <ansi.h>
#include <obj.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object npc;
        int i;
        
	if( me != this_player(1) ) return 0;
	
	if( SECURITY_D->get_wiz_level(me) < SECURITY_D->get_wiz_level("(arch)"))
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������" + MUD_NAME + "\n");
        if(!arg||sscanf(arg,"%d",i)!=1)
         i=1;
        if(i>20)
        return notify_fail("ʱ��Ҳ̫���˰ɣ���\n");
	seteuid(getuid());

        message("system",
                HIY    "����˫����DAtang ShuangLong������"+HIR+chinese_number(i)+HIY+"���Ӻ������������ңţ£ϣϣԣ���\n\n" NOR,
                users() );
        call_out("countdown", 60,i);
        return 1;
}

private void countdown(int min)
{
 int i;object *ob;
	min--;
	if( min ) {
		message("system",
                        HIR     "\t\t����˫����DAtang ShuangLong����" + chinese_number(min) + "���Ӻ������������ңţ£ϣϣԣ���\n\n"NOR,
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
                        HIW "����˫����DAtang ShuangLong�������������ңţ£ϣϣԣ�������\n"NOR,
			users() );
 ob=users();
 for(i=0;i<sizeof(ob);i++){
 if(!interactive(ob[i])) continue;
ob[i]->delete("busy_time");
ob[i]->save();}
                call_out("do_shutdown",6);
	}
}

private void do_shutdown()
{
	shutdown(0);
}
int help (object me)
{
        write(@HELP
ָ���ʽ: reboot
 
��������Ϸ, ϵͳ�Ὺʼ������ʱ, �������������𶯡�
 
HELP
);
        return 1;
}
 
