inherit ROOM;
void create()
{
	set("short", "СУ��");
	set("long", @LONG
����������Ӫ��СУ����ƽʱ��ʿ�Ǿ���������������Ϻ�ƽ����
������ָ��̨���и��������ɵ���ˣ��˶�һ������һ������������Ӫ
��ɫ����ӭ���������졣ƽʱ��ʿ��һ�����������ϳ��٣����������
������Ұս����������ʳ����Ѳ�ߡ�
LONG );
	set("exits", ([
		"north" : __DIR__"junying",
	]));
	set("objects", ([
		__DIR__"npc/bing" :3,
	]));
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

