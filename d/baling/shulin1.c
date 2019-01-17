
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片一望无垠林海，每棵树木都有十来丈高，周围阡陌交错，
几十丈高的大树簇在一块，密实的枝叶象一蓬蓬巨伞般伸向天空，把阳
光遮得丝毫也无。远处似乎有几个人在休息。
LONG);

  set("exits", ([ 

  "east":__DIR__"shalu2",
  "southwest":__DIR__"shulin2",
  "west":__DIR__"xiaoxi",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

