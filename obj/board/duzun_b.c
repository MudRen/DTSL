
inherit BULLETIN_BOARD;

void create()
{
        set_name("�������԰�", ({ "board" }) );
        set("location", "/d/chengdu/duzunbao");
        set("board_id", "duzun_b");
   set("long", "���Ƕ���ר�õ����԰�.\n");
  
        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}

