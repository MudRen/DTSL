
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�������������Ͻ֡������߿��Ե����������ġ�������һ��Ǯׯ��
Ǯׯ�Ľ�������������Ϳ��÷ǳ�������м����ٱ�����������߹���
�ƺ�����̸��������Ǯ���أ�����һ����ͷ������һ�ۣ�Ȼ���ּ�����
�����ٱ�̸Цȥ�ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"qianzhuang",
 "north":__DIR__"nandajie2",
 "south":__DIR__"nandajie4",
        ]));
  set("objects",([
	  __DIR__"npc/zhongnian":1,
	  "/d/yinkui/npc/baiqinger":1,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

