
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ӭ����");
  set ("long", @LONG
�������������Ŀ�ջ--ӭ���ݡ�ÿ�춼�кܶ���������Ͷ�ޡ���
�ڱ������ң���Ͷ�޶������ѵİ��ա���С������æ����ͣ��ֻ������
�������˽�������С����æ��ȥ���к���
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie1",
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
