
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"�´���"NOR);
  set ("long", @LONG
�������������ŵı��š�������Ҳ���Խ����������С��м����ٱ�
���������ϸ�ؼ���������ˡ�
LONG);

  set("exits", ([ 
  

  "northup":__DIR__"xichenglou",
  "east":__DIR__"luoshuidi1",
 
         ]));
  set("objects",([
	  __DIR__"npc/bing":1,
	  ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

