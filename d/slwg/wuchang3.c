
#include <room.h>

inherit ROOM;

int do_action(string arg);

void create()
{
	set("short", "���䳡");
	set("long", @LONG
������ʯ����ݵ����䳡����ʯ����ݳ�������ѧϰ�书�ĵط���
�������������վ׮������Լ����书��ֻ�����ﳾ�������������
���������������֡�
LONG
);


	set("exits", ([
		"west" :__DIR__"wuchang2",
		
	]));
	/*set("objects",([
	     __DIR__"npc/dizi":1,
	    ]));*/
       set("no_fight",1);
       set("lianwu","վ׮");
       set("over_work","���վ׮�Ѿ���ϰ�ÿ����ˣ�����ȥ�ҽ�ͷ��[task ok]��\n");
       set("work_msg",({
       	"������һ�֣�һ�������ȵ�վ�ڵ��ϣ�\n",
       	"����һ�����������˫��һ�壬���ϳ���һ��ǳ�ӡ�\n",
       	"ֻ��һ�����ӳ����˫����ȥ������˼��Σ����ȵ�վס�ˡ�\n",
       	}));
       set("outdoors", "slwg");
	setup();
}

void init()
{
  add_action("do_action","lianwu");
}

#include "work_skill.c"