
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������ɽ·�������������ʵǣ��Ϳ��Ե�̩ɽ�Ķ����ˡ������ɽ
·�ǳ���խ��������ۣ��ǳ����ߡ�����һ�㶼���Ŷ������ʵǡ�
LONG);

  set("exits", ([ 

   "westdown":__DIR__"baihequan",
   "westup":__DIR__"shanlu2",
          ]));
 /*set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

