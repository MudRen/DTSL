
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
 "north":__DIR__"xishidongjie5",
 "eastup":__DIR__"xpqiao",
 "west":__DIR__"xishinankou1",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

