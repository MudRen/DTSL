
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·��������ȥ��·���м�����ʬ����������������ͬ��
��ࡣ��ʱ��������������������
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu8",
 "southwest":__DIR__"tulu",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

