
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǳ��ȡ�ǽ�����и���������ͼ�������෱�࣬��ɽˮ������
���ȵȣ�һ�����ǳ�����������֮�֡��ϱ߾��ǽ������������ˡ�
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"xilang2",
	  "south":__DIR__"woshi2",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
