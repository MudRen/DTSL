
inherit BULLETIN_BOARD;

void create()
{
	set_name("����������԰�", ({ "board" }) );
	set("location", "/d/luoyang/zhulou");
	set("board_id", "party_hj_b");
	set("long","���ǻ����ɵ��ӵ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
