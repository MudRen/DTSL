
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ�����Ĵ�·����·����·�ϵ����˺ܶࡣ��ʱ������
�����������ԴҴҳ۹����ϱ߾��������μұ��ˡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"dalu1",
  "south":__DIR__"door",
  "northeast":"/d/jiujiang/shanlu4",
         ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

