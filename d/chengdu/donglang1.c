
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ƕ��ȡ�ǽ�����и���������ͼ�������෱�࣬��ɽˮ������
���ȵȣ�һ�����ǳ�����������֮�֡������Ƕ��𱤵����á�
LONG);

  set("exits", ([ 
  
	  "west":__DIR__"zhutang",
	  "east":__DIR__"donglang2",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
