
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������Ƭ�ݵء��ݵ�ϸ����������·���ǳ�������м���Ѿ�ߴ�
���߽������������߾��������µ������ˡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"huayuan3",
 "east":__DIR__"woshi3",
     ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

