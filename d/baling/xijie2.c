
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西街");
  set ("long", @LONG
这里是巴绫的西街。西边就是巴陵的西门了，有几个官兵正在那里
盘查着过往的行人。南边有一家客栈，门口挂着的大红灯笼远远就看得
清清楚楚。店小二正在门口热情地招呼着客人。
LONG);

  set("exits", ([ 

  "west":__DIR__"ximen",
  "east":__DIR__"xijie1",
  "south":__DIR__"kezhan",
  "north":__DIR__"yanju",
       ]));
 set("objects",([
 __DIR__"npc/jiyinong":1,
 ]));
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

