
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����������������֡������Ѿ��ܷ����ˡ���ս��ʱ�ڣ�������
�����γ��з������������൱�ķ��������������������������ߣ��Ϳ�
�Ե�������ˡ�
LONG);

  set("exits", ([ 
  
  "west":__DIR__"ximen",
  "east":__DIR__"luoshenjie2",
  "north":__DIR__"yanju",
         ]));
  set("objects",([
	  __DIR__"npc/old":1,
	  ]));
  set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

