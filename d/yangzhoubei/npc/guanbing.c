
inherit NPC;

void create()
{
   set_name("官兵",({ "guan bing","guan","bing" }) );
        set("gender", "男性" );
           set("long", "这是一个到处洗劫老百姓的官兵。\n");
          set("combat_exp", 5000);
   set("str", 30);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/junfu")->wear();
  carry_object(__DIR__"obj/blade")->wield();
}

