
inherit BULLETIN_BOARD;

void create()
{
        set_name("��ɳ�����԰�", ({ "board" }) );
        set("location", "/d/haisha/cunxi");
        set("board_id", "haisha_b");
   set("long", "���Ǻ�ɳ��ר�õ����԰�.\n");
  
        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}

