
inherit NPC;
inherit F_DEALER;
inherit F_REPAIR;
void create()
{
   set_name("铁匠",({ "tie jiang","tie","jiang","tiejiang" }) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "这是洛阳的铁匠，他打造的兵器都是很好。\n");

   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("vendor_goods",({
	  __DIR__"obj/changjian",
	  __DIR__"obj/blade",
	  __DIR__"obj/axe"
	  }));
   setup();
   // carry_object(__DIR__"obj/cloth")->wear();

}

void init()
{
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_repair",({"repair","xiu"}));

}
