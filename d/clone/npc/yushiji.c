
inherit NPC;

void create()
{
   set_name("������",({ "yu shiji","yu","shiji" }) );
        set("gender", "����" );
        set("age", 42);
        set("tetle","��ʷ����");
   set("long", "�����峯��������,������µĺ��ˡ�\n");
   set("combat_exp",6000);
   set("str", 28);
   set("per", 23);
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
   carry_object(__DIR__"obj/guanxue")->wear();
}

