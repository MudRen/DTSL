
inherit ROOM;


void create ()
{
  set ("short","�Ž���ջ");
  set ("long", @LONG
������һ�ҿ�ջ���������Ž����˺ܶ࣬������ҿ�ջ����������
��С��������ȥ��æ����ͣ��ֻ����һ�������������˽�������С����
æ����ȥ���к���
LONG);

  set("exits", ([ 

 "north":__DIR__"dongdajie2",
 "enter":__DIR__"wofang",

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
