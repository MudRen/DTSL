
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
	
    "west":__DIR__"shennvdi3",
    "northup":__DIR__"dongchenglou",
 	
  ]));
	
  set("objects",([

    __DIR__"npc/bing":1,

  ]));

  set("outdoors","luoyang");

  set("valid_startroom", 1);

  setup();

}