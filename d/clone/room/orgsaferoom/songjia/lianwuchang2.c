
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","练武场");
  set ("long", @LONG
这里是宋家堡的练武场，只见这里兵器齐备，还有梅花桩、沙坑等
练武的东西。有几个宋家堡弟子正在那里练习武艺，呼喝的声音不住的
传来。
LONG);

  set("exits", ([ 
 "west":__DIR__"lianwuchang",

      ]));
  set("valid_startroom", 1);
  set("outdoors","songjia");
  setup();
 
}
