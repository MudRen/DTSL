
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"�㳡"NOR);
  set ("long", @LONG
���������̵����ӣ�һ�����ǳ�������֮�����ʹ��䱸ɭ�ϣ�����
���������߹���
LONG);

  set("exits", ([ 
  "east":__DIR__"guangchang2",
         ]));

  set("objects",([
   __DIR__"npc/taijian1":1,
   ]));
  set("valid_startroom", 1);
  setup();
 
}

