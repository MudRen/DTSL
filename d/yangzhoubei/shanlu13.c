
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。只见一对官兵从你的身旁走过，他们兴高采烈，
看来不知又是哪里的老百姓倒霉了。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu12",
 "southwest":"/d/outyang/xiaolu5",
 "north":"/d/pengliang/nanchengmen",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

