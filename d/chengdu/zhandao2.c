
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
		"southwest" : __DIR__"zhandao1",
		"northwest" : __DIR__"zhandao3",
	]));
        set("outdoors", "�ɶ�");
	setup();
}


