

inherit ROOM;

void create()
{
	set("short", "�ϲ��");
	set("long", @LONG
����һ����ͨ����ʯ��·���ϱ�ͨ���ϲ��ţ����߾��Ƕ���֡���
������˲��Ǻܶࡣ
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
        "north" : __DIR__"dadongmen",
		"south" : __DIR__"nancejie2",
	]));

	setup();
	replace_program(ROOM);
}

