
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","聚义亭");
  set ("long", @LONG
这里是大江联的聚义亭。大江联的人在这里进行结拜仪式。面对滔
滔江水，你的心中不由得生出一股豪壮之气。这里还有一幅对联(lian)。
LONG);

  set("exits", ([ 
	  "south":__DIR__"tulu2",
	      ]));
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("item_desc",([
      "lian":HIG"聚义亭聚义义薄云天\n大江联仗剑剑啸江湖\n"NOR,
       ]));
  set("valid_startroom", 1);
  setup();
  "/obj/sboard/dajiang_b.c"->foo();
}

