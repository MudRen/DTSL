
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����£��㿪ʼС���������������߾�������ɽ�ˡ�����
����Ե�����ɽ�ϡ�
LONG);

  set("exits", ([ 

   "northup":__DIR__"doupo1",
  "eastdown":__DIR__"doupo3",
   
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

