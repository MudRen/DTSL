
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "ջ��");
	set("long", @LONG
���������ǽ�����ص�ջ�����׻�˵������ѣ����������족��һ
���Ǹ߳����Ƶ�ɽ�壬һ����������Ԩ��������ջ���ϲ�����Щ���ĵ�
����
LONG);


	set("exits", ([
		"westdown" : __DIR__"dadao1",
		"northeast" : __DIR__"zhandao2",
	]));
        set("outdoors", "�ɶ�");
	setup();
}


