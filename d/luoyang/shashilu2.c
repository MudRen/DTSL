
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
������һ��ɳʯ·�����ڽ����������ң��������˺��٣��Եú���
����
LONG);

  set("exits", ([ 
  "northeast":__DIR__"shashilu1",
  "southwest":__DIR__"guanlu3",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

