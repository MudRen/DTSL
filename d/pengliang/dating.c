inherit ROOM;

void create()
{
	set("short", "少帅府大厅");
	set("long", @LONG
这里是少帅府的大厅，大堂两边摆着兵器架，架上锋刃仍留血迹，
映着架后的战旗，分外耀眼。这里就是少帅办公和会客的地方。
LONG );
	set("exits", ([
		"south" : __DIR__"yuanzi",
        "enter":"/d/clone/room/cityroom/pengliang",
	]));
	setup();
	replace_program(ROOM);
}

