
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
������һ����ɽ��С������Χ�Ƕ�üɽ�����ķ�⡣��ʱ�����˺�
����������
LONG);

  set("exits", ([ 
 "eastup":__DIR__"xiaojing2",
 "southdown":__DIR__"shanjiao",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

