
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","沙路");
  set ("long", @LONG
这里是一条沙路。南边有一片树林。这里几乎没有人迹，到处一片
荒凉的景象，苍凉之意油然而生。
LONG);

  set("exits", ([ 
 "west":"/d/pengliang/dadao2",
 "southeast":__DIR__"shalu1",
 
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

