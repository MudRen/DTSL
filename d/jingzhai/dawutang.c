
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"������"NOR);
  set ("long", @LONG
�����ǴȺ���ի�Ĵ����á��Ⱥ���ի�ĵ����������������ԡ�����
˭���������Ĵ󳹴�����������������Ǻ�����ġ�
LONG);

  set("exits", ([ 
  "south":__DIR__"siguotang",
   ]));
  set("objects",([
	  __DIR__"npc/shi":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

