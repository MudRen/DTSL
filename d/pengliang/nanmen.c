inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������š���������˧����פ���ĳ��С�����������Ͷ����
�˷ǳ��ࡣ����վ�ż����ٱ����ڼ�����������ˡ�
LONG );
        set("outdoors", "pengliang");
	set("no_clean_up", 0);

	set("exits", ([
		"north" : __DIR__"nandajie",
		"south" : "/d/xingyang/dadao4",
	]));
	set("objects",([
	__DIR__"npc/bing":2,
        __DIR__"npc/wujiang":1,
	]));
	setup();
	replace_program(ROOM);
}

