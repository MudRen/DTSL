
inherit BULLETIN_BOARD;

void create()
{
        set_name("���Ź����", ({ "board" }) );
        set("location", "/d/wiz/wizroom");
        set("board_id", "news_b");
   set("long", "�������Ź���棬��ʦ�ĸ���˵����д�����\n");
  
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}

