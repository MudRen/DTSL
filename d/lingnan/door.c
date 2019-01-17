
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","宋家堡");
  set ("long", @LONG
这里是宋家堡的门口了。宋家堡在岭南是最有势力的一个家族，南
方群雄对宋家无不敬畏有加。宋家堡历代不受官府的约束，掌握有全国
的经济买卖，可说是富贾一方。
LONG);

  set("exits", ([ 

  "enter":__DIR__"changlang1",
  "north":__DIR__"dalu2",
        ]));
  set("objects",([
	  __DIR__"npc/boy":1,
	  __DIR__"npc/girl":1,
	//  "/d/job/banghuijob/songjia":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
"/obj/board/songjia_b.c"->foo();
 
}

 int valid_leave(object ob,string dir)
{
if(!userp(ob)) return 0;
 return ::valid_leave(ob,dir);
}
