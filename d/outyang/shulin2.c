
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
 "north":__DIR__"shulin1",
 "southeast":__DIR__"shulin3",
        ]));
  set("objects",([
	  __DIR__"npc/fox":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

