
inherit BULLETIN_BOARD;

void create()
{
	set_name("����������԰�", ({ "board" }) );
	set("location", "/d/dongming/door");
	set("board_id", "party_dm_b");
	set("long","���Ƕ����ɵ��ӵ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
