
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
	  "south":__DIR__"qingshilu4",
	  "north":__DIR__"feiniao_yuan",
	  "east":"/d/clone/room/orgsaferoom/feima/wanxiaotang",
    ]));
 set("objects",([
	  __DIR__"npc/dizi":1,
	  ]));
  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

