
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","青石路");
  set ("long", @LONG
这里是条青石路。两旁有假山和水池。假山上怪石嶙峋，一望便知
出自高人之手。不时有一些宋家堡弟子从你的身旁匆匆走过。
LONG);

  set("exits", ([ 

  "south":__DIR__"donglang3",
  "north":__DIR__"qingshilu2",
       ]));
  set("objects",([
	  __DIR__"npc/song-shuang":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

