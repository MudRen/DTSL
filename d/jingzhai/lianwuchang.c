
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"���䳡"NOR);
  set ("long", @LONG
�����ǴȺ���ի�����䳡���Ⱥ���ի��ϰ��������Ϊ�����м�����
����������ϰ���գ��������ţ��������ݡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"suishilu3",
    ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  set("outdoors","jingzhai");
  set("valid_startroom", 1);
  setup();
 
}

