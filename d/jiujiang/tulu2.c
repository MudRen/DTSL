
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·�������������ߣ��Ϳ��Ե��Ž����������ߣ����Ե�
��������ϡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"tulu1",
 "southwest":__DIR__"shanlu1",
 "southeast":"/d/dongming/shanlu4",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

