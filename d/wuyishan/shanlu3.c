
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��������һƬ���֡�������һ��ɽ�������������
�ģ���֪����û��Σ�ա�
LONG);

  set("exits", ([ 

   "east":__DIR__"shandong",
   "north":__DIR__"shulin3",
   "southwest":__DIR__"shanlu5",
   "southeast":__DIR__"shanlu4",
  
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

