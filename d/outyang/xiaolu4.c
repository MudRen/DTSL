
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·�������ǰ��պͽ��յĽ��紦�����������Ƿ���֮
�أ�������������˽�������������
LONG);

  set("exits", ([ 
 "northwest":__DIR__"xiaolu3",
 "southeast":__DIR__"dalu1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

