
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
��������������ڳ�������������������¥�����ƷǷ���������
�����������ڣ��������������ҪԱ������칫֮�أ������������ϣ�
ƽ�����ո��ǲ��ýӽ���
LONG);

  set("exits", ([ 
 "north":__DIR__"changlang1",
 "south":__DIR__"jinshuiqiao",
        ]));
  set("objects",([
	 "/d/changan/npc/bing":2,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

