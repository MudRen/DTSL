
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
�������λ�ں͹����ϵ��������������У������е����ڣ�ʮ��
·���򶫣������ߵ����ַǷ������С�������һƬ�ž�����ӡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"xishixikou1",
 "south":__DIR__"hgdajie1",
 "west":__DIR__"changanfang",
 "east":__DIR__"xishixijie4",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

