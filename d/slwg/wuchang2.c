
#include <room.h>

inherit ROOM;

int do_action(string arg);

void create()
{
	set("short", "���䳡");
	set("long", @LONG
������ʯ����ݵ����䳡����ʯ����ݳ�������ѧϰ�书�ĵط���
�������������÷��׮������Լ����书��ֻ�����ﳾ�����������
�����������������֡�
LONG
);


	set("exits", ([
		"west" :__DIR__"beilang1",
		"east":__DIR__"wuchang3",
		"south":__DIR__"wuchang4",
		"north":__DIR__"wuchang5",
               
	]));
	/*set("objects",([
	     __DIR__"npc/dizi":1,
	    ]));*/
       set("no_fight",1);
       set("lianwu","÷��׮");
       set("over_work","���÷��׮�Ѿ���ϰ�ÿ����ˣ�����ȥ�ҽ�ͷ��[task ok]��\n");
       set("work_msg",({
       "��վ��÷��׮�ϲ�ͣ���߶���������ѧ����Ϊ���˽�һ������ߣ�\n",
       "����÷��׮�Ϸ����߶��������Լ��ļ�������Щ��ߡ�\n",
       "����÷��׮����ת��Ų����Խ��Խ��ӯ�ˡ�\n",
       }));
       set("outdoors", "slwg");
	setup();
}

void init()
{
  add_action("do_action","lianwu");
}

#include "work_skill.c"