
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","饭铺");
  set ("long", @LONG
这间饭铺虽然不大，但是生意倒是非常的好，这里专门提供当地的
各种风味小吃，你找了一张空桌坐了下来，店小二马上拿着一条白毛巾
笑盈盈的向你走了过来。
LONG);

  set("exits", ([ 
 "east":__DIR__"hgdajie3",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer3":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

