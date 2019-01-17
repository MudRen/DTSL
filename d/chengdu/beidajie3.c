
inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是成都的北大街。北边通向北城门，南边显得很繁忙。有几个小
商贩推着车从你的身旁走过，嘴里还不停地吆喝着。只见几个官兵耀武
扬威地从你的身旁走过，冷冷地打量着路上的行人。
LONG);
        set("outdoors", "成都");

	set("exits", ([
		"north" : __DIR__"beidajie4",
		"south" : __DIR__"center",
		
	]));
	set("objects",([
	  "/d/clone/npc/songyuhua":1,
	  ]));

	setup();
	replace_program(ROOM);
}

