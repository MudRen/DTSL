
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
����Ϊ��ɽ�������ţ������·��᫣����˶��Ƿ���С�ġ�������
���ߣ��Ϳ��Ե��ﻪɽ��ȫ���¡�
LONG);

  set("exits", ([ 
 "southwest":__DIR__"quanzhenya",
 "east":__DIR__"shanlu2",
       ]));
  /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
