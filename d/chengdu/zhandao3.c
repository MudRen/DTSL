
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
		"southeast" : __DIR__"zhandao2",
		"eastdown" : "/d/xiangyang/tulu4",
	]));
        set("outdoors", "�ɶ�");
	setup();
}


