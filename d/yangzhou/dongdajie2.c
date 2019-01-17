
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是扬州城的东大街.这里比较清净.北面是扬州的一家书院。从
这里可以听到里面朗朗的读书声。书院的先生是扬州有名的白老夫子，
虽然战乱连年，但是还有很多人送自己的孩子来这里读书。南边是扬州
的月老亭，那里成就了许多武林的姻缘。
LONG);

  set("exits", ([ 
 "east":__DIR__"dongdajie3",
 "southwest":__DIR__"dongdajie1",
 "north":__DIR__"shuyuan",
 "south":__DIR__"yuelaoting",
        ]));
  set("objects",([
	  __DIR__"npc/boy":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

