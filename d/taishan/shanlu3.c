
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������ɽ·��̧ͷ��ȥ��̩ɽ�Ķ��廹���������С�ǰ�����̩ɽ
�Ķ�ĸ���ˡ���ʱ�����˴���������߹���
LONG);

  set("exits", ([ 

   "eastdown":__DIR__"hongmengong",
   "northup":__DIR__"doumugong",
          ]));
 /*set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

