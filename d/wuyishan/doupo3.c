
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����£����߾�������ɽ�ˡ���������ȥ���Ϳ��Ե�����
ɽ�������ɽ·�Ƚ��վ����㲻��С��������
LONG);

  set("exits", ([ 

   "westup":__DIR__"doupo2",
   "eastdown":"/d/dongming/xiaolu1",
   
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

