
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������֣��ϱ����ӳ����ǵ������ź͵����š�����ʮ�����֣�
��������������Ϣ��������һ�����̡�
LONG);

  set("exits", ([ 
 "north":__DIR__"qydajie5",
 "south":__DIR__"gmdajie3",
 "east":__DIR__"dangpu",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
}

