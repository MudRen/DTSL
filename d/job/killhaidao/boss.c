
inherit JOBNPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   set_name("����",({ "chuan zhang","zhang"}) );
   set("gender", "����" );
   set("age",30);
   set("title","��ͨ����");	
   set("long", "�������Ҵ��Ĵ�����\n");
       
   set("combat_exp",500000);
   set("str",30);
   set("cor",30);
   set_skill("force",20);
   set("force",5000);
   set("max_force",5000);
   set_this_skills("high");
   set_temp("apply/armor",50+random(50));
   set("chat_chance_combat",30);
   set("jiali",100);
   set("attitude","aggressive");
   set("pfm_rate",70);
   setup();
  
}


void die()
{
   object ob;
         
   ob=query_temp("last_damage_from");
   if(!ob) return ::die();
   
   if(query("fu",1))
   JOBSYS_D->give_reward_haidaojob(ob,3/2);
   else
   JOBSYS_D->give_reward_haidaojob(ob,2);
   
   return ::die();
}

int chat()
{
   string *pfm;
   
   pfm=query("can_perform");
   
   if(arrayp(pfm)&&is_fighting()&&random(100)>query("pfm_rate")){
     set("apply_points",200);
     command("perform "+pfm[random(sizeof(pfm))]);
     return 1;
   }
   
   return ::chat();
}        

int set_status(object ob)
{
	object boss;
	
	boss = this_object();
	
	if(ob->query("combat_exp")>boss->query("combat_exp"))
     	boss->set("combat_exp",ob->query("combat_exp")+400000);
	set_all_skill(boss,ob->query("max_pot")-70);
	copy_hp_item(ob,boss,"gin");
	boss->set("eff_kee",ob->query("max_kee")*3/2+2000);
	boss->set("max_kee",ob->query("max_kee")*3/2+2000);
	boss->set("kee",ob->query("max_kee")*3/2+2000);
	copy_hp_item(ob,boss,"sen");
	if(ob->query("max_force")>boss->query("max_force")){
     	boss->set("max_force",ob->query("max_force")+4000);
     	boss->set("force",ob->query("max_force")+4000);
    }
    add_temp("apply/armor",100+random(200));
    return 1;
	
}
        