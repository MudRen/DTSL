
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIB"�ص�"NOR);
  set ("long", @LONG
������һ���ص����ںڵģ����ֲ�����ָ��ǰ������е����⡣ͻ
Ȼһֻ�����������Դܹ���
LONG);

  set("exits", ([ 
 "east":__DIR__"didao3",
"south":__DIR__"didao1",
      ]));
  set("no_select",1);
  set("valid_startroom", 1);
  setup();
 
}
