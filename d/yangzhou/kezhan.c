
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������ջ");
  set ("long", @LONG
������һ�ҿ�ջ��Ҳ���������Ŀ�ջ�ˡ�ÿ�춼�кܶ���������
Ͷ�ޡ�����Ҳ���������ֵĵط�֮һ���ķ�������������̸��˵�ء���
����������߳Է��Ȳ��С����̸��������´��ҵ���ʽ�����м�����
����ʿ������̸���ź���赵����顣��С����������ȥ��æ����ͣ��
LONG);

  set("exits", ([ 
 "south":__DIR__"xidajie3",
 "up":__DIR__"wofang",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer2":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="up")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("��С����ס���㣺�͹٣�����û��Ǯ��!\n");
		else return notify_fail("�ƹ�����溰�����͹٣���Ǯ��ס�갡!\n");
		return ::valid_leave(me,dir);
		return 1;
}
