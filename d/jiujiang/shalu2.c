
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","ɳ·");
  set ("long", @LONG
������Ƭɳ·�������볤�������Ǻ�Զ�������ǰ��պ��㽭�Ľ���
���ˡ������߾����㽭�������߾��ǰ����ˡ�
LONG);

  set("exits", ([ 

  "east":__DIR__"shalu3",
  "southwest":__DIR__"shalu1",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

