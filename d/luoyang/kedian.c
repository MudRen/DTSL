
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","客店");
  set ("long", @LONG
这里是家小客店。由于近日洛阳的人来的很多，所以这家小客店生
意也是非常的好。店小二跑前跑后忙个不停。
LONG);

  set("exits", ([ 
  
	  "west":__DIR__"baihujie2",
	  "enter":__DIR__"shuifang2",
         ]));
  set("objects",([
	  __DIR__"npc/xiaoer2":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="enter")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("店小二拦住了你：客官，您还没给钱呢!\n");
		else return notify_fail("掌柜从里面喊道：客官，给钱再住店啊!\n");
		return ::valid_leave(me,dir);
		return 1;
}
