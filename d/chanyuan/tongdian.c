
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIB"ͭ��"NOR);
  set ("long", @LONG
�����Ǿ�����Ժ��ͭ�����ͭ����������ҪС�ɵö࣬��ȴ��
������������ʮ���ĵ�����е�λ������һ������������ɣ��ߴ��ɰ�
��ͭ������輫��Ľ�ͭ����Ҫ�������ĸ����ɽ��ųɡ�
LONG);

  set("exits", ([ 
	  "east":__DIR__"shilu4",
	  "out":__DIR__"shilu3",
  
         ]));
  set("objects",([
	  __DIR__"npc/liaokong":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

