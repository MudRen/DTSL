#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_look(string arg);

void create()
{
    set("short", HIY"��̨"NOR);
        set("long", @LONG
����һ���ķ��Ĵ���̨����̨�������һ�ź��Ĳ����ӣ���о���һ��Ũ
���ɱ���Ӳ�����ɢ�������������ڿ����ֱ���������ġ�
LONG );

    set("no_beg",1);
    set("no_steal",1);
    set("biwu_room",1);

    set("objects",([
    ]));

    set("no_clean_up", 0);
    setup();
}

void init()
{
    add_action("do_get","get");
    add_action("do_put","put");
    add_action("do_drop","drop");
    add_action("do_summon","summon");
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

int do_summon()
{
    object me;
    me = this_player();
    if (wizardp(me)) return 0;

    tell_object(me,"�����������ʲô��\n");
    return 1;
}


