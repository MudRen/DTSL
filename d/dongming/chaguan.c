
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "���");
	set("long", @LONG
������һ�������Ĳ�ݡ��������д����������ˣ���������ս�ң�
��Ҳ���Ѿ�û���˾�Ӫ�ˡ�
LONG);
	set("exits", ([
		"southeast":__DIR__"shalu2",
		"northwest":__DIR__"shanlu1",
		"north":__DIR__"tulu1",
		"east":"/d/haisha/cunxi",
		]));
		/*
	set("objects",([
		__DIR__"npc/shangren":1,
		]));
		*/
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

