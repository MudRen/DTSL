
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������������һ�ҵ��̡�������ս��������������������������
�˺ܶࡣ�����ϰ�����������������ų�����ˡ�
LONG);

  set("exits", ([ 
	  "east":__DIR__"baihujie4",
         ]));
  set("objects",([
	  __DIR__"npc/zhou":1,
	  ]));

 set("valid_startroom", 1);
  setup();
 
}

