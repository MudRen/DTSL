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
		"southup"     : __DIR__"shanlu2",
		"eastdown" : __DIR__"dadao2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

