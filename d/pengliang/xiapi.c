inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ǹų��������ˣ��Դ����´�����������·Ӣ���ӸͶ�����
�ڵ������ǣ���Ȼ��ս��Ҫ�أ���ȴû�о�ս���ϴ��
LONG );
	set("exits", ([
		"southup" : __DIR__"baimen",
		"north" : __DIR__"shiqiao",
	]));
	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

