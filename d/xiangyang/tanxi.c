
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","檀溪");
  set ("long", @LONG
此处就是当年刘皇叔马跃檀溪之处，从此之后才成就了三分天下之
格局。此处地势险峻，三面环山一面邻水，水急山峻，可谓人间仙处。
LONG);

  set("exits", ([ 
 "south":__DIR__"nongtian1",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

