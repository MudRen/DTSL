
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵء���������Ĳݵ�֮�ϣ��㲻���÷ǳ����������
����һƬ���֡��ϱ���һ�����£��Ѿ�û��·�ˡ�
LONG);

  set("exits", ([ 

   "north":__DIR__"shulin1",
               ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

