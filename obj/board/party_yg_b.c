
inherit BULLETIN_BOARD;

void create()
{
	set_name("����������԰�", ({ "board" }) );
	set("location", "/d/yinkui/door");
	set("board_id", "party_yg_b");
	set("long","���������ɵ��ӵ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
