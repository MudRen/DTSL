
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","СϪ");
  set ("long", @LONG
������һ��СϪ����������������񷤣�����˳������ֱ������ɽ
�¡�Ϫˮ�峺����������ӳ�������ò��������Ұ�õ�С�����������
ˮ��
LONG);

  set("exits", ([ 

   "southwest":__DIR__"doupo1",
   "northdown":__DIR__"shanlu2",
   
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

