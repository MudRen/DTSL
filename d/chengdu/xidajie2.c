
inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。西边是西城门通向城
外。东边显得很繁忙。北边是成都的盐局，有不少武林人士护卫着盐车
朝那里走去。南边有一家钱庄，门前的金字招牌在阳光的照耀下闪闪发
光。
LONG);
        set("outdoors", "成都");

	set("exits", ([
		"east" : __DIR__"xidajie1",
		"west" : __DIR__"daximen",
		"south":__DIR__"qianzhuang",
		"north":__DIR__"yanju",
	]));
	set("objects",([
		__DIR__"npc/dizi":1,
		]));

	setup();
	replace_program(ROOM);
}

