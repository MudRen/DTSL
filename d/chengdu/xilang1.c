
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���������ȡ�ǽ�����и���������ͼ�������෱�࣬��ɽˮ������
���ȵȣ�һ�����ǳ�����������֮�֡������Ƕ��𱤵����á�
LONG);

  set("exits", ([ 
  
	  "east":__DIR__"zhutang",
	  "west":__DIR__"xilang2",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
