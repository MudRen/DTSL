
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
���������ݳǱ��Ĺ�·�����߾������ݵı����ˡ���������˺ܶ࣬
���ַǷ����Թ����ݾ��ǽ��Ϸ��������ģ����������ڱ������ҵ������
����ķ���Ҳ����������
LONG);

  set("exits", ([ 
 "north":__DIR__"guanlu2",
 "south":"/d/yangzhou/beimen",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

