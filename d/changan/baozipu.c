
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
����������Ȼ���󣬵������⵹�Ƿǳ��ĺã�������һ�ſ�����
����������С����������һ����ë��Цӯӯ���������˹�����
LONG);

  set("exits", ([ 
 "east":__DIR__"xishixijie3",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer3":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

