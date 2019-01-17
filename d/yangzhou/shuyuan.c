
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","书院");
  set ("long", @LONG
这里是扬州城的著名的书院，书院的先生白老夫子更是受人景仰的
老师，他的学问在扬州更是出名，据说他的弟子中有很多都做了大官。
只见这里并排放了六排桌子，白老夫子在前面拿着书本认真地朗读，下
面的学生也认真地跟随着朗读，朗朗的读书声充满了学堂。
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie2",
//"north":"/d/quest/csj/tianjing",
       ]));
  set("objects",([
	  __DIR__"npc/bai":1,
	  __DIR__"npc/boy2":2,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

