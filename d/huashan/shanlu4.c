
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ����᫵�ɽ·�����߿��Ե���ɽ�Ľ��칬�����ϱ���һ
��С��ͤ����������Ϣ֮�á�������ȥ��ɽ�����ŵĵ�·��
LONG);

  set("exits", ([ 
 "northwest":__DIR__"jintiangong",
 "east":__DIR__"shanlu5",
 "southwest":__DIR__"yanggongting",
 "southeast":__DIR__"nantianmen",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
