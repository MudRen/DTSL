inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�
�����еĶ������������е����š�����������Ϣ����ǽ��������˧����
����ɫ��Ѱ�������ܡ����������������ȫ������ɴ��۾������㡣
LONG );

	set("exits", ([
		"east" : __DIR__"beidajie",
	]));
	set("objects", ([
		__DIR__"npc/xuan" : 1,
		__DIR__"npc/guan"  : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

