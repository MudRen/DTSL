
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIB"�ص�"NOR);
  set ("long", @LONG
������һ���ص����ںڵģ����ֲ�����ָ��һ������������洵
�˳��������Ե���ɭ�ֲ���
LONG);

  set("exits", ([ 
 "north":__DIR__"didao2",
"out":__DIR__"zhenbaozhai",
      ]));
  set("no_select",1);
  set("valid_startroom", 1);
  setup();
 
}
