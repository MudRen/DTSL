
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
���������ݳǱ��Ĺ�·���򱱱���ȥ�������������ݵĳ����ˡ���
ʱ�����˴���������߹����������ݵķ������ɲ�����ǰ��
LONG);

  set("exits", ([ 
 "northeast":__DIR__"xiaolu1",
 "south":__DIR__"guanlu1",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

