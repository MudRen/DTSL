
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
���������ݳǵ�������Ĺ�·�����߾������ݵ������ˡ����ڵ���
�ݻ��Ǻܷ������������������һ�㶼���١�
LONG);

  set("exits", ([ 
 "east":__DIR__"ximen",
 "west":__DIR__"guanlu2",
        ]));
  set("objects",([
   __DIR__"npc/xingren":2,
   ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

