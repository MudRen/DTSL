
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","侧园");
  set ("long", @LONG
这里是一个侧园。园中种了各种花草，美不胜收。这里的花的品种
不是很多，但是种了很多珍贵的药材。各种花五彩缤纷，色彩艳丽，让
人赏心悦目。花园的围杆花纹奇特，必定是出自成都著名工匠之手。
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"zhutang",
	  "southeast":__DIR__"xiaojing1",
      ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
