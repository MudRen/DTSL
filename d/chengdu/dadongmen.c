
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ǳɶ��Ķ������ˡ��ɶ��ش����У�һ������ս�����ţ���
�Ժ��ټ�����ʿ�����������ճ�������ȥ��
LONG);


	set("exits", ([
        "west" : __DIR__"dongdajie2",
        "south" : __DIR__"nancejie1",
		"east" : __DIR__"dadao1",
	]));
	set("object",([
		__DIR__"npc/bing":2,
		]));
        set("outdoors", "�ɶ�");
	setup();
}


