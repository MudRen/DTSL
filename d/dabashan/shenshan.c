
#include <ansi.h>
inherit ROOM;

int do_cai(string arg);
void create ()
{
  set ("short","��ɽ");
  set ("long", @LONG
�����Ǵ��ɽ�������������ʢ��ҩ�ġ�
LONG);

  set("exits", ([ 
  "southwest":"/d/job/yishengjob/shenshan",
       ]));
set("outdoors","dabashan");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_cai","cai");
}

int do_cai(string arg)
{
	object me,ob,tool;
	me=this_player();
	if(!arg||arg!="ҩ")
		return notify_fail("���뿪��ʲô��\n");
	if(me->is_busy())
		return notify_fail("�����ں�æ��ЪЪ��!\n");
	if(me->is_fighting())
		return notify_fail("�㻹���ȴ�������˵�ɣ�\n");
	if((int)me->query_encumbrance() + 50000 > (int)me->query_max_encumbrance() ) 
         return notify_fail( "�����ϵĶ���̫���ˣ������ò���ҩ�ģ�����ʲô����\n");
      message_vision("$N������ҩ������\n",me);
   me->start_busy(1);
	me->receive_damage("sen",50+random(5));
    if(random(10)>4)
	{ob=new("/d/job/yishengjob/yao");
	ob->move((me));
	message_vision("$N���ɳ�һ��"+ob->name()+"����\n",me);
	}
	else
	{
		message_vision("ͻȻһ���ʯ��ɽ�Ϲ���������\nֱ������$N!\n",me);
		if((int)me->query_skill("dodge",1)>=1)
		{
			message_vision("$N���Ʋ��ã���æ���˿�����\n",me);
            ob=new("/d/job/yishengjob/yao");
	        ob->move((me));
            message_vision("$N���ɳ�һ��"+ob->name()+"����\n",me);
			return 1;
		}
		else
		{
			message_vision("$N����ʯ�������У�\n",me);
            ob=new("/d/job/yishengjob/yao");
	        ob->move((me));
			me->unconcious();
			return 1;
		}
	}
	return 1;
}
