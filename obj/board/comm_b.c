inherit BULLETIN_BOARD;
void create()
{
    set_name("��ҽ�����", ({ "board" }) );
    set("location", "/u/kouzhong/chatroom");
    set("board_id", "comm_b");
    set("no_get",1);
     set("long", "����һ�鹩��ҽ����ĵõ����԰塣\n");
        setup();
        set("unit","��");
        set("capacity", 218);
        replace_program(BULLETIN_BOARD);
}

