
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�����Ǻ��ݵ����š�����������ʤ�أ�������������˺ܶࡣ����
�������ٱ����ڼ�������������ˡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"nandajie2",
  "south":"/d/dongming/dalu4",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

