
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"���ķ�"NOR);
  set ("long", @LONG
�����ǴȺ���ի�Ŀ��ķ����Ⱥ���ի�ĵ��Ӷ�Ҫ�������ĵĵ����У�
����һ������֮���������Ҳ�ǴȺ���ի��������ĵط���
LONG);

  set("exits", ([ 

  "south":__DIR__"zoulang1",
    ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/

  
  set("valid_startroom", 1);
  setup();
 
}

