
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�ϱ����ϳ���ͨ���
�⡣�����Եúܷ�æ��������һ�ұ����̣����洫�������ô���������
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"nandajie1",
		"south" : __DIR__"dananmen",
		"east":__DIR__"bingqipu",
	]));
	set("objects",([
 "/d/job/killerjob/yangxu-yan":1,
		]));

	setup();
	replace_program(ROOM);
}

