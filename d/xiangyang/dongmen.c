
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����������ǵĶ����ˡ������������Ǿ����صأ������кܶ�ٱ�
�����������������ˡ�ֻ���м��������ػ����γ�վ������ȴ���
���������ǽ��ǵĹ�����
LONG);

  set("exits", ([ 
"west":__DIR__"dongdajie3",
"east":__DIR__"guanlu1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(me->query_temp("guanchai_yunyan")&&dir=="west"&&!present("gong han",me)&&!me->query_temp("no_in"))
	{
		me->apply_condition("yunyan_job",0);
		me->set_temp("no_in",1);
		return notify_fail("�йٱ�������"+RANK_D->query_respect(me)+",���ν���Ҫ�Ⱥ��ϼ�˵��һ�£���һ���!\n");
	}
	else if(me->query_temp("guanchai_yunyan")&&dir=="west"&&!present("gong han",me))
		
		return notify_fail("�йٱ�������"+RANK_D->query_respect(me)+",���ν���Ҫ�Ⱥ��ϼ�˵��һ�£���һ���!\n");
	if(me->query_temp("guanchai_yunyan")&&dir=="east"&&!present("gong han",me))
	{
		return notify_fail("�йٱ�������"+RANK_D->query_respect(me)+",���߰���һ��͸��㹫����!\n");
	}
	return ::valid_leave(me,dir);
}

void give_card(object me)
{
	object card;
	if(!me) {remove_call_out("give_card");return;}
	card=new(__DIR__"obj/card");
	card->move(me);
    message_vision("�ٱ�����$Nһ������\n",me);
    return;
  //  remove_call_out("give_card");return;
}

