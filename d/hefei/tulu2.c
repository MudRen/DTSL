
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·�������ǰ��պͺ����Ľ��磬���߾��Ǻ����ľ����ˣ�
�����ǰ��յľ��ء�
LONG);

  set("exits", ([ 

  "east":__DIR__"tulu1",
  "southwest":__DIR__"caodi1",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

