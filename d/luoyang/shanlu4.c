
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ�����µ�ɽ·�������߾Ϳ������������ˡ������·����
���㲻��С��������
LONG);

  set("exits", ([ 
  "northup":__DIR__"shanlu3",
  "westdown":__DIR__"shanlu5",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

