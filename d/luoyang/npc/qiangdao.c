
inherit NPC;

void create()
{
   set_name("强盗",({ "qiang dao","qiang","dao" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "他是专门在秦岭打劫的强盗,无恶不做。\n");
       
   set("combat_exp",200000);
   set("str", 26);
   set("per", 22);
  set("attitude", "aggressive");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}

