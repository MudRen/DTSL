
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
������ʯ����ݵı����̣���ʹ�ñ����ĵ��ӿ��Ե��������������
����ı������෱�࣬Ӧ�о��С���������ı�����������ֻ��������
��֮�á�
LONG
);


	set("exits", ([
		  "east":__DIR__"zoulang1",
	]));
	set("objects",([
	    __DIR__"npc/tiejiang":1,
	    ]));
       set("no_fight",1);
    
	setup();
}

