

inherit ROOM;

void create()
{
	set("short", "�ϲ��");
	set("long", @LONG
����һ����ͨ����ʯ��·���ϱ������ؾ����ϲ��ţ����߲�Զ��
����֡���������˲��Ǻܶࡣ
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"nancejie1",
		"south" : __DIR__"xiaonanmen",
	]));

	setup();
	replace_program(ROOM);
}

