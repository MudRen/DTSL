// /guanwai/huandi2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
���ǳǶ���һ����·��·�����ҵĳ�����ϥ�ĻĲݣ�Զ������һ�ˡ�
���Ըɿݵ������������˳�Ⱥ����ѻ���������������ڻ�Ұ��ԶԶ��ȥ��
һ�������ľ���
LONG );
	set("exits", ([
		//"east" : "/d/gaoli/road1",
		"southwest"     : __DIR__"huandi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "saiwai");
	setup();
	replace_program(ROOM);
}

