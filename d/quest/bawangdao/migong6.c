
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
		"west":__DIR__"migong2",
		"south":__DIR__"migong1",
		"north":__DIR__"migong3",
		
	]));
	
  	setup();
}
