
inherit FIGHTER;

void create()
{
   set_name("铁罗汉",({ "tie luohan","tie","luohan"}) );
   set("gender", "男性" );
   set("age", 22);
		
   set("long", "这是一个铁罗汉，看起来和真人一模一样。\n");       
   set("combat_exp",5000);
   set("str", 20);
   set("per", 25);
   set_skill("force",20);
   set_skill("dodge",20);
   set_skill("parry",20);
   
   set_skill("strike",20);
   set_skill("tieluohan-skill",20);
   set_skill("lianhua-step",20);
  
   setup();
   
}

