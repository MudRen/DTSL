
inherit BULLETIN_BOARD;

void create()
{
	set_name("ͻ�ʵ������԰�", ({ "board" }) );
	set("location", "/d/dingxiang/yizhan");
	set("board_id", "party_tj_b");
	set("long","����ͻ�ʵ��ӵ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
