
inherit BULLETIN_BOARD;

void create()
{
        set_name("��������԰�", ({ "board" }) );
        set("location", "/d/cahc/chengqingdian");
        set("board_id", "lifa_b");
   set("long", "���ǳ����ר�õ����԰�.\n");
  
        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}

