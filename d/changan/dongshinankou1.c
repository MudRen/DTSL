
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东市南口");
  set ("long", @LONG
这是一个在兴平大街上的丁字路口，路北一条小街通向长安城闻名
的东市－－都会市。那里似乎是长安城最热闹的地方了，因为人还没到，
那喧嚣的声音已经传了过来。
LONG);

  set("exits", ([ 
 "north":__DIR__"dongshixijie5",
 "east":__DIR__"dongshinankou2",
 "west":__DIR__"xpdajie6",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

