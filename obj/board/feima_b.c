
inherit BULLETIN_BOARD;

void create()
{
        set_name("�����������԰�", ({ "board" }) );
        set("location", "/d/feima-muchang/door");
        set("board_id", "feima_b");
   set("long", "���Ƿ�������ר�õ����԰�.\n");
  
        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}

