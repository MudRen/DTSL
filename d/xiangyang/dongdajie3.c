
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����������Ķ��֡�������һ�ҹŶ��꣬����Ľ���������������
�������⡣������һ��ҩ�꣬�����ϵġ��������ˡ��ĸ�����Զ�Ϳ���
���������
LONG);

  set("exits", ([ 
 "east":__DIR__"dongmen",
 "west":__DIR__"dongdajie2",
 "north":__DIR__"gudongdian",
 "south":__DIR__"yaodian",
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

