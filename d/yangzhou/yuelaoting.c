
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ͤ");
  set ("long", @LONG
���������ݵ�����ͤ��ͤ�ڵ����Ϸ�����һ����컨�����Դ�����
�����ʴ���ͤ�ӵ��Ϸ����ܻ�����һȦ�Ĳʴ�����������������顣��
����������Ͷ��ϵ���Ů������������������ȫ���ǵĻ�����
LONG);

  set("exits", ([ 
 "north":__DIR__"dongdajie2",
        ]));
  set("objects",([
 "/d/clone/npc/yuelao":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

