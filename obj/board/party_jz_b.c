
inherit BULLETIN_BOARD;

void create()
{
	set_name("�Ⱥ���ի�������԰�", ({ "board" }) );
	set("location", "/d/jingzhai/door");
	set("board_id", "party_jz_b");
	set("long","���ǴȺ���ի���ӵ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
