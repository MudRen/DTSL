
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·�������Ѿ��߳����㽭�ľ����ˣ������߾��ǽ�����
�����ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"tulu1",
 "west":__DIR__"shangang1",
        ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

