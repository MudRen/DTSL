// /d/gaoli/baihuuedajie3
// Room in 高丽
inherit ROOM;
void create()	
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，因为战争的原因，越向前走行人越来越少，
不时有人骑着马匆匆而过。大道往东进入新罗境内。北边通向高丽城。
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"west" : __DIR__"baihumen",
                "southwest" : __DIR__"dadao8",
		"east" : __DIR__"jiangkou",
	]));
       setup();
	replace_program(ROOM);
}	
