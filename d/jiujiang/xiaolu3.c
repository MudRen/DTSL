
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����ǽ��ߵ�С·���������˲��ࡣ�㲻ʱ���Կ��������д�ʻ
����һ��紵������ˮ�ĳ�ʪ��Ϣ�˱Ƕ�����
LONG);

  set("exits", ([ 

  "east":__DIR__"caodi1",
  "southwest":__DIR__"xiaolu2",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

