
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������ʯ����ݵĳ������м���������������æ��������ֻ������
�����˱ǣ��кܶ����õķ��˷����������ϡ��м�������������������
���ʵس��š�
LONG
);


	set("exits", ([
		"south" :__DIR__"xilang2",
		
	]));
	set("objects",([
	    __DIR__"npc/chuzi":1,
	    ]));
	set("resource/water",1);
       set("no_fight",1);
       //set("outdoors", "slwg");
	setup();
}
