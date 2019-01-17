

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东大寺");
  set ("long", @LONG
东大寺规模宏大，房舍近千，别院处处。放眼所见，这里尽是高阁
石壁，佛彩龙像，绕不一会，已然分不清来时的道路。但见那一尊尊的
石刻似乎都裂著嘴在向你嘿嘿而笑。
LONG);

  set("exits", ([ 
 "west":__DIR__"wxdajie2",
 "east":__DIR__"xiaojing",
]));
 
  set("objects",([
          "d/job/jj/heshang3":2,
	   ]));
  set("valid_startroom", 1);
  setup();
 
}
