
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("弟子", ({ "dizi","di","zi"}) );
       set("gender", "男性" );
	   set("title","川帮弟子");
       set("age", 25);
       set("long",
               "他是四川第一大帮川帮的入门弟子。\n");
       set("combat_exp",40000);
       set("attitude", "peaceful");
	   
	   set("force",300);
	   set("max_force",300);
	   set_skill("force",40);
	   set_skill("fork",40);
	   setup();
 carry_object(__DIR__"obj/cloth")->wear();
 carry_object(__DIR__"obj/fork")->wield();

}










