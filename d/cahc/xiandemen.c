
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Ե���");
  set ("long", @LONG
�������Ե´��ǰ���Ե��š�������ȥ���������컧������������ 
�ݶ�����ͭ�ߣ������������֮״��Ρ��׳������ҫ��Ŀ��������ʿ��
������������Ѳ�ӡ�
LONG);

  set("exits", ([ 
 "northup":__DIR__"xiandedian",
 "east":__DIR__"yichunyuan",
 "south":__DIR__"chongmingmen",
        ]));
  set("objects",([
           __DIR__"npc/changlinjun":2,
        ]));
  

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

