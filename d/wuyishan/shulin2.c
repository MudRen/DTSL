
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬï�ܵ����֣�������ɢ�ش����ͷ������������������
�����ڶ���������һ��ɽ·����Ƭ���ֿ������ܴ󣬹���Ҫ��һ�����
��ȥ��
LONG);

  set("exits", ([ 

   "west":__DIR__"shanlu2",
   "east":__DIR__"shulin3",
  
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

