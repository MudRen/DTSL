
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
 "northeast":"/d/taiyuan/road8b",
 "southwest":__DIR__"dadao1",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

