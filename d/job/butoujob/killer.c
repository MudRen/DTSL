
inherit JOBNPC;

#include <ansi.h>
#include <job_money.h>


void create()
{
   set_name("����",({"dao zei","zei"}));
   set("gender", "����" );
   set("age", 42);
   set("long", "����һ�������ڽ����ĵ��������ձ������Ĳ�ͷͨ����\n");
       
   set("combat_exp",100000);
   set("str", 28);
   set("per", 20);  
   set("max_force",1500);
   set("force",1500);
   set("max_gin",1500);
   set("max_kee",1500);
   set("max_sen",1500);
   set("jiali",50);
   
   set("chat_chance",30);
   set("chat_msg",({
    (:random_move:),
   }));
   
   setup();
  
}

void die()
{
	object ob;
	int lev;
	
	ob=this_object()->query_temp("last_damage_from");
	
	if(!ob) return ::die();		
	
	if(query("name")=="ʯ֮��")
	 lev=2;
	else
	 lev=1;
	JOBSYS_D->give_reward_butoujob(ob,this_object(),lev);
	
	return ::die();
}

int set_status()
{
    JOBNPC_D->set_butoujob_killer(this_object(),0);
    return 1;
    
}

int accept_fight(object who)
{
  return 0;
}

void kill_ob(object ob)
{
  if(query("max_kee")<ob->query("max_kee")){
  copy_hp_item(ob,this_object(),"gin");
  copy_hp_item(ob,this_object(),"kee");
  copy_hp_item(ob,this_object(),"sen");}
  if(query("max_force")<ob->query("max_force"))
  copy_force(ob,this_object());
  return ::kill_ob(ob);
}