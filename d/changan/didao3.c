
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIB"�ص�"NOR);
  set ("long", @LONG
������һ���ص����ںڵģ����ֲ�����ָ������ǳ���խ����ֻ��
������ǰ���ˡ�ǰ������Ǹ����ң���֪��������ʲô�ˡ�
LONG);

  set("exits", ([ 
 "in":__DIR__"mishi",
"west":__DIR__"didao2",
      ]));
  set("no_select",1);
  set("valid_startroom", 1);
  setup();
 
}
