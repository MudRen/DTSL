
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǳɶ��Ķ���֡�����ͨ�򶫳��ţ������ǳ����ģ��Ǳߴ�����
�ֵ�������������һ�Ҷĳ���ֻ���к�������������������漸�䣬��
������ȥ��
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"west" : __DIR__"center",
		"north":__DIR__"duchang",
		"south":__DIR__"dangpu",
	]));
	set("objects",([
		__DIR__"npc/laozhe":1,
		]));


	setup();
	replace_program(ROOM);
}

