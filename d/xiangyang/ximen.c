
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�����������ǵ������ˡ����������ڵ�����ռ�к���Ҫ��λ�ã���
����ǵļ��Ҳ�Ƿǳ��ϸ�
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie1",
 "west":__DIR__"xiguanlu1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

