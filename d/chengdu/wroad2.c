
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "��·");
	set("long", @LONG
���ǳɶ��������һ����·��������һƬ���֣���˵�ܶ���������
��·��������
LONG);


	set("exits", ([
		"east" : __DIR__"wroad1",
        "west":"/u/kouzhong/youlin1",
	]));
       set("outdoors", "�ɶ�");
	setup();
}



