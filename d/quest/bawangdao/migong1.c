
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
这里是一个山洞，里面道路曲折，四通八达，看起来非常复杂。一
不小心就会迷失方向。这里光线很暗，不时有几只蝙蝠从你的头上飞过，
显得更加恐怖。
LONG);

	set("exits", ([
		"east" :__DIR__"migong1",
		"west":__DIR__"migong2",
		"south":__DIR__"migong1",
		"north":__DIR__"migong1",
		"out":"/d/chengdu/wu",
	]));
	
  	setup();
}
