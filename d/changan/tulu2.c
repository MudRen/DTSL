
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·�������������ͺ��ϵĽ��紦�ˡ����������У���
���Ե������ĳ����ˣ������ﶫ�У��Ϳ��Ե����ϵ������ˡ�
LONG);

  set("exits", ([ 
"northwest":__DIR__"tulu1",
"east":__DIR__"dalu1",
"northeast":__DIR__"shanlu3",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

