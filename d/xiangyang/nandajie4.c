
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�������������ϴ�֡�������������������ˣ�������˲��Ǻܶࡣ
������һ����Ӫ���м����ٱ�������դ���ϴ����ʱ���˸����γ�����
�������߹���
LONG);

  set("exits", ([ 
 "east":__DIR__"bingying2",
 "north":__DIR__"nandajie3",
 "south":__DIR__"nanmen",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	object card;
	if(objectp(card=present("gong han",me)))
	{
		message_vision("�ٱ�������$N���ϵĹ���\n",me);
		me->delete_temp("no_in");
		destruct(card);
	}
	return ::valid_leave(me,dir);
}
