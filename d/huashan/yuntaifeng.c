
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��̨��");
  set ("long", @LONG
��̨���ǻ�ɽ����֮һ����λ�þӱ����������������������Ϲھ�
�ƣ���ͨ������ΡȻ���㣬������̨�����������̨�塣�山�ٰ��Ʒ壬
��������ɽ����ͨ���������壬�½ӹ���ϿΣ������ͷ�ɼ����ʯƴ�ӣ�
��Ȼ��ɡ�
LONG);

  set("exits", ([ 
 "southdown":__DIR__"woniutai",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
