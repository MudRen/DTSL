
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ��·");
  set ("long", @LONG
����һ�����ĵ�ʯ��С·�������Ǹ߸ߵķ�Ժǽ������ʯ��·�ϣ�
���´���������������
LONG);

  set("exits", ([ 
 "north":__DIR__"xuanpingfang",
 "west":__DIR__"duoqingwo",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

