#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_look(string arg);

void create()
{
    set("short", HIY"�������"NOR);
    set("long", @LONG
����һ����ɫ�����ȣ�������һ�����������ȣ���ͷ���Ǳ����������̶��
��������ͨ����̨����һ���ߵͣ������������̶�����������е�ʥ�ء������
������ʮ����ֽ�񣬸����������������������
LONG );

    set("no_fight",1);
    set("no_beg",1);
    set("no_steal",1);

    set("exits", ([
        "north" : "/d/city/biwu_road",
        "south" : "/d/city/wudao1",
    ]));

    set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        int i;
        mapping conditions;
        object *inv;
 
        if (dir != "north") return 1;

        if (mapp(conditions = me->query_condition()))
               return notify_fail("�Բ����������״�����ã����ܽ��룡\n");

        if (me->query("eff_kee") < me->query("max_kee") ) 
               return notify_fail("�Բ��������Ѫ�����ˣ����ܽ��룡\n");

        if (me->query("eff_gin") < me->query("max_gin"))
               return notify_fail("�Բ�����ľ��������ˣ����ܽ��룡\n");

        inv = deep_inventory(me);
        for (i = 0; i < sizeof(inv); i++)
        {
                if (! userp(inv[i])) continue;
                tell_object(me, "�㱳����˭�����������£�\n");
                return 0;
        }

        inv = 0;
        return 1;
}

