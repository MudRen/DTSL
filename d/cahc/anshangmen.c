
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","安上门");
  set ("long", @LONG
安上门位于皇城南面靠东，平时王公贵族门入朝一般都从这里出入
此门相比正面的朱雀门，规模和气势就弱了一些，不过依然是青色大理
石的结构，朱红色的大木门，上面九九排列着八十一个金光闪闪的铜帽。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"tianjie1",
 "southeast":"/d/changan/gmdajie4",
  "west":__DIR__"zhuquemen",
        ]));
  set("objects",([
	  "/d/changan/npc/bing":2,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

