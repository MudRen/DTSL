
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֣���ľïʢ����ס�˴󲿷����⡣���µĿ����˱�
����������þ���һ��
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shalu2",
 "south":__DIR__"shulin2",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

