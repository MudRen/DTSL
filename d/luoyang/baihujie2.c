
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ľ��");
  set ("long", @LONG
���������������С��ӹ�¥������ңң�������������߾��ǰ׻���
�������������������ַǷ���
LONG);

  set("exits", ([ 
  

  "north":__DIR__"baihujie1",
  "southeast":__DIR__"baihujie3",
  "east":__DIR__"kedian",
  "west":__DIR__"zhonggulou",
         ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

