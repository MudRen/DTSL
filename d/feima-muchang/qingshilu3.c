
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
������һ����ʯ·�������Ƿ��������Ĳ�԰���ϱ��Ƿ���������԰
�֡��м������˴������߹�����������ȥ��԰�ֲ˸ɻ�ġ�
LONG);

  set("exits", ([ 
	  "west":__DIR__"caodi2",
	  "southeast":__DIR__"yuanlin",
    ]));
  set("objects",([
	  __DIR__"npc/wuzhao-ru":1,
	  ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

