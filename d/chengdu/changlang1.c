
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǹ����ȡ�������һ����ͤ���ϱ��Ƕ��𱤵ı������͵�����
�ˡ��м���Ѿ�ߴ��������������
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"liangting",
	  "south":__DIR__"woshi1",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
