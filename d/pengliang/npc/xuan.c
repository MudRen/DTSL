
inherit NPC;

void create()
{
   set_name("宣永",({ "xuan yong" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "他就是少帅军的彭梁大总管。\n");
       
   set("combat_exp",600000);
   set("str", 46);
   set("per", 42);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/junfu")->wear();
   carry_object(__DIR__"obj/gangjian")->wield();
  
}

