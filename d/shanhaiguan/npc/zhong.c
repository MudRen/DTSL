
inherit NPC;

void create()
{
   set_name("����",({ "bangzhong","zhong" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "������Į��İ��ڣ������������������ˡ�\n");
       
   set("combat_exp",200000);
   set("attitude", "peaceful");
   setup();
   //carry_object("/d/gaoli/obj/cloth")->wear();
   //carry_object("/d/obj/gangjian")->wield();
  
}

