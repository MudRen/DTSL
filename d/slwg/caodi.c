
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������һƬ���̡�����Ĳݵأ���������ǳ�����������Ǽ�ɽ԰
�֣�������ʯ���������ˡ��м���Ѿ�ߴ������߹���΢Ц�����������
����
LONG
);


	set("exits", ([
		"west" :__DIR__"jiashan",
                "east":__DIR__"woshi",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
