// Room: /d/death/gateway.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"���޴��"NOR);
	set("long", @LONG
����������һ����ɭ�Ĵ��ǰ�������Ĺ���Ƕ������ڴ˽�������
�����У�Ϊ�Լ���ǰ��������Ϊ���ŨŨ��������������ܣ�����
��Զ������ɢȥ�Ƶġ����ϵ��м�յ��ƣ���Լ���ռ�ʮ��ڤ������Ӱ��
LONG);
	set("exits", ([ 
		"out" : "/d/death/gate",
	]));
	set("no_fight", 1);
set("no_quit",1);
	set("objects", ([
		__DIR__"npc/yanluo": 1,
           
	]) );
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;
	if( dir == "out") 
	     return notify_fail(HIW"��������ȵ�����û�л�ͷ·�ˣ�\n"NOR);
	else return 1;
}
