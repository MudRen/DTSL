
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��ʯ·"NOR);
  set ("long", @LONG
����������ʯ·���ϱ�ͨ���Ⱥ���ի�ĺ��������ǴȺ���ի��
�����á���ʱ�дȺ���ի�ĵ��Ӻ�����������
LONG);

  set("exits", ([ 

  "north":__DIR__"pushantang",
  "south":__DIR__"houqingdian",
  "east":__DIR__"chufang",
      ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  set("outdoors","jingzhai");
  set("valid_startroom", 1);
  setup();
 
}

