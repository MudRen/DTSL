
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","飞天楼阁");
  set ("long", @LONG
这里是扬州的飞天楼阁，据说有人曾经在这里遇见了太上老君，从
而成仙升天。南边是一家破旧的客栈，据说里面总是鬼气森森，很少有
人会去那里。
LONG);

  set("exits", ([ 
 "east":__DIR__"beidajie2",
 "up":"/d/wiz/wizroom",
  "south":__DIR__"hotel",
  "west":"/d/wiz/wizroom4",
        ]));
 
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!wizardp(me)&&dir=="up")
		return notify_fail("你只感到一股神秘的力量阻止你继续上去!\n");
	return ::valid_leave(me,dir);
}

