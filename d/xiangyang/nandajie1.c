
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是襄阳的南大街。东面是一家客栈，店小二正在门口招呼着
来往的行人。有几个人骑着马从你身旁驰过，这里的行人不是很多。
LONG);

  set("exits", ([ 
 "east":__DIR__"yingbinguan",
 "north":__DIR__"guangchang",
 "south":__DIR__"nandajie2",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

