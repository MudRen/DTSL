
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣������������ͨ���
�⡣�����Եúܷ�æ�������ǳɶ����ξ֣��в���������ʿ�������γ�
��������ȥ���ϱ���һ��Ǯׯ����ǰ�Ľ����������������ҫ��������
�⡣
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : __DIR__"xidajie1",
		"west" : __DIR__"daximen",
		"south":__DIR__"qianzhuang",
		"north":__DIR__"yanju",
	]));
	set("objects",([
		__DIR__"npc/dizi":1,
		]));

	setup();
	replace_program(ROOM);
}

