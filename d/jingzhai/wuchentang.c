
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"������"NOR);
  set ("long", @LONG
�����ǴȺ���ի�������á���Ҽ���������������Ҳ�����������ġ�
�Ⱥ���ի�ĵ���Ҫʱ���������������Դﵽ������������
LONG);

  set("exits", ([ 

  "south":__DIR__"qusutang",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  
  set("valid_startroom", 1);
  setup();
 
}

