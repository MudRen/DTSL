
#include <room.h>

inherit ROOM;

int do_action(string arg);

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是石龙武馆的练武场，是石龙武馆初级弟子学习武功的地方。
你可以在这里和弟子切磋武功。只见这里尘土飞扬，数名弟子正在那里
打得热闹。
LONG
);


	set("exits", ([
		"east" :__DIR__"wuchang1",
		
	]));
	set("objects",([
	     __DIR__"npc/dizi":2,
	    ]));
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}

void init()
{
  add_action("do_action","qiecuo");
}

#include "get_skill1.c"