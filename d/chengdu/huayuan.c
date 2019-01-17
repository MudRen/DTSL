
#include <ansi.h>
inherit ROOM;

int do_dig();
void create ()
{
  set ("short","��԰");
  set ("long", @LONG
�����Ǹ���԰������Ļ���Ʒ�ֲ��Ǻܶ࣬�������˺ܶ�����ҩ
�ġ����ֻ�����ͷף�ɫ������������������Ŀ����԰��Χ�˻������أ�
�ض��ǳ��Գɶ���������֮�֡�
LONG);

  set("exits", ([ 
  
	  "west":__DIR__"donglang2",
	  "southeast":__DIR__"liangting",
        ]));
  set("objects",([
	  __DIR__"npc/nvdizi":2,
	  ]));
  set("dig_out", "/d/chengdu/obj/huangqi");
	
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_dig",({"dig","wa"}));
}

int do_dig()
{
	object me,ob,tool;
	me=this_player();
	if(me->is_busy()||me->is_fighting())
		return notify_fail("�㻹æ���أ�\n");
	if(!me->query_temp("weapon"))
		return  notify_fail("������ô��ҩ����\n");
	tool=me->query_temp("weapon");
	if(tool->query("name")!="��ͷ")
		return notify_fail("û�г�ͷ��ô��ҩ��\n");
	message_vision("$N�����ͷ����ҩ����\n",me);
	if(random(10)>4)
	{if(random(4)>1)
		ob=new(__DIR__"obj/huangqi");
	else ob=new(__DIR__"obj/gouqizi");
	me->start_busy(2);
	ob->move(me);
	me->receive_damage("sen",5+random(10));
    message_vision("$N�ڵ���һ��"+ob->name()+"!\n",me);
	return 1;
	}
	message_vision("$N���˰��죬ʲôҲû�ڵ���\n",me);
	me->receive_damage("sen",5+random(10));
	return 1;
}