
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ĵ��");
  set ("long", @long
�����������ĳ��Ľ֡�

long);

  set("exits", ([ 
	  "north":__DIR__"changxiajie2",
	  "west":__DIR__"liangchang2",
  	  "south":__DIR__"changxiajie4",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

