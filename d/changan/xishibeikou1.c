#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���б���");
  set ("long", @LONG
�������λ�ڹ�������ϵ��������������У������еı��ڣ�����
·�����ϣ������ߵ����ַǷ������С�
LONG);

  set("exits", ([ 
 "south":__DIR__"xishixijie1",
 "west":__DIR__"gmdajie7",
 "east":__DIR__"xishibeikou2",
        ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

