
inherit BULLETIN_BOARD;

void create()
{
        set_name("������Ժ���԰�", ({ "board" }) );
	set("location", "/d/chanyuan/miaodoor");
	set("board_id", "party_cy_b");
        set("long","���Ǿ�����Ժ���ӵ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
