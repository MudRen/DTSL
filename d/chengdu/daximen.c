
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǿ��ǳɶ����������ˡ��ɶ��ش����У�һ������ս�����ţ���
�Ժ��ټ�����ʿ�����м����������ڳ�������ȥ��
LONG);


	set("exits", ([
		"east" : __DIR__"xidajie2",
		"west":__DIR__"wroad1",
	]));
	set("object",([
		__DIR__"npc/bing":2,
		]));
        set("outdoors", "�ɶ�");
	setup();
}



