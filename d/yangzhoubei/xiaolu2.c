
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������С·��������һƬ�ݵء�һ��紵������������ˮ����Ϣ��
���������ض��к�ˮ������ˡ�
LONG);

  set("exits", ([ 
 "northwest":__DIR__"caodi1",
 "southwest":__DIR__"xiaolu1",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

