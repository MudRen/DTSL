#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","药师工会");
  set ("long", @LONG
这里药师们的工会，关于药师的大小事情都在这里处理，里面放着
各种各类的医学书籍，一个药师正在指导其他的学徒学习这些东西，东
面有一条通往药房的走廊。
LONG);

  set("exits", ([ 
 "out":__DIR__"yaodian",
 "east":__DIR__"yaofang",
       ]));
  set("objects",([
	  "/d/job/yishengjob/yisheng1":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

