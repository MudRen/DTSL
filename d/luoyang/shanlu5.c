
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ�����µ�ɽ·�������߾Ϳ������������ˡ�����ĵ�·��
���������ˡ�
LONG);

  set("exits", ([ 
  "eastup":__DIR__"shanlu4",
  "south":__DIR__"xiaolu8",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

