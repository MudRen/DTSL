
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��ˮ̲");
  set ("long", @LONG
�����Ǿ�����ˮ̲�������ϱ��߲�Զ���������ˡ�������ľϡ�٣�
ֻ��Զ����һƬϡ��Ĳݵء�
LONG);

  set("exits", ([ 

  "northeast":__DIR__"tree2",
  "southeast":"/d/lingnan/caodi1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

