
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
��������ɳʯ·����������������������������������Ҳ�ܶࡣ
�кܶ������������ߡ�
LONG);

  set("exits", ([ 
 "south":__DIR__"shashilu2",
 "northeast":__DIR__"dalu1",
 "east":__DIR__"shangang",
        ]));
  set("objects",([
	  __DIR__"npc/shang":1,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

