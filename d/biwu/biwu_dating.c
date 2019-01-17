#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_look(string arg);

void create()
{
    set("short", HIY"�������"NOR);
    set("long", @LONG
����һ�����Ĵ󷿼䣬����ǽ����һ���޴����̨(leitai)����̨��һ
�鲼���ڵ�������ʵʵ������һ��Ũ���ɱ����Ȼ�Ӳ�����ɢ�������������ڿ�
���ֱ���������ġ��ڶ���ǽ�ϣ�������ټ���һ������(dabian)��
LONG );

    set("no_fight",1);
    set("no_beg",1);
    set("no_steal",1);
    set("biwu_room",1);

    set("item_desc",([
            "leitai" : "һ�����ķ����Ĵ���̨���������(jump)��ȥ��\n",
    ]));

    set("exits", ([
        "south"  : "/d/biwu/biwu_road",
    ]));

    set("no_clean_up", 0);
    set("coor/x", -60);
        set("coor/y", 20);
        set("coor/z", 0);
        setup();
}

void init()
{
    add_action("do_no","get");
    add_action("do_no","put");
    add_action("do_no","drop");
    add_action("do_no","summon");
    add_action("do_no","eat");
    add_action("do_no","drink");
    add_action("do_no","guard");
    add_action("do_jump","jump");
    add_action("do_look","look");
}

int do_no()
{
    object me;
    me = this_player();
    if (wizardp(me)) return 0;

    tell_object(me,"�����������ʲô��\n");
    return 1;
}

int do_look(string arg)
{
    string msg;
    int i;
    mapping paiming;

    if (arg != "dabian") return 0;
    paiming = COMPETE_D->query_tops();
    msg = HIC "      *          ��       ��       ��       ��          *\n"NOR;
    msg += HIC "-------------------------------------------------------------\n";
    msg += "\n";
    for (i = 0;i < sizeof(paiming);i++)
{
            msg += HIY + "   �����µ�" + chinese_number(i+1) + "�� " + NOR + paiming[i]["title"] + "\n";
            msg += "\n";
}
    msg += HIC "-------------------------------------------------------------\n";
    write(msg);
    return 1;
}

int do_jump(string arg)
{
    object me;

    me = this_player();

    if (arg != "leitai")
    {
            tell_object(me,"��Ҫ������������\n");
            return 1;
    }

    if (wizardp(me))
    {
            tell_object(me,"������ʦ�����ͱ����������ʲô��һ�ڶ��ˣ�\n");
            return 1;
    }

    if (COMPETE_D->join_competition(me)) 
            return 1;
}

