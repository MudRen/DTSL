
inherit BULLETIN_BOARD;

void create()
{
        set_name("�л����԰�", ({ "board" }) );
        // set("location", "/d/clone/room/hanghui/room");
        set("location", "/u/mudren/workroom");
        set("board_id", "hanghui_b");
        set("long", "���Ǵ���˫�����л����԰棬�������Ժ�����ͨ��������ϵ��\n");

        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}
