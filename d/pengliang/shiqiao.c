inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ���ոս��ɵ�ʯ�ţ�������ʯ�ݳɡ����µĺ�ˮ��ɼ��ס�
����С���ںӵ�������ȥ���ɴ����Ͼ����������ˡ�
LONG );
	set("exits", ([
		"northwest" : __DIR__"edao3",
		"south" : __DIR__"xiapi",
	]));
	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

