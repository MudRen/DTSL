inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǿ�Ӫ����������һɫ�ĸ�ͷս��Ӫ�е�ս����Ǿ�ѡ����
����׳������������������ڶ��Ͳ��ϣ�һ�����ζ�Ͳ��ϵĻ��ζ
��Ʈ�˹�����
LONG );
	set("exits", ([
		"west" : __DIR__"junying",
	]));
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

