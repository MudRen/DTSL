
inherit BULLETIN_BOARD;

void create()
{
        set_name("���԰�", ({ "board" }) );
        set("location", "/d/yangzhou/zuihualou");
        set("board_id", "pal_b");
   set("long", "��ʲô��Ҫ˵,��ʲô���,�����԰�!\n");
  
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

