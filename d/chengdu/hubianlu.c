

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����������ϰ����ϱ߾��ǳɶ������Ķ����ˡ��м���������
����������ȥ��Ѳ�������������ˡ�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"northeast":__DIR__"wansuihu",
		"southwest":__DIR__"duzunbao",
		
	]));

	setup();
	replace_program(ROOM);
}

