
inherit NPC;

void create()
{
   set_name("李渊",({ "li yuan","li","yuan" }) );
        set("gender", "男性" );
        set("title", "李阀阀主" );
        set("age", 55);
   set("long", "这就是长安李阀的阀主李渊。\n");
   set("combat_exp", 500000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1500);
   set("max_force",1500);
   set("shili",([
      "leader":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/longpao")->wear();
  
}

