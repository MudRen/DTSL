
#include <room.h>

inherit ROOM;

int do_action(string arg);

void create()
{
	set("short", "���䳡");
	set("long", @LONG
������ʯ����ݵ����䳡����ʯ����ݳ�������ѧϰ�书�ĵط���
�����������͵����д��书��ֻ�����ﳾ���������������������
������֡�
LONG
);


	set("exits", ([
		"east" :__DIR__"wuchang1",
		
	]));
	set("objects",([
	     __DIR__"npc/dizi":2,
	    ]));
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}

void init()
{
  add_action("do_action","qiecuo");
}

#include "get_skill1.c"