
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·�������Ѿ��ǰ��յľ����ˡ����ﲢ����ղ���ô
���������˲��Ǻܶࡣ
LONG);

  set("exits", ([ 
 "northeast":"/d/jiujiang/dalu1",
 "southeast":__DIR__"guanlu2",
 "southwest":"/d/jiujiang/shalu3",
 "westup":__DIR__"xiaolu2",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

