
#include <room.h>

inherit ROOM;

int do_action(string arg);

void create()
{
	set("short", "���䳡");
	set("long", @LONG
������ʯ����ݵ����䳡����ʯ����ݳ�������ѧϰ�书�ĵط���
������������ɳ��������Լ����书��ֻ�����ﳾ�������������
���������������֡�
LONG
);


	set("exits", ([
		"south" :__DIR__"wuchang2",
		
	]));
	/*set("objects",([
	     __DIR__"npc/dizi":1,
	    ]));*/
       set("no_fight",1);
       set("lianwu","��ɳ��");
       set("over_work","��Ĵ�ɳ���Ѿ���ϰ�ÿ����ˣ�����ȥ�ҽ�ͷ��[task ok]��\n");
       set("work_msg",({
       "�����ɳ��žž��ȥ��������ѧ����Ϊ���˽�һ������ߣ�\n",
       "��˫ȭ�������������ɳ����ž���죬�������\n",
       "��һ���ȭ��ȥ��ֻ��ɳ���һΣ��������ѿ�����\n",
       }));
       set("outdoors", "slwg");
	setup();
}

void init()
{
  add_action("do_action","lianwu");
}

#include "work_skill.c"