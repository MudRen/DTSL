
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ͤ");
  set ("long", @LONG
������̩ɽ������ͤ������������������Ϣһ�¡���������Ϣ
�����˺ܶ࣬Ҳ����ĥ���Լ������͡�
LONG);

  set("exits", ([ 

   "westup":__DIR__"bixiaci",
   "westdown":__DIR__"yunbuqiao",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

