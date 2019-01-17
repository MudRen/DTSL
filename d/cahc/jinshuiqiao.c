
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","金水桥");
  set ("long", @LONG
你走在长安的金水桥上。这里宽敞可容四马并驰，建造得鬼斧神功，
气势磅礴，使人生起一夫当关万夫莫敌的感觉。桥下有一条清澈见底、蜿
蜒地川流的小河，河水有时撞在石上，发出淙淙的流水声，悦耳动听。北
边就是李家的王府了。
LONG);

  set("exits", ([ 
 "north":__DIR__"wangfu",
 "south":__DIR__"beijie3",
        ]));
 /*        set("objects",([
         "/d/job/banghuijob/lifa":1,
          ]));*/
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
"/obj/board/lifa_b.c"->foo();
}

