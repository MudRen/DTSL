
inherit JOBNPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   set_name("ˮ��",({ "shui shou","shou"}) );
        set("gender", "����" );
        set("age",30);
	set("title","��ͨ����");	
   set("long", "�����ڴ���������ˮ�֡�\n");
       
   set("combat_exp",500000);
   set("str",30);
   set("cor",30);
   set_skill("force",20);
   set("force",5000);
   set("max_force",5000);
   set_this_skills("high");
   set_temp("apply/armor",50+random(50));
   set("jiali",50);
   set("attitude","aggressive");
   set("pfm_rate",80);
   setup();
  
}


void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   if(!ob) return ::die();
    
   JOBSYS_D->give_reward_haidaojob(ob,0);
   
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
	object killer;
	
	killer = this_object();
	
	if(ob->query("combat_exp")>killer->query("combat_exp"))
     	killer->set("combat_exp",ob->query("combat_exp")+300000);
	set_all_skill(killer,ob->query("max_pot")-80);
	copy_hp_item(ob,killer,"gin");
	killer->set("eff_kee",ob->query("max_kee")*3/2);
	killer->set("max_kee",ob->query("max_kee")*3/2);
	killer->set("kee",ob->query("max_kee")*3/2);
	copy_hp_item(ob,killer,"sen");
	if(ob->query("max_force")>killer->query("max_force")){
    	killer->set("max_force",ob->query("max_force")+2000);
     	killer->set("force",ob->query("max_force")+2000);
    }
    add_temp("apply/armor",100+random(200));
    return 1;	
	
}        