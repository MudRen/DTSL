
#include <ansi.h>
inherit ROOM;

int do_enter(string arg);
void create ()
{
  set ("short","山洞");
  set ("long", @LONG
这里是一山洞。据说这里盛产矿石，许多人都来这里采矿，来打造
兵器。
LONG);
  set("objects",([
	  __DIR__"obj/iron":1,
	  ]));
 set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_enter",({"enter","zuan"}));
}

int do_enter(string arg)
{
	object me;
	me=this_player();
	if(!arg||(arg!="洞"&&arg!="hole"))
		return notify_fail("你要往哪里钻?\n");
	message_vision("$N看准洞口，朝外面使劲钻去！\n",me);
	me->move(__DIR__"shilin");
	return 1;
}
