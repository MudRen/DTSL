
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ͨ�������¥��ʯ�ס�
LONG);
	set("exits", ([
		"westup" : __DIR__"shijie3",
		
		"eastdown" : __DIR__"shijie1",
	]));

	setup(); 
	replace_program(ROOM);
}
