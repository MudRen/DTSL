
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路。从这里可以看到长江汹涌的波涛。这里渐渐显得
有些热闹了。不时有大队的官兵从你的身旁走过，吓得路上的百姓都朝
两边闪去。这里风景秀丽，山水如画，空气清新。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"xiaolu1",
 "south":__DIR__"jiangbei",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

