
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·�������߾Ϳ��Ե������ˡ���ʱ��������ʿ��������
�¡�
LONG);

  set("exits", ([ 
 "south":__DIR__"beiguanlu1",
 "northwest":__DIR__"shashilu1",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

