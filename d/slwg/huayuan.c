
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��԰");
	set("long", @LONG
������һ����԰�����ﻨ��Ʒ�ַ��࣬����ȫ�����ص�����Ʒ�֣�
�������׺���쳣Ư�����м���û�µ�Ѿ�����������ͻ����м�������
������Ц���֡�
LONG
);


	set("exits", ([
		"east" :__DIR__"xilang2",
		"southwest":__DIR__"xiuxishi",
                
	]));
	set("objects",([
	    __DIR__"npc/yahuan":1,
	    __DIR__"npc/zhangjiaotou":1,
	    ]));
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
