
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��ɽ");
	set("long", @LONG
������һ����ɽ����ɽ��״���죬�������أ��ټ����Ա߻�����ľ
�ĵ�׺����Ū�õ�ȷ�������Ƿ������߾���ʯ�����鷿�������ߣ����
�Ե�ʯ�������ҡ�
LONG
);


	set("exits", ([
		"northeast" :__DIR__"shufang",
                "southwest":__DIR__"beilang2",
                "east":__DIR__"caodi",
                
	]));
	set("objects",([
	    __DIR__"npc/yahuan":1,
	    ]));
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
