
inherit BULLETIN_BOARD;

void create()
{
        set_name("��ʦ���԰�", ({ "board" }) );
        set("location", "/d/wiz/wizroom2");
        set("board_id", "wiz_b");
   set("long", "������ʦר�õ����԰�.\n");
  
        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}

