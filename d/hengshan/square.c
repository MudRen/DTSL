// Room: /d/hengshan/huixiantai.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���Է�");
        set("long", @LONG
�����Ǻ�ɽ������Է�嶥�������︩�Ⱥɽ�������ú��Ժ�ɽ
�ǻ��ı�����ɽ֮�ڡ�
LONG);
        set("exits", ([
           "westdown"  : __DIR__"shandao2",
        ]));
        set("outdoors", "hengshan");
        setup();
        replace_program(ROOM);
}

