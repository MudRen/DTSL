
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·���������߾��������ˡ������߾��ǰ��յľ����ˡ�
����ֻ��ϡϡ����ļ������ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"guanlu1",
 "northwest":__DIR__"xiaolu1",
        ]));
  set("objects",([
   __DIR__"npc/youke":2,
   ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

