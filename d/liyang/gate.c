inherit ROOM;
void create()
{
	set("short", "Ԫ˧��");
	set("long", @LONG
��������Ԫ˧�������ڵأ���ɫ����ƽʱ�������ţ���ǰ�ĸ�����
ʿ��վ�š������и�����ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"qingshilu",
		"north":"/d/clone/room/cityroom/liyang",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 4,
	]));
	set("no_clean_up", 0);
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

