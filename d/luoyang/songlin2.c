
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֡���������Կ���Զ���������ǣ���������ʤ�ա�
�����кܶ�Ư����Ұ�����������׺�������쳣��
LONG);

  set("exits", ([ 
  "west":__DIR__"songlin",
        ]));
  set("objects",([
	  __DIR__"obj/wuhuaguo":1,
	  ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	object ob;
	if(dir=="west"&&present("wuhua guo",me)&&!present("she",environment(me))
		&&!me->query_temp("temp_wu"))
	{ 
		ob=new(__DIR__"npc/she");
		ob->move(environment(me));
		me->set_temp("temp_wu",1);
		tell_object(environment(me),"ͻȻ����һ���ߣ�\n");
		ob->kill_ob(me);
		return notify_fail("�㱻����ס��ȥ·!\n");
	}
	return ::valid_leave(me,dir);
}



