
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����ȡ����ȵ��������˸����滨��ݣ�����ʤ�ա�����
��Ʒ�ַ��࣬ɫ������������ʤ�ա�ֻ�����ﻨ�ݵ�Ʒ�֣��Ϳ��Կ���
�μұ��Ƹ��ĸ��㡣
LONG);

  set("exits", ([ 

  "north":__DIR__"changlang1",
  "south":__DIR__"zhengting",
        ]));
  set("objects",([
	  __DIR__"npc/songbang":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

