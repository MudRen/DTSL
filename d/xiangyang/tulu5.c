
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����Ѿ��Ǻ��ϵľ����ˡ�����һ����·���������������ˣ���ʱ
�м������ɿ��ܹ����������
LONG);

  set("exits", ([ 

  "southwest":__DIR__"tulu6",
  "north":__DIR__"jiangnan",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

