
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ǹ������ꡣ��������ս���������������������ر�á���
��������˵ط��Ÿ��ֱ������������ֵ��ȡ����ܵ�¯�𿾵���ֱ����
�����������������ô�򣬺ܿ������һ������Ҫ��¯�ˡ�
LONG);

  set("exits", ([ 

  "east":__DIR__"nanjie3",

         ]));
  set("objects",([
	  __DIR__"npc/tiejiang":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

