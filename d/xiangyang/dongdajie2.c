
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����������Ķ��֡�������Ե����������ġ�������һ�����̡���
�̵������Ѿ����ƾ��ˣ�����ġ���ѧ��ʵ���ĸ��Ѿ����ģ�����塣
����书�����ױ�ס����������ȥ���̵���Խ��Խ���ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"dongdajie3",
 "south":__DIR__"dangpu",
 "south":__DIR__"dangpu",
 "west":__DIR__"dongdajie1",
 "north":__DIR__"shupu",
        ]));
  set("objects",([
	  __DIR__"npc/boy":1,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

