
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������ǵ�������Ĺ�·���������������ǵ������ˡ������
���˽�������������
LONG);

  set("exits", ([ 
 "northwest":"/d/luoyang/nanmen2",
 "southeast":__DIR__"guanlu2",
 
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

