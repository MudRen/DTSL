// /d/qiuci/xidajie1
// Room in 龟兹 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。西大街是商贾所在，
行人来来往往，十分热闹。东边是彭梁的十字街口。南边是一家当铺，
北面是一家钱庄。
LONG
	);
        set("outdoors", "pengliang");

	set("exits", ([
		"east" : __DIR__"shizijietou",
		"south" : __DIR__"dangpu",
                "north" : __DIR__"qianzhuang",
		"west" : __DIR__"ximen",
		
	]));

	setup();
	replace_program(ROOM);
}

