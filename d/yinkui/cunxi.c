
#include <ansi.h>
inherit ROOM;

int do_zuan(string arg);
void create ()
{
  set ("short","村西");
  set ("long", @LONG
这里是小村子的西面。西边是一望无际的草原。这里几乎没有什么
人，旁边有几棵大树，树枝已经凋零，上面零散地落着几只乌鸦，朝着
天空哑哑地叫着。
LONG);

  set("exits",([
	  "east":__DIR__"cunzhong",
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
	object me;
	me=this_player();
	if(!arg||(arg!="hole"&&arg!="洞"))
		return notify_fail("你要往哪里钻？\n");
	if(!me->query("yingui_pass_ok")&&me->query("combat_exp")<1000000)
	return notify_fail("你钻不进去！\n");
	message_vision("$N朝草丛中的一个洞钻进去！\n",me);
	me->move(__DIR__"caocong2");
	return 1;
}