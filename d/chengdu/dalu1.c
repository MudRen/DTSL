

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����·�������ǳɶ��ı���֡������ǳɶ��������������
�ǳɶ����𱤵ĵط��ˡ�
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east":__DIR__"beidajie4",
		"west":__DIR__"wansuihu",
		
	]));

	setup();
	replace_program(ROOM);
}

