
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","经房");
  set ("long", @LONG
这里是阴癸派的经房，这里有阴癸派的各种武功秘籍，普通
弟子是不能进来的。
LONG);
  set("exits",([
	  "southwest":__DIR__"chitang",
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

