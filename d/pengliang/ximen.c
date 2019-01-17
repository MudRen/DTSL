inherit ROOM;


void create()
{
	set("short", "西门");
	set("long", @LONG
这是西城门，城门正上方刻着“西门”两个楷书大字。官兵们警惕
地注视着过往行人，你最好小心为妙。一条笔直的青石板大道向东西两
边延伸。
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"west" : __DIR__"edao4",
                "east" : __DIR__"xidajie",
	]));
         set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
	setup();
	replace_program(ROOM);
}

