inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣��������̼����ڣ�
��������������ʮ�����֡�������������ʮ�ֽֿڡ��ϱ���һ�ҷ��ݣ���
����һ�ҿ�ջ��
LONG
	);
       set("outdoors", "pengliang");

	set("exits", ([
		"west" : __DIR__"shizijietou",
		"south" : __DIR__"duyimei",
                "north" : __DIR__"kezhan",
		"east" : __DIR__"dongmen",
		
	]));

	setup();
	replace_program(ROOM);
}

