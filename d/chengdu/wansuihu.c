

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��������������沨ƽ�˾����ϱ߿��Կ���һ���Ǳ����Ǿ�������
�Ĵ��Ķ����ˡ�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east":__DIR__"dalu1",
		"southwest":__DIR__"hubianlu",
		
	]));

	setup();
	replace_program(ROOM);
}

