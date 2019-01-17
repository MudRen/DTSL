
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("老和尚",({ "lao heshang","heshang","lao"}) );
        set("gender", "男性" );
        set("age", 70);
        set("str",30);
        set("class","bonze");
        set("long","这是一个老和尚，年老体弱。\n");
        set("combat_exp",600000);
        
        set("max_kee",3000);
        set("max_sen",3000);
        set("max_gin",3000);
        set("max_force",3000);
        set("force",3000);
       
        setup();
  
}

void die()
{
  object ob,*target;
  int i;
  
  ob=query_temp("last_damage_from");
  
  if(!ob||!ob->query_temp("dtsl_quest_badao_help_ok"))
  return ::die();
 
  target=children("/d/chengdu/npc/shiqingxuan");
  for(i=0;i<sizeof(target);i++)
   if(objectp(target[i])&&environment(target[i])){
    target[i]->set("can_kill_enemy",1);
    target[i]->clear_enemy_flag();
   }
  ob->delete_temp("dtsl_quest_badao_help_ok");
  ob->set("dtsl_quest_badao_help_ok",1);
  
  CHANNEL_D->do_channel(this_object(),"rumor","据说天君出现于巴蜀地区！\n");
  
  return ::die();
 
}