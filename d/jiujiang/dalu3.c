
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����Ǹ�����·�������Ѿ����������Ŀ������ݵĳ����ˡ�����
�Թž��Ƿ����ش����������Ѿ����������������ֵ������ˡ�
LONG);

  set("exits", ([ 

  "southeast":__DIR__"dalu4",
  "west":__DIR__"dalu2",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

