
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ĵ��");
  set ("long", @long
�����������ĳ��Ľ֡�

long);

  set("exits", ([ 
	  "north":__DIR__"changxiajie3",
	  "east":__DIR__"yaodian",
  	  "south":__DIR__"changxiajie5",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

