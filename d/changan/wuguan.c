
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","武馆大门");
  set ("long", @LONG
这里是一个大宅子，门口高悬一个大匾“长安武馆”，立了两个石
狮，你从大门口瞧进去，好象里面人来人往，都很繁忙的样子，门口站
着两个门卫，神情威严。
LONG);

  set("exits", ([ 
 "west":__DIR__"csdajie3",
 "east":__DIR__"wuguan1",
        ]));
set("valid_startroom", 1);
  setup();
 
}

