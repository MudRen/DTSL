
#include <room.h>

inherit ROOM;

int do_action(string arg);

void create()
{
	set("short", "������");
	set("long", @LONG
������ʯ����ݵ���������������������ҽ�ͷ�д���������߼�
�ܵ���Ϊ���������ʲô�����׵ģ�ֻҪ���ͷѯ�ʡ��д衱�Ϳ����ˡ�
�кܶ�������������д蹦��
LONG
);


	set("exits", ([
		"north" :__DIR__"fangting",
              
	]));
	set("objects",([
	    __DIR__"npc/jiaotou":2,
	    ]));
       set("no_fight",1);
      // set("outdoors", "slwg");
	setup();
}

void init()
{
  add_action("do_action","qiecuo");
}

#include "get_skill.c"