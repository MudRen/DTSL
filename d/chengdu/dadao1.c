
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "���");
	set("long", @LONG
���ǳɶ��������һ����·�������ǳɶ��Ķ��š�������һƬƬ��
���֣���˵�������˽�ȥ�ܹ��ٳ���������ȥ����ջ���ˡ�
LONG);


	set("exits", ([
		"west" : __DIR__"dadongmen",
		"eastup" : __DIR__"zhandao1",
	]));
        set("outdoors", "�ɶ�");
	setup();
}


