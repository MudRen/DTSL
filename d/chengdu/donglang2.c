
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ƕ��ȡ�ǽ�����и���������ͼ�������෱�࣬��ɽˮ������
���ȵȣ�һ�����ǳ�����������֮�֡������Ƕ��𱤵����á������Ǹ�
��԰��
LONG);

  set("exits", ([ 
  
	  "west":__DIR__"donglang1",
	  "east":__DIR__"huayuan",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
