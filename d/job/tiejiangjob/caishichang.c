#include <ansi.h>
inherit ROOM;

int do_cai(string arg);
void create ()
{
  set ("short","��ʯ��");
  set ("long", @LONG
�����ǲ�ʯ���������зḻ�Ŀ�ʯ��������������ʯ���������
�������Ǿ�˵Ҳ�в������ڿ��ɿ�ʯʱ����ʯ���������ﻹ����һ����
�ӣ�pai����
LONG);

  set("exits", ([ 
 "southeast":__DIR__"shanlu1",
// "east":__DIR__"songlin",
       ]));
  set("item_desc",([
	  "pai":"�ڴ˿���(kaicai)��ʯ�ߣ��������Ը����ٸ�һ�Ų�����\n",
	  ]));
set("outdoors","dabashan");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_cai","kaicai");
}

int do_cai(string arg)
{
	object me,ob,tool;
	me=this_player();
	if(!arg||arg!="��ʯ")
		return notify_fail("���뿪��ʲô��\n");
	if(!objectp(tool=me->query_temp("weapon")))
		return notify_fail("������ô���ɿ�ʯ��\n");
	if(tool->query("skill_type")!="fork")
		return notify_fail("�㻹���ø�ͷ���ɰɣ�\n");
	if(me->is_busy())
		return notify_fail("�����ں�æ��ЪЪ��!\n");
	if(me->is_fighting())
		return notify_fail("�㻹���ȴ�������˵�ɣ�\n");
	if((int)me->query_encumbrance() + 50000 > (int)me->query_max_encumbrance() ) 
         return notify_fail( "�����ϵĶ���̫���ˣ������ò�����ʯ������ʲô����\n");
      message_vision("$N��"+tool->name()+"�������ʯ����\n",me);
	me->start_busy(1);
	me->receive_damage("sen",50+random(5));
	if(random(10)>6)
	{ob=new("/d/job/tiejiangjob/kuang");
	ob->move((me));
	message_vision("$N���ɳ�һ��"+ob->name()+"����\n",me);
	}
	else
	{
		message_vision("ͻȻһ����ʯ��ɽ�Ϲ���������\nֱ������$N!\n",me);
		if((int)me->query_skill("dodge",1)>=1)
		{
			message_vision("$N���Ʋ��ã���æ���˿�����\n",me);
            ob=new("/d/job/tiejiangjob/kuang");
	        ob->move((me));
            message_vision("$N���ɳ�һ��"+ob->name()+"����\n",me);
			return 1;
		}
		else
		{
			message_vision("$N����ʯ�������У�\n",me);
            ob=new("/d/job/tiejiangjob/kuang");
	        ob->move((me));
			me->unconcious();
			return 1;
		}
	}
	return 1;
}