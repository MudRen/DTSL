
inherit BULLETIN_BOARD;

void create()
{
        set_name("��ʦ�����ǳ̰�", ({ "taskboard" }) );
        set("location", "/d/wiz/wizroom5");
        set("board_id", "task_board_b");
   set("long", "������ʦ�������̼�¼�档���λ��ʦ���Լ���\n"+
               "�������̼�¼������໥��Ϻá�\n");
  
        setup();
        set("capacity",300);
        replace_program(BULLETIN_BOARD);
}

