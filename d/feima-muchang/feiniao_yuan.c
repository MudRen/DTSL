
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����԰"NOR);
  set ("long", @LONG
԰������������Զ�����ݸߵ����򣬴�������ľ֮�䣬���׵�
�塣����´�������ׯ԰���ڸߴ�����ʱ�ɿ������������չ�޾�����
��������������б����Խ���������͡�
LONG);

  set("exits", ([ 
	  "south":__DIR__"qingshilu5",
	  "north":__DIR__"woshi1",
	  "east":__DIR__"shufang",
	  "west":__DIR__"qingshilu6",
    ]));
  set("objects",([
	  __DIR__"npc/liuzong-dao":1,
	  ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
  "/obj/sboard/feima_b.c"->foo();

 
}

