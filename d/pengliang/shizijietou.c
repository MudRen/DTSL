// /d/pengliang/shizijietou
//room in 彭梁
inherit ROOM;

void create()
{
	set("short", "十字街头");
	set("long", @LONG
这里是梁都的正中心，一个并不宽阔的广场，铺着青石地面。原来
这里人声鼎沸，一派繁华景象，但从天下大乱以来，彭梁饱受战乱之苦，
但少帅军成立以来，这里的秩序好多了。
LONG
	);
        set("outdoors", "/d/pengliang");
       
	set("exits", ([
		"east" : __DIR__"dongdajie",
		"south" : __DIR__"nandajie",
		"west" : __DIR__"xidajie",
		"north" : __DIR__"beidajie",
	]));
set("objects", ([
		__DIR__"npc/putou" : 1,
                __DIR__"npc/guanyuan" : 1,
	]));
	setup();
}

// laowuwu 99/03/28
