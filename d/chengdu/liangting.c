
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ͤ");
  set ("long", @LONG
��������ͤ�������Ǹ���԰����紵�����㲻������һ����ͤ��
Χ�˻������أ��ض��ǳ��Գɶ���������֮�֡�
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"huayuan",
	  "south":__DIR__"changlang1",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
