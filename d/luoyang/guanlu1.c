
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�������������ŵĹ�·����Ȼ�����������ң�����������·���Ǻ�
��ȫ����������������ˡ�
LONG);

  set("exits", ([ 
  "north":__DIR__"baihumen",
  "southwest":__DIR__"guanlu2",

         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

