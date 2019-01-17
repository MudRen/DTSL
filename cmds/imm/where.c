#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob, where, *ob_list;
        int i;


        if (! str)
                return notify_fail("ָ���ʽ��where <�������>\n"); 

        ob = find_player(str);
        if (! ob) ob = find_living(str);
        if (! ob || ! me->visible(ob))
        {
                str = resolve_path(me->query("cwd"), str);
                ob = find_object(str);
        }

        if (! ob)
                return notify_fail("û���ҵ������Ʒ��\n");

        where = environment(ob);
        if (! where)
                return notify_fail("����˲�֪��������Ү...\n");
        printf(YEL"\n���ó�ˮ��������һ����Ŷ��%s(%s)������...\n\n"NOR,
                (string)ob->name(1),
                (string)ob->query("id"));
"/cmds/std/look"->look_room(me, where); 
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: where <����ID>

���ָ����������֪����Ŀǰ���ڵ�λ��.

HELP );
        return 1;
}

