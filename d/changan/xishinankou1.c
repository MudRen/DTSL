
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����Ͽ�");
  set ("long", @LONG
�������λ����ƽ����ϵ��������������У������е��Ͽڣ�����
·���򱱣������ߵ����ַǷ������С�
LONG);

  set("exits", ([ 
 "north":__DIR__"xishixijie5",
 "west":__DIR__"xpdajie1",
 "east":__DIR__"xishinankou2",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

