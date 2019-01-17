
inherit BULLETIN_BOARD;

void create()
{
	set_name("ŞÄ½£ÅÉµÜ×ÓÁôÑÔ°å", ({ "board" }) );
	set("location", "/d/gaoli/xingguan");
        set("board_id", "party_yj_b");
	set("long","ÕâÊÇŞÄ½£ÅÉµÜ×ÓµÄÁôÑÔ°å¡£\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
