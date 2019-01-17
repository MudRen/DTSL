
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"报国门"NOR);
  set ("long", @LONG
这里是洛阳的东门。作为繁华的城市，平时有很多人来洛阳城。旁
边有两个边门，有几个全副武装的官兵正站在那里。城门口的官兵正在
那里严密地检查来往的行人。
LONG);

  set("exits", ([ 
  

  "west":__DIR__"xiangwangjie3",
  "north":__DIR__"dongbianmen1",
  "southup":__DIR__"dongchenglou",
  "east":"/d/luoyange/guanlu1",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

