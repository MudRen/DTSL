
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·����ʱ�м������ɿ��ܹ��������Ǻ������Ĵ��Ľ�
�紦��
LONG);

  set("exits", ([ 
 "east":__DIR__"xiguanlu2",
 "southwest":__DIR__"tulu2",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

