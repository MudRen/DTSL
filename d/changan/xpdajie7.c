
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兴平大街");
  set ("long", @LONG
你走在兴平大街上，这条大街横贯长安城东西，东连延兴门，西至
延平门，是长安城的主干道之一。四面热热闹闹的，南北通向的大街是
和光大街。
LONG);

  set("exits", ([
 "north":__DIR__"csdajie1",
  "west":__DIR__"dongshinankou2",
 "east":__DIR__"yanxingmen",
        ]));
  set("objects",([
  "/d/tujue/kang":1,
  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

