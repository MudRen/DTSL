

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ǳɶ��ı������ˡ��ɶ��ش����У�������Ҫ������ս�½�
�١��м����ٱ����ڼ�������İ��ա�
LONG);


	set("exits", ([
		"south" : __DIR__"beidajie4",
		"northeast":"/d/luoyang/guanlu4",
	]));
	set("object",([
		__DIR__"npc/bing":2,
		]));
        set("outdoors", "�ɶ�");
	setup();
}


