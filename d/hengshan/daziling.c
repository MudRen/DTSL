// Room: /d/hengshan/daziling.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������ɽ����֮·��ʯ�������� "����" ���֣��߿����ɣ�
�����پ��������ۻ롣
LONG);
        set("exits", ([ 
           "west"      : __DIR__"yunge",
           "northeast" : __DIR__"hufengkou",
           "southdown" : "/d/taiyuan/sroad5",
        ]));
        set("outdoors", "hengshan");
        setup();
        replace_program(ROOM);
}

