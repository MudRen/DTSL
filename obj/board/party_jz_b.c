
inherit BULLETIN_BOARD;

void create()
{
	set_name("´Èº½¾²Õ«µÜ×ÓÁôÑÔ°å", ({ "board" }) );
	set("location", "/d/jingzhai/door");
	set("board_id", "party_jz_b");
	set("long","ÕâÊÇ´Èº½¾²Õ«µÜ×ÓµÄÁôÑÔ°å¡£\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
