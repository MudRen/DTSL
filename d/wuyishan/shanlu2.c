
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·�ϣ��ϱ߾�������ɽ����ɽ֮·�ˡ�������ȥ����
��ɽ�����ľ�ɫ�����۵ס�ǰ����һ��СϪ��������һƬ���֣�������
������������ͷ羰��
LONG);

  set("exits", ([ 

   "southup":__DIR__"xiaoxi1",
   "northdown":__DIR__"shanlu1",
   "east":__DIR__"shulin2",
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

