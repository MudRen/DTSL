
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�������壬���뾭��һ�����ͺ���խ���롣�����Կ���������һʯ
�ѣ������㼣�������ߣ������磬���С������㡱���֡���˵�Ǿ�����
���µ��㼣��
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"cuilinggong",
 "westup":__DIR__"lianhuafeng",
 "southup":__DIR__"liandanlu",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
