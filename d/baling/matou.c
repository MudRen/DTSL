
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ͷ");
  set ("long", @LONG
�����ǰ������ͷ�����ڰ��ߵĴ��������飬������õ�С�㴬��
�˻��õ��̴���������ͨ���ò���Ĺٴ������ϴ�������æ���쳣����
�ߺ����д�͵��̴���
LONG);

  set("exits", ([ 

  "south":__DIR__"guandao4",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

