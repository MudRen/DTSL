
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������ݳǵĶ����̡����ߴ���һЩ�������������������������
������Ĵ���б����ͬ���������һ����ɫ�ˡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"donghudi3",
 "southwest":__DIR__"nanhudi2",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

