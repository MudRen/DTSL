
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ͨ�������¥��ʯ��.
LONG);
	set("exits", ([
		"westup" : __DIR__"shijie5",
		
		"eastdown" : __DIR__"shijie3",
	]));

	setup(); 
	replace_program(ROOM);
}
