
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ�����Ĵ�·���ϱ߾��ǺϷʵı����ˡ��������������
�����ֵ����������������Ҳ����������
LONG);

  set("exits", ([ 
 "northeast":__DIR__"dalu1",
 "south":"/d/hefei/beimen",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

