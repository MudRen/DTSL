
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬï�ܵ����֡���ľ��ס�����⣬�Ե�������ˬ���졣��
��������ɽ����ɽ֮·���ϱ���һƬ�ݵء�
LONG);

  set("exits", ([ 

   "east":__DIR__"shanlu1",
   "south":__DIR__"caodi1",
             ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

