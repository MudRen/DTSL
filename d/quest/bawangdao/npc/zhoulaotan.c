
inherit JOBNPC;
#include <ansi.h>
#include <job_money.h>

void create()
{
        set_name("����̾",({ "zhou lantan","zhou"}) );
        set("gender", "����" );
        set("age", 52);
        set("str",30);
        set("long","����а�̵�һ����֡�\n");
        set("combat_exp",600000);
        
        set("max_kee",3000);
        set("max_sen",3000);
        set("max_gin",3000);
        set("max_force",3000);
        set("force",3000);
        set("attitude","aggressive");
        
        setup();
  
}

int set_status(object ob)
{
  object me;
  
  me=this_object();
  
  me->set("last",time());
  me->set("target_id",ob->query("id"));
  
  me->set("combat_exp",ob->query("combat_exp")/2);
  if(ob->query("combat_exp")<150000)
    set_this_skills("low");
   else
   if(ob->query("combat_exp")<80000)
    set_this_skills("middle");
   else
    set_this_skills("high");
  set_all_skill(me,ob->query("max_pot")/2);
  copy_hp_item(ob,me,"gin");
  copy_hp_item(ob,me,"kee");
  copy_hp_item(ob,me,"sen");
  
  me->set("max_force",ob->query("max_force")/2);
  me->set("force",ob->query("max_force")/2);
  
  return 1;
}


void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
  
   if(!ob)
   return ::die();
   
   ob->add_temp("dtsl_quest_badao_killer",1);
   return ::die();
}