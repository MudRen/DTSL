
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��ʯ·"NOR);
  set ("long", @LONG
����������ʯ·�������ǴȺ���ի�������ã������ǴȺ���ի����
�䳡���ϱ��Ǽ�����ҡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"pushantang",
  "south":__DIR__"bingqishi",
  "east":__DIR__"lianwuchang",
      ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  set("outdoors","jingzhai");
  set("valid_startroom", 1);
  setup();
 
}

