
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","池塘");
  set ("long", @LONG
这里是一个池塘。池塘里养了很多鱼，各种鱼自由自在的游来游去，
几乎让人相信这是个人间仙境。东边是阴癸派辟守玄的住处，里面不时传
来女子的欢笑的声音。
LONG);
  set("exits",([
	  "southwest":__DIR__"qingshilu5",
	  "northeast":__DIR__"mishi",
	  ]));

  set("objects",([
	  __DIR__"npc/dizi3":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","yinkui");

  setup();
 
}
