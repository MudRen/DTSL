
inherit BULLETIN_BOARD;

void create()
{
        set_name("�������԰�", ({ "board" }) );
        set("location", "/d/dajianglian/mumen");
        set("board_id", "dajiang_b");
   set("long", "���Ǵ���ר�õ����԰�.\n");
  
        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}

