
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ʺ�");
  set ("long", @LONG
������ʺ��ˡ���ˮƽ�����кܶ��������������ͷ羰����Ȼ��ս
������������ﻹ���Եú�ƽ�����㲻��������ķ羰����ס�ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"caodi2",
 "south":__DIR__"caodi1",
        ]));
  set("objects",([
    __DIR__"npc/youke":2,
    ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

