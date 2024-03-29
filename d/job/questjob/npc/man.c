
inherit NPC;

#include <ansi.h>
#include <job_money.h>

void create()
{
   set_name("中年男子",({ "nan zi","nan"}) );
        set("gender", "男性" );
        set("age",25);

   set("long", "这是阴癸派的弟子，据说最近正在躲避本派长老的追杀。\n");

   set("combat_exp", 30000);
   set("str", 20);
   set("per", 10);

   set_skill("strike",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("cuff",100);

   set_skill("jiutian-huanzhang",100);
   set_skill("linglong-yuquan",100);
   set_skill("tianmo-huanzong",100);

   set("max_kee",2000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   setup();

}

void die()
{
   object ob;
   int exp,pot,silver;

   ob=query_temp("last_damage_from");
   if(!ob) return ::die();
   if(ob->query("id")!=query("target_id"))
   return ::die();

   exp=R_JOB+30+random(50);
   pot=ob->query("max_pot")/3;
   silver=ob->query("max_pot");

   ob->add("combat_exp",exp);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot"))
    ob->set("potential",ob->query("max_pot"));
   ob->add("deposit",silver);
   add_shili(ob,exp/10,silver/10);
   tell_object(ob,"在这次行动中你得到了"+HIW+chinese_number(exp)+NOR+"点经验值，\n"+
                  "                    "+HIY+chinese_number(pot)+NOR+"点潜能，"+
                  MONEY_D->money_str(silver)+"。\n");
   message_vision("\n$N仰天长叹：如今这个世道，做个男人都好难啊\n",this_object());
   return ::die();
}

// #include "job_npc.c"
