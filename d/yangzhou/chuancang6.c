
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","后甲板");
  set ("long", @long
这里是画舫的后甲板，从这里可以观赏到瘦西湖美丽的景色。
long);

  set("exits", ([ 
 "south":__DIR__"chuancang5",
 ]));
  set("outdoors","yangzhou");
  set("valid_startroom", 1);
  setup();
 
}

