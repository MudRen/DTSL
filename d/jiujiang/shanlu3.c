
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
你正走在一条崎岖不平的山路上，偶尔听到一阵阵的野兽叫声，头
顶有一些不知名的小鸟在跳来跳去，四周丛林密布，鲜花绿草若隐若现。
宋家堡已经可以清晰的看到了。
LONG);

  set("exits", ([ 
 "north":__DIR__"shanlu2",
 "southwest":__DIR__"shanlu4",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

