
inherit BULLETIN_BOARD;

void create()
{
        set_name("行会留言版", ({ "board" }) );
        // set("location", "/d/clone/room/hanghui/room");
        set("location", "/u/mudren/workroom");
        set("board_id", "hanghui_b");
        set("long", "这是大唐双龙的行会留言版，买主可以和卖主通过这里联系。\n");

        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}
