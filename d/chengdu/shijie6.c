
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ͨ�������¥��ʯ��.
LONG);
	set("exits", ([
		"westup" : "/d/yinkui/door",
		
		"eastdown" : __DIR__"shijie5",
	]));

	setup(); 
	replace_program(ROOM);
}
