
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����Ǹ�����·����������Ѿ��ܶ��ˡ���Ȼ��ս�����������
Ȼ��������Ӧ�еķ�������
LONG);

  set("exits", ([ 

  "east":__DIR__"dalu3",
  "west":__DIR__"dalu1",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

