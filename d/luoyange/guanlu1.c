
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������Ķ��ŵĹ�·�������߿��Ե�����ʦ����������˺ܶ࣬
����Ҫ����������ʿ��
LONG);

  set("exits", ([ 
  "west":"/d/luoyang/dongmen",
  "southeast":__DIR__"guanlu2",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

