// ɽ��
// gaoshan0.c
// augx@sj 2/27/2002

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","��ɽ����");
	set("long",
"���������ߵ�ɽ�壬�Ӱ�ɽ������������ƣ���ɽ���������������Ų���
������ݣ����в��ٺ����Ķ����û����ɽ��������ҩ�Ĳ��أ����궼������
�Ĳ�ҩ��æµ��䡣
"); 

	set("objects",([
		__DIR__"npc/xunbu" : 2,
	]));
        
	set("exits",([
		"west"		: "/d/chengdu/road1",
		"northup"	: __DIR__"gaoshan1",
		"southup"	: __DIR__"gaoshan2",
		"eastup"	: __DIR__"gaoshan3",
	]));
	
	set("outdoors", "�ɶ�����");
	set("incity",1);
	setup();
}

int clean_up()
{
	return 1;
}

// Added by mxzhao 2004/03/06
int valid_leave(object me, string dir)
{
	//if (!wizardp(me) && dir != "west")
	if (dir != "west")
	{
		return notify_fail("�˵ؽ������޳�û����ֹͨ�С�\n\n\t\t�ɶ�֪����\n");
	}

	return ::valid_leave(me, dir);
}
// End
