
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·������������������ˣ���������˲��Ǻܶࡣ����
�����Ĵ����������ʿ��
LONG);

  set("exits", ([ 
 "northwest":__DIR__"guanlu1",
 "southeast":__DIR__"shalu1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

