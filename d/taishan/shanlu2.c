
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������ɽ·��̧ͷ��ȥ��̩ɽ�Ķ��廹���������С�ǰ�����̩ɽ
�ĺ��Ź��ˡ���ʱ�����˴���������߹���
LONG);

  set("exits", ([ 

   "eastdown":__DIR__"shanlu1",
   "up":__DIR__"hongmengong",
          ]));
 /*set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

