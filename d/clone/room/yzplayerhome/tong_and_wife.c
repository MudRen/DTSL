
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIG"霜刀居"NOR);
	set("long", @LONG
这里是霜刀居了。这里的男女主人是天龙和嫣然。他夫妇二
二人在江湖上都是颇有名气的武林高手。天龙精通刀法，继承了
岭南「天刀」一派。西边是一个小屋，就是天龙和嫣然的卧室了。
LONG);
    set("exits", ([
	        "east" : __DIR__"nandajie1",
	        "west":__DIR__"tong_wife_woshi",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
