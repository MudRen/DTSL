
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�����Ǻ��ݵ��ϴ�֡��ϱ��Ǻ��ݵ������ˡ�������һ��Ǯׯ����
���οʹ���������߹�������̸���������ķ�⡣ֻ��һ����������
������ʻ������������ȥ������ұ�������ȥ�ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"nanmen",
  "north":__DIR__"nandajie1",
  "east":__DIR__"qianzhuang",
        ]));
  set("objects",([
	  __DIR__"npc/man":1,
	  ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

