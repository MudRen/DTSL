
#include <room.h>

inherit ROOM;

int do_action(string arg);

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是石龙武馆的练功房。你可以在这里找教头切磋武艺来提高技
能的修为。如果你有什么不明白的，只要象教头询问“切磋”就可以了。
有很多弟子正在这里切磋功夫。
LONG
);


	set("exits", ([
		"north" :__DIR__"fangting",
              
	]));
	set("objects",([
	    __DIR__"npc/jiaotou":2,
	    ]));
       set("no_fight",1);
      // set("outdoors", "slwg");
	setup();
}

void init()
{
  add_action("do_action","qiecuo");
}

#include "get_skill.c"