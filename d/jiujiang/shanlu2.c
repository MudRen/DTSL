
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·�������������ˡ�ɽ·��᫣���������ԼԼ�����μ�
���ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu1",
 "south":__DIR__"shanlu3",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

