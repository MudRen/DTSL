
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"������"NOR);
  set ("long", @LONG
�����������Ķ��ŵı��š��м����ٱ�����������������������
���Ա߻���һ������������ָ�ֻ��ţ�����ʮ�㡣
LONG);

  set("exits", ([ 
  

  "southwest":__DIR__"xiangwangjie3",
  "south":__DIR__"dongmen",
 
 
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

