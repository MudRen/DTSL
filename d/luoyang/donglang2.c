
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"东廊"NOR);
  set ("long", @LONG
这里是东廊。再往东走就是皇帝的寝宫了。这里已经是皇宫的内部
了，所以有很多的卫兵在来回的巡逻。长廊的旁边有一个水池，水面清
晰，可以看到里面有许多鱼在游动。有几个宫女正在池边玩耍。
LONG);

  set("exits", ([ 
  
  "east":__DIR__"liangtai",
  "west":__DIR__"donglang1",

         ]));

  set("objects",([
   __DIR__"npc/guanbing":1,
   __DIR__"npc/taijian1":1,
   ]));
  set("valid_startroom", 1);
  setup();
 
}

