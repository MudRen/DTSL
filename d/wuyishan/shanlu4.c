
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·�����������������������������������һ���ٲ���
���Ｘ��û��ʲô�������㲻��С��������
LONG);

  set("exits", ([ 

   "northwest":__DIR__"shanlu3",
    "east":__DIR__"pubu",
           ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

