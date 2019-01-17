
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","洛阳坊");
  set ("long", @long
洛阳地势宽大，除了东北面是杨广的行宫外，东南面则是繁荣的商
业区，而西面则是由洛阳八坊组成的居住区，上三坊主要居住各种公干
官员和大商贾，下五坊则是鱼龙混杂，什么人都有。
long);

  set("exits", ([      
      "northeast":__DIR__"beimen1",
      "south":__DIR__"qinglongjie3",
  ]));

  set("outdoors","luoyang");

  set("valid_startroom", 1);

  setup();
}

