
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ͨ�������¥��ʯ��.
LONG);
	set("exits", ([
		"westup" : __DIR__"shijie4",
		
		"eastdown" : __DIR__"shijie2",
	]));

	setup(); 
	replace_program(ROOM);
}
