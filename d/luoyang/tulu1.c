
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·�������������ǵı��š���������˺ܶ࣬�кܶ���
����ʿ�߹���
LONG);

  set("exits", ([ 

  "south":__DIR__"beimen",
 "northeast":__DIR__"tulu2",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

