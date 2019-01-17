
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市西街");
  set ("long", @LONG
你来到了闻名长安的西市－利人市，这里是利人市的西街，到处都
是前来逛集市的人。吆喝声，叫卖声不绝于耳，东面有一家酒楼，西面
是一个珍宝古玩店。
LONG);

  set("exits", ([ 
  "north":__DIR__"xishibeikou1",
  "south":__DIR__"xishixijie2",
 "west":__DIR__"zhenbaozhai",
 "east":__DIR__"zhangjialou",
        ]));
  set("objects",([
         __DIR__"npc/shangren":2,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

