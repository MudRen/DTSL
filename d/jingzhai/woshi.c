
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
�����Ǽ����ҡ��Ⱥ���ի�ĵ��Ӷ�������������Ϣ�����﹩��һ��
�������������������Щ���ˡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"xiuluoyuan",
  
    ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/

  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

