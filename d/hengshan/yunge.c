// Room: /d/hengshan/yunge.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�Ƹ����");
        set("long", @LONG
����ջ�����͵��Ƹ���š�ǰ����ɽ������Է壬��Ҫ��������
�����ӡ������Բ���ˮ�������������ؽ��泩��
LONG);
        set("exits", ([ 
           "east"      : __DIR__"daziling",
           "northdown" : __DIR__"zhandao",
        ]));
        set("outdoors", "hengshan");
        setup();
        replace_program(ROOM);
}

