
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"������"NOR);
  set ("long", @LONG
���������������š���Ϊ�����ĳ��У�ƽʱ�кܶ����������ǡ���
�����������ţ��м���ȫ����װ�Ĺٱ���վ��������ſڵĹٱ�����
�������ܵؼ�����������ˡ�
LONG);

  set("exits", ([ 
	  "north":__DIR__"nanjie4",
  "west":__DIR__"baihumen",
  "east":__DIR__"nanmen2",
  "south":"/d/xiangyang/dalu2",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

