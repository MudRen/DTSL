 
// cat.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
   string file,dir2;

    seteuid(geteuid(me));
   if (!arg) return notify_fail("����Ҫ��ʾ�Ǹ�����?\n");
   file = resolve_path(me->query("cwd"), arg);
   if( file_size(file)<0 ) return notify_fail("û�����������\n");

    dir2= me->query("cwd");

   if( (dir2=="/cmds/wiz/" || dir2=="/cmds/arch/"
    || dir2=="/cmds/adm/" || dir2=="/adm/daemons/"
    || dir2=="/adm/etc/" || dir2=="/feature/" || dir2=="/clone/npc/"
    || dir2=="/data/login/" || dir2=="/data/npc/")
   &&  wiz_level(me) < 5 )
    return notify_fail("�Բ�������ļ������������\n");

    cat(file);
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : cat <����>

��ָ�������ֱ�Ӷ�ȡĳ����֮��ʽ��
HELP
    );
    return 1;
}
