
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǳɶ��ĳ����ģ���һ�����ֵ�С�㳡��������ʯ���档����
�кܶ����ơ����յ��ˣ������Ⱥ���ǳ����֡���ʱ�м������𱤵�
���Ӵ���������߹����������룬������ʮ�����硣�ɶ��ش����У���
���ս�һ�����ʮ�ֵ����ԡ�
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"west" : __DIR__"xidajie1",
		"south" : __DIR__"nandajie1",
		"north" : __DIR__"beidajie3",
	]));
	set("objects",([
		__DIR__"npc/xiaojie":1,
		__DIR__"npc/wushi":1,
		]));

	setup();
	replace_program(ROOM);
}

