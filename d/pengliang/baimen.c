inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����������İ���¥����¥����һ�Ѵ��Σ��������ż��߰ߣ���˵
��������������ģ��Ƿ�����ģ�˭Ҳ˵���塣
LONG );
	set("exits", ([
		"northdown" : __DIR__"xiapi",
	]));
	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

