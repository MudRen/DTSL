
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֣���ľïʢ����ס�˴󲿷����⡣���µĿ����˱�
����������þ���һ�񡣿���������������������㲻��С��������
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shulin2",
 "southeast":__DIR__"xiaolu1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

