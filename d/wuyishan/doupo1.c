
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����£��㲻��С��������������һ��СϪ�����������
��Լ������������ˮ����������һƬ���֡�
LONG);

  set("exits", ([ 

   "northeast":__DIR__"xiaoxi1",
   "west":__DIR__"shulin4",
   "southdown":__DIR__"doupo2",
   
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

