
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ��ͨ·");
  set ("long", @LONG
������һ��ʯ��ͨ·������ֲ�в��ɴ�أ����������ľ֮�䡣��
ɫ������յ��š�
LONG);

  set("exits", ([ 
  
	  "southwest":__DIR__"qiao",
	  "north":__DIR__"paifang",
         ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
