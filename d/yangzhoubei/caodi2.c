
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里片草地。南边就是著名的高邮湖。北边是一片树林，也不知道
有没有危险。想到如今的乱世，你不禁加倍小心起来。
LONG);

  set("exits", ([ 
 "north":__DIR__"shulin1",
 "southwest":__DIR__"gaoyouhu",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

