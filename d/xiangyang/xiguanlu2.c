
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·�����������������š������߾�Ҫ���Ĵ��ľ����ˡ�
��������˲��Ǻܶࡣ
LONG);

  set("exits", ([ 
 "east":__DIR__"xiguanlu1",
 "west":__DIR__"tulu1",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

