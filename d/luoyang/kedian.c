
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�͵�");
  set ("long", @LONG
�����Ǽ�С�͵ꡣ���ڽ��������������ĺܶ࣬�������С�͵���
��Ҳ�Ƿǳ��ĺá���С����ǰ�ܺ�æ����ͣ��
LONG);

  set("exits", ([ 
  
	  "west":__DIR__"baihujie2",
	  "enter":__DIR__"shuifang2",
         ]));
  set("objects",([
	  __DIR__"npc/xiaoer2":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="enter")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("��С����ס���㣺�͹٣�����û��Ǯ��!\n");
		else return notify_fail("�ƹ�����溰�����͹٣���Ǯ��ס�갡!\n");
		return ::valid_leave(me,dir);
		return 1;
}
