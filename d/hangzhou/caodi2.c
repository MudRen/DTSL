
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ��ݵء����߾��ǳ����İ����ˡ���ʱ���˴�����˴�
�����������������ǳ����֡�
LONG);

  set("exits", ([ 

  "south":__DIR__"caodi1",
  "northeast":__DIR__"jiangnan",
        ]));
 
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

