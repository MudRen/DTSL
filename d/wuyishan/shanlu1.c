
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·�ϣ��ϱ߾�������ɽ����ɽ֮·�ˡ�������������
��⣬��Լ��������������ˮ��������·�Բ�ʱ�Ĺ�һֻҰ�á�
LONG);

  set("exits", ([ 

   "southup":__DIR__"shanlu2",
   "northdown":__DIR__"shanjiao",
   "west":__DIR__"shulin1",
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

