
inherit BULLETIN_BOARD;

void create()
{
        set_name("�μұ����԰�", ({ "board" }) );
        set("location", "/d/lingnan/door");
        set("board_id", "songjia_b");
   set("long", "���ǹ��μұ�����ʹ�õ����԰�.\n");
  
        setup();
        set("capacity", 280);
        replace_program(BULLETIN_BOARD);
}

