
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @LONG
������һ����·�����Ϸ����Ե��ųǳ�����·�����˲��Ǻܶ࣬��
�������ģ��ƺ����������򱱶��У���������һ����ʲô�羰��ʤ��
�ڡ�
LONG);

  set("exits", ([ 
 "south":__DIR__"guanlu1",
 "northeast":__DIR__"dadao2",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}
