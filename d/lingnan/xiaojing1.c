
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
��������С������������ϸ���Сʯ���������ĵ��ţ��㲻��С��
������������һ��ͷ���
LONG);

  set("exits", ([ 

  "north":__DIR__"houbao",
 "southeast":__DIR__"xiaojing2",
 "east":__DIR__"kefang",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

