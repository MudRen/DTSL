
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"游戏新闻发布大厅"NOR);
  set ("long", @LONG
这里是游戏新闻发布大厅，是巫师发布游戏新闻的地方。西边有巫
师的工作服。北边是大唐双龙的排行榜。这里的留言版是新闻发布用的，
如果要发布新闻，请在这里post，如果要巫师内部留言，请到西边的留
言版post。
LONG);

  set("exits", ([ 
 "down":"/d/yangzhou/xiaolou",
 "west":__DIR__"wizroom2",
 "east":__DIR__"courthouse",
 "north":__DIR__"wizroom3",
        ]));

  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/news_b", "???"); 
}

