
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
��������ɳʯ·����������ȥȥֻ�м����ˡ������Ǻ��ϺͰ��յ�
���紦�ˡ�
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shalu1",
 "southeast":__DIR__"shulin1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

