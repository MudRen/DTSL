inherit ROOM;

void create()
{
	set("short", "下邳");
	set("long", @LONG
这就是古城下邳城了，自从天下大乱以来，各路英豪接竿而起，现
在的下邳城，虽然是战略要地，但却没有经战火的洗礼。
LONG );
	set("exits", ([
		"southup" : __DIR__"baimen",
		"north" : __DIR__"shiqiao",
	]));
	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

