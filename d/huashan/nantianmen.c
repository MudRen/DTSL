
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������Ϸ嶫�ࡣ�Զ��������¾������衢����̨�������С��
��Ԯ���Ϊ���ٳ�Ԫ��������ջ��������ʯ�ҡ�ȫ���µı���֮����
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shanlu4",
 "southeast":__DIR__"shanlu2",
       ]));
  /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
