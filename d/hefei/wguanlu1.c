
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·���������������ǳ���æ����ʱ����������ҴҶ�����
���߾��ǺϷʵ������ˡ���������˺ܶࡣ
LONG);

  set("exits", ([ 

  "northeast":__DIR__"ximen",
  "southwest":__DIR__"wguanlu2",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

