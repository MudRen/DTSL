
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������ݳǵı����̡�ƽ�����˳���ӿ��������ͣ���Ŷ��һ�����
��ʮ�������ϵĹ깫���������ͣ���Ӧ��������ʫ��ʮ��һ�������Σ�Ӯ
����¥��������
LONG);

	set("exits", ([ 
 		"west":__DIR__"guangchang",
 		"south":__DIR__"donghudi",
 		"southwest":__DIR__"matou",
        ]));
	set("objects",([
		__DIR__"npc/guigong":1,
	]));

    set("outdoors","yangzhou");
    set("no_fight",1);
	
	set("valid_startroom", 1);
	setup();
 
}
int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="southwest")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("�깫��ס���㣺�͹٣�����û��Ǯ��!\n");
		else return notify_fail("�깫˵�����͹٣���ô�ţ���Ӳ������!\n");
		return ::valid_leave(me,dir);
		return 1;
}
