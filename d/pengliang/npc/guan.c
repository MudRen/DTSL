
inherit NPC;
inherit JOIN;
void create()
{
   set_name("��Ա",({ "guan yuan" }) );
        set("gender", "����" );
        set("age", 42);
   set("long", "���������Ĺ�Ա��ר�Ÿ���ʿ����ѵ����\n");
       
   set("combat_exp", 500000);
//  set("shili","wang");
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
  
}



