
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"老君观"NOR);
  set ("long", @LONG
这里这里就是翠云峰顶的老君观了。从这里可以看到邙山的部分秀
丽的风景。远处的碧云峰也可以遥遥望到。门前挂着一个大牌匾，上面
写着「老君观」三个字。但是庙门破裂，看来已经很久没有人来打理这
里了。
LONG);

  set("exits", ([ 

  "down":__DIR__"shanlu9",
 "enter":__DIR__"tingyuan",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

