inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣���߾��Ǵ���������
��˧���������İ칫�ص㣢��˧����
LONG );
        set("outdoors", "pengliang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"damen",
		"north" : __DIR__"shizijietou",
		"south" : __DIR__"nanmen",
	]));
	setup();
	replace_program(ROOM);
}

