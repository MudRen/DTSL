
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ��ɽ���������·���ۣ���ͨ�˴�������ǳ����ӡ�һ
��С�ľͻ���ʧ����������ߺܰ�����ʱ�м�ֻ��������ͷ�Ϸɹ���
�Եø��ӿֲ���
LONG);

	set("exits", ([
		"east" :__DIR__"migong7",
		"west":__DIR__"migong3",
		"south":__DIR__"migong5",
		"north":__DIR__"migong1",
		"out":"/d/chengdu/wu",
	]));
	
	set("objects",([
	  __DIR__"npc/youniao-juan":1,
	  __DIR__"npc/jinhuan-zhen":1,
	  __DIR__"npc/zhoulaotan":1,
	  __DIR__"npc/dingjiuchong":1,
        ]));
	  
	
  	setup();
}
