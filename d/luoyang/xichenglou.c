
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"������¥"NOR);
  set ("long", @LONG
�����Ǻ����ˮ�����ų�¥��������ˮ�����ĳ��ţ�ƽʱ��׼����
������ֻ��Ϊ����������ר��ͨ����
LONG);

  set("exits", ([ 
  

  "northdown":__DIR__"ximen",
  "southdown":__DIR__"xibianmen2",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

