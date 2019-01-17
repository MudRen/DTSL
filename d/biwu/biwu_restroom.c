#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_look(string arg);

void create()
{
    set("short", HIY"��Ϣ��"NOR);
    set("long", @LONG
����һ���򵥵���ɫ����͵�С���䣬�����������һЩɳ���������м仹
�м���С������������̨����ս����ʱ��ʱ��̧������������������뱣�ְ�����
LONG );

    set("no_fight",1);
    set("no_beg",1);
    set("no_steal",1);
    set("biwu_room",1);

    set("exits", ([
        "east"  : "/d/biwu/biwu_road",
    ]));

    set("no_clean_up", 0);
    set("coor/x", -70);
        set("coor/y", 10);
        set("coor/z", 0);
        setup();
}

void init()
{
    add_action("do_get","get");
    add_action("do_put","put");
    add_action("do_drop","drop");
}

int do_get()
{
    object me;
    me = this_player();
    if (wizardp(me)) return 0;

    tell_object(me,"�����������ʲô��\n");
    return 1;
}

int do_drop()
{
    object me;
    me = this_player();
    if (wizardp(me)) return 0;

    tell_object(me,"�����������ʲô��\n");
    return 1;
}

int do_put()
{
    object me;
    me = this_player();
    if (wizardp(me)) return 0;

    tell_object(me,"�����������ʲô��\n");
    return 1;
}


