#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","拍卖屋");
  set ("long", @LONG
这里是扬州城的拍卖屋。所有拍卖交割都在这里进行，只见屋内有
一巨型柜台，柜台后站着一位老者，他炯炯有神的双目，仿佛一眼就能
看出所有宝物的实际价值。
LONG);

  set("exits", ([
 "out":"/d/yangzhou/guangchang",
        ]));
  set("objects",([
	  __DIR__"paimaishi":1,
	  // "/u/chris/dtangel":1,
	  ]));
  set("no_fight",1);
  set("no_exert",1);
  setup();

}
