

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","太极广场");
  set ("long", @LONG
太极广场是位于太极殿前面的巨大的广场，全部由汉白玉石铺成，
凡重大时刻，天子在这里检阅文武百官。　远处太极殿耸出的殿顶，在
阳光中，更是气象万千，代表着大唐皇朝权力的极峰。
LONG);

  set("exits", ([ 
 "north":__DIR__"taijimen",
 "south":__DIR__"chengtianmen",
        ]));
 
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

