
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"ʯ��"NOR);
  set ("long", @LONG
������ʯ�ס��������ߣ��Ϳ��Ե��ʹ������޹��ˡ�
LONG);

  set("exits", ([ 
  
  "northwest":__DIR__"houdian",
  "south":__DIR__"yushanfang",
         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

