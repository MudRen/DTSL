
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����ϰ�");
  set ("long", @LONG
�������������ϰ���������һ���ţ����Ե������Ķ����������к�
���������������������ķ�⡣
LONG);

  set("exits", ([ 
 "east":__DIR__"nanan1",
"northeast":__DIR__"hupao",
 "northup":__DIR__"qiao",
 "west":__DIR__"xiaolu1",
 "northeast":__DIR__"hupao",
        ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

