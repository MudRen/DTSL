
inherit NPC;

void create()
{
   set_name("�",({ "li jing","li","jing" }) );
        set("gender", "����" );
        set("age", 25);
   set("long", "����ǳ������������������\n");
   set("combat_exp", 500000);
   set("str", 28);
   set("per", 24);
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set_skill("blade",150);
   set_skill("xuezhan-shishi",160);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}


int surrender(object killer,object victim)
{
   if(!killer->query_temp("bai_ke"))
   return 1;
   killer->delete_temp("bai_ke");
   killer->set_temp("bai_ke_ok",1);
   return 1;
}