
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"¥��"NOR);
  set ("long", @LONG
������С¥��һ�����ӡ�����װ�εĲ������������Եó������ף�
���ɲ�����
LONG);

  set("exits", ([ 

	  "down":__DIR__"xiaolou",
 ]));

set("objects",([ __DIR__"npc/lumiaozi":1,]));
  
  set("valid_startroom", 1);
  setup();
 
}

