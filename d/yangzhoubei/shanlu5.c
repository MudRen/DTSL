
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·���ϱ߿��Կ�������֮�׵�̩ɽ�������ǻƺӵ��ϰ���
����������������Ļƺ�������
LONG);

  set("exits", ([ 
 "northeast":__DIR__"huanghenan",
 "southwest":__DIR__"taishanjiao",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

