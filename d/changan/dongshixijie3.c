
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����������������Ķ��У������У������Ƕ����е����֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���������һ��˿��꣬��
���Ƕ�����
LONG);

  set("exits", ([ 
 "north":__DIR__"dongshixijie2",
 "south":__DIR__"dongshixijie4",
 "west":__DIR__"dongshishu",
 "east":__DIR__"sichoudian",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

