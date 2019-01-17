
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","安上大街");
  set ("long", @LONG
这是安上大街，南北连接长安城的兴平街和建福门。这条街是长安
的南北向主要大街，长安皇城就在安上北街的西面。街上十分热闹，人
来人往川流不息。西面是皇城的延喜门，东面是一所大宅院。
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie5",
 "south":__DIR__"asdajie4",
 "east":__DIR__"yuwenfu",
 "west":"/d/cahc/yanximen",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

