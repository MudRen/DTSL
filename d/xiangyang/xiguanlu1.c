
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������ǵ���������Ĺ�·�����߾��������������ˡ������
������ֻ�к��ٵ��ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"ximen",
 "west":__DIR__"xiguanlu2",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

