
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"ʯ��"NOR);
  set ("long", @LONG
������ʯ�ס��������ߣ��Ϳ��Ե��ʹ������޹��ˡ�
LONG);

  set("exits", ([ 
  
  "northeast":__DIR__"houdian",
  "south":__DIR__"guanhuayuan",
         ]));

  set("objects",([
   __DIR__"npc/gongnv1":1,
   ]));
  set("valid_startroom", 1);
  setup();
 
}

