
#include <room.h>

inherit ROOM;

int do_action(string arg);

void create()
{
	set("short", "���䳡");
	set("long", @LONG
������ʯ����ݵ����䳡����ʯ����ݳ�������ѧϰ�书�ĵط���
������������ʯ��������Լ����书��ֻ�����ﳾ�������������
���������������֡�
LONG
);


	set("exits", ([
		"north" :__DIR__"wuchang2",
		
	]));
	/*set("objects",([
	     __DIR__"npc/dizi":1,
	    ]));*/
       set("no_fight",1);
       set("lianwu","��ʯ��");
       set("over_work","��ľ�ʯ���Ѿ���ϰ�ÿ����ˣ�����ȥ�ҽ�ͷ��[task ok]��\n");
       set("work_msg",({
       "��һ���󺰣���ʯ���ٹ���ͷ����Ȼ���顱��һ�������˵��ϣ�\n",
       "��һ������ʯ���ٹ�ͷ�������ȵ�վ��һ�ᣬȻ���顱��һ����ʯ������������\n",
       "������������˿�������ʯ���ٹ���ͷ����Ȼ���顱��һ�������˵��ϣ�\n",
       }));
       set("outdoors", "slwg");
	setup();
}

void init()
{
  add_action("do_action","lianwu");
}

#include "work_skill.c"