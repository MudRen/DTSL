
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"走廊"NOR);
  set ("long", @LONG
这里是王府的西厢走廊。走廊的北边是一个荷花池，里面荷花绽放
，非常漂亮。不时有几名王府侍卫从这里走过，检查着这里的安全。
LONG);

  set("exits", ([ 

  "east":__DIR__"wangfu_neiting",
  "west":__DIR__"shufang2",
  //"north":"/d/job/tujuejob/luoyang_junjichu",
       ]));
  

  
  set("valid_startroom", 1);
  setup();
 
}

