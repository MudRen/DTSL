
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����������ǵ����š��Թ������������Ǿ����صء���������ļ�
��Ҳ�Ƿǳ��ϸ��м����ٱ�ҫ��������վ������Խ��ǵ��˲�ס��
���ȡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"nandajie4",
 "south":__DIR__"guanlu3",
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
	if(me->query_temp("guanchai_yunyan")&&dir=="north"&&!present("gong han",me)&&!me->query_temp("no_in"))
	{
		me->apply_condition("yunyan_job",0);
		me->set_temp("no_in",1);
		return notify_fail("�йٱ�������"+RANK_D->query_respect(me)+",���ν���Ҫ�Ⱥ��ϼ�˵��һ�£���һ���!\n");
	}
	else if(me->query_temp("guanchai_yunyan")&&dir=="north"&&!present("gong han",me))
		
		return notify_fail("�йٱ�������"+RANK_D->query_respect(me)+",���ν���Ҫ�Ⱥ��ϼ�˵��һ�£���һ���!\n");
	if(me->query_temp("guanchai_yunyan")&&dir=="south"&&!present("gong han",me))
	{
		return notify_fail("�йٱ�������"+RANK_D->query_respect(me)+",���߰���һ��͸��㹫����!\n");
	}
	return ::valid_leave(me,dir);
}
