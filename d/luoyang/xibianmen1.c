
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"��ȸ��"NOR);
  set ("long", @LONG
�������������ŵ���ȸ�š�������Ҳ���Խ����������С��м�����
�����������ϸ�ؼ���������ˡ�
LONG);

  set("exits", ([ 
  

  "south":__DIR__"ximen",
 
         ]));
  set("objects",([
	  __DIR__"npc/bing":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

