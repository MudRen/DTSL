
#include <ansi.h>
inherit ROOM;
#include <job_money.h>

void create ()
{
  set ("short","小巷");
  set ("long", @LONG
这里是条小巷。平时有很多地痞流氓聚集在这里。
LONG);

  set("exits", ([ 

  "north":"/d/baling/dongjie1",
     ]));
 set("objects",([
	 "/d/baling/npc/liumang":1,
	 "/d/baling/npc/liumang2":1,
	 ]));
set("outdoors","baling");
  set("valid_startroom", 1);
  setup();
 
}

