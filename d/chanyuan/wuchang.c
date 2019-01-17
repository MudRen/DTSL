
#include <ansi.h>
inherit ROOM;
int do_sao(string arg);

void create ()
{
  set ("short","���䳡");
  set ("long", @LONG
�����Ǿ�����Ժ���䳡��ƽʱ��ɮ�Ǿ���������ϰ���ա�ֻ������
���ȵ������������Ա߼���ɮ�˴�����𾢡�Զ��ʮ����ɮ��վ�ɼ��ţ�
����Ŭ����ϰ���գ����ȵ�����ԶԶ���������ﲻ�����������֮�
LONG);

  set("exits", ([ 

	  "east":__DIR__"xiaolu7",
	  "west":__DIR__"caodi4",
      ]));
  set("objects",([
	  __DIR__"npc/xuchen":1,
	  ]));
  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_sao","sao");
}

int do_sao(string arg)
{
	object me;
	me=this_player();
	if(!arg||arg!="�䳡") return notify_fail("����ɨʲô?\n");
	if(!me->query_temp("budian_job/3"))
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
	message_vision("$N��ϸ�ش�ɨ���䳡����\n",me);
	return 1;
}

void return_job(object me)
{
	message_vision("$N����ͷ�ϵĺ�,�����Լ���Ϊ���ʥ�����˼�����.\n",me);
	return;
}