
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·���ϱ߾��������ı����ˡ����������������ļ�����
�ˡ�
LONG);

  set("exits", ([ 
 "south":__DIR__"beimen",
 "north":__DIR__"beiguanlu2",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

