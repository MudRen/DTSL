// Room: /d/hengshan/beiyuemiao.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������Ǹ�ΡΡ׳�۵Ĺ������ɽ�����أ����и��ϣ�����ʯ��
���㡣�����Ǳ����������ߵ� "����" ��
LONG);
        set("exits", ([
           "east"      : __DIR__"kutianjing",
           "west"      : __DIR__"jijiaoshi",
           "northup"   : __DIR__"beiyuedian",
           "southdown" : __DIR__"guolaoling",
        ]));
/*	set("objects", ([
		__DIR__"npc/dao" : 1,
	]));*/
        setup();
        replace_program(ROOM);
}

