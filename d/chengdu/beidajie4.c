

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ���
�⡣�ϱ��Եúܷ�æ�������мҿ͵ꡣ������ͨ��������һ����·����
��·�ľ�ͷ���ǳɶ��Ľ�ұ��ˡ�
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		
		"south" : __DIR__"beidajie3",
		"north":__DIR__"dabeimen",
		"east":__DIR__"kedian",
		"west":__DIR__"dalu1",
		
	]));

	setup();
	replace_program(ROOM);
}

