
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
����һ��С�����������ۣ���֪����ͨ��ʲô�ط���������������
������������ľ������˸о��ǳ������
LONG
	);


	set("exits", ([
		"east" :"/d/chengdu/wu",
		"north":__DIR__"xiaojing2",
	]));
       set("outdoors", "�ɶ�");
	setup();
}

