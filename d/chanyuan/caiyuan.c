
#include <ansi.h>
inherit ROOM;
int do_zhong(string arg);

void create ()
{
  set ("short","��԰");
  set ("long", @LONG
�����Ǿ�����Ժ�Ĳ�԰���������˺ܶ��߲�ˮ�����аײˡ��ƹϡ�
�������ܲ��ȡ��м���ɮ�������������ڵظɻ�е��ڳ��ݣ��е���
��ˮ���е���ʩ�ʡ�������Ժ��ɮ�˾�������ͨ���Ͷ������������
������ѧ��Ϊ��
LONG);

  set("exits", ([ 
	  "south":__DIR__"caodi4",
     ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_zhong","zhong");
}

int do_zhong(string arg)
{
	object me;
	me=this_player();
	if(!arg||arg!="��") return notify_fail("������ʲô?\n");
	if(!me->query_temp("budian_job/2"))
		return notify_fail("��������æʲô��?\n");
	if(me->is_busy()) return notify_fail("����æ����!\n");
	if((int)me->query("sen",1)<=5) return notify_fail("��̫����,�Ѿ������ٸɻ���!\n");
	if(me->query_temp("budian_job/ok"))
		return notify_fail("����,����Ի�ȥ������!\n");
	if(me->query_temp("budian_job/count"))
		me->add_temp("budian_job/count",1+random(1));
	else me->set_temp("budian_job/count",1);
	if((int)me->query_temp("budian_job/count",1)>=10+random(5))
		me->set_temp("budian_job/ok",1);
	me->receive_damage("sen",10+random(2));
	call_out("return_job",2,me);me->start_busy(1);
	message_vision("$N������������.\n",me);
	return 1;
}

void return_job(object me)
{
	message_vision("$N����ͷ�ϵĺ�,�����Լ���Ϊ���ʥ�����˼�����.\n",me);

	return;
}