
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"������"NOR);
  set ("long", @LONG
�����ǴȺ���ի�������á�����ν������գ���������̸�����ס�
���������������ĵ��Ӷ�����Ϊ���ߵġ�������Ҳ�ǴȺ���ի�ĵ���׷
����ռ�Ŀ��֮һ��
LONG);

  set("exits", ([ 

  "west":__DIR__"qusutang",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  
  set("valid_startroom", 1);
  setup();
 
}

