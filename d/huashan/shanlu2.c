
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
 "northwest":__DIR__"nantianmen",
 "west":__DIR__"shanlu3",
       ]));
  
  set("objects",([
	  "/d/clone/npc/beast/huilang":1,
	  ]));
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
