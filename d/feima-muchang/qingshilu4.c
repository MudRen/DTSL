
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·��������������ķ�ש�������ǳ����ʹ�ܼҵľ�
����ƽ���˵��ǲ���������ġ��м���Ѿ�����������߳���
LONG);

  set("exits", ([ 
	  "south":__DIR__"yuanlin",
	  "north":__DIR__"qingshilu5",
    ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

