
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����¡���������Կ��������ˮ̶�������¿��˿�����
����Щ���Σ����ɵû��˻Ρ�
LONG);

  set("exits", ([ 
 "north":__DIR__"shanya",
 "east":__DIR__"shulin",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

