
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ĵ��");
  set ("long", @long
�����������ĳ��Ľ֡�������һ�����ׯ��

long);

  set("exits", ([ 
	  "north":__DIR__"shennvdi2",
	  "east":__DIR__"caifengdian",
  	  "south":__DIR__"changxiajie2",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

