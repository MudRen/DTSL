
inherit NPC;

void create()
{
   set_name("����",({ "man" }) );
        set("gender", "����" );
        set("age", 25);
   set("long", "����һ���������ӣ���������������Ļ���\n");
       
   set("combat_exp", 500+random(500));
   setup();
   //carry_object("/d/gaoli/obj/cloth")->wear();
  
}

