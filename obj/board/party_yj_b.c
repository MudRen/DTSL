
inherit BULLETIN_BOARD;

void create()
{
	set_name("�Ľ��ɵ������԰�", ({ "board" }) );
	set("location", "/d/gaoli/xingguan");
        set("board_id", "party_yj_b");
	set("long","�����Ľ��ɵ��ӵ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
