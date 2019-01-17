// Room: /d/longyan/road2.c

inherit ROOM;

void create()
{
	set("short", "龙眼村街道");
	set("long", @LONG
这里是一条寂静的村间小道，远离集市的喧嚣。道路两旁
是普通的农房，北边是一间打铁铺。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"center",
]));

	setup();
	replace_program(ROOM);
}
