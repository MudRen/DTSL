inherit ROOM;
void create()
{
	set("short", "���д�·");
	set("long", @LONG
����ɽ�����·����ǿ����ͨ��һ���󳵣�·��������������ĳ�
��ӡ��·��ɽ����ȫ�ǲ����ľ������ȥ�ܲ�͸�磬������ľ�������
ż��������в��ܴ��Ƽž�����·����������ת���䡣
LONG );
	set("exits", ([
		"southdown": __DIR__"dadao3",
		"eastup": __DIR__"shanlu3",
	]));
	set("objects", ([
		__DIR__"npc/yetu" : 1,
	]));
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

