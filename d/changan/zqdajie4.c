
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","朱雀大街");
  set ("long", @LONG
这里就是长安城最有名的，最宽的主大街－朱雀大街了，它位于长
安城的中轴线上，南面连接明德门，北面直通皇城的朱雀门，阔达四十
丈，两旁均是非常华丽巍峨的建筑，从这里遥望北方的皇城，气势宏伟，
景致壮观。西面是一座宏伟壮观的波斯胡寺。
LONG);

  set("exits", ([ 
 "north":__DIR__"zqdajie2",
 "south":__DIR__"zqdajie1",
 "west":__DIR__"bosihusi",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

