
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
�������λ�ں͹����ϵ��������������У������е����ڣ�ʮ��
·���򶫣������ߵ����ַǷ������С�������һ�Ҵ��������ӣ����ϵ�
�С�ƹ�ҡ�-��ƹ�ҡ�������������
LONG);

  set("exits", ([ 
  "north":__DIR__"gmdajie7",
  "south":__DIR__"xishixikou2",
 "west":__DIR__"tiejiangpu",
 "east":__DIR__"xishixijie2",
        ]));
  set("objects",([
         __DIR__"npc/youke":1,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

