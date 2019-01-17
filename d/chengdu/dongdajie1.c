
inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是成都的东大街。东边通向东城门，西边是城中心，那边传来热
闹的声音。北边有一家赌场，只听叫好声、漫骂声、吵闹嘟哝几句，又
朝别处走去。
LONG);
        set("outdoors", "成都");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"west" : __DIR__"center",
		"north":__DIR__"duchang",
		"south":__DIR__"dangpu",
	]));
	set("objects",([
		__DIR__"npc/laozhe":1,
		]));


	setup();
	replace_program(ROOM);
}

