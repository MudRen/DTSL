inherit ROOM;
void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����������ؾ���פ�أ��������Ƕ�����Ӫռ������Ӵ󣬱�����
Ӫ����������СУ������������ų�ǽ��һ����ǡ�
LONG );
	set("exits", ([
		"south" : __DIR__"xiaojiaochang",
		"north" : __DIR__"yingfang",
		"west"  : __DIR__"qingshilu",
		"east"  : __DIR__"malan",
	]));
	set("objects", ([
		__DIR__"npc/bing" :2,
	]));
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

