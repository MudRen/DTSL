
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���������ȡ�ǽ�����и���������ͼ�������෱�࣬��ɽˮ������
���ȵȣ�һ�����ǳ�����������֮�֡������Ƕ��𱤵����á�������һ
Ƭ�ݵء�
LONG);

  set("exits", ([ 
  
	  "east":__DIR__"xilang1",
	  "north":__DIR__"caodi4",
	  "south":__DIR__"changlang2",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
