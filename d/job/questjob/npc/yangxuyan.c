
inherit NPC;
#include <ansi.h>
#include <job_money.h>

void create()
{
  
   set_name("杨虚彦",({ "yang xuyan","yang" }) );
        set("gender", "男性" );
	set("title",BLU"影子刺客"NOR);
        set("age", 32);
   set("long", "这是武林中闻名的刺客--[影子刺客]杨虚延。只要有钱，他就会为你杀人。\n");
       
   set("combat_exp", 1000000);
   set("str", 28);
   set("per", 22);
   set("gin",1000);
   set("kee",1500);
   set("max_kee",1500);
   set("sen",1500);
   set("max_sen",1500);
   set("force",1500);
   set("max_force",1500);
   set_skill("force",150);
   set_skill("dodge",150);
   set_skill("sword",160);
   set_skill("niaozong-shu",150);
   set_skill("yingzi-jianfa",150);

   
   setup();
  carry_object(__DIR__"obj/changjian")->wield();
   
}


#include "job_npc.c"