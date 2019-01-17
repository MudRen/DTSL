
inherit JOBNPC;
#include <job_money.h>
#include <ansi.h>


void create()
{
   set_name("����",({ "dao zei","dao","zei"}) );
        set("gender", "����" );
        set("age",42);
        set("long","����һ���������ĺ�������\n");
        
     set("combat_exp",10000);
     set("dex",30);
     set("str",30); 
     set("chat_chance",30);
     set("chat_msg",({
      (:random_move:),
     }));
     setup();
  
}
void die()
{
  object ob;
  
  ob=query_temp("last_damage_from");
  if(!objectp(ob)) return ::die();
  if(!ob->query_temp("gaoli_kill_job")||
     query("target_id")!=ob->query("id"))
  return ::die();
    
  message_vision(HIR"\n$N��������������������һ���ú�����\n"NOR,this_object());
  
  ob->set("busy_time",time());
  ob->delete_temp("gaoli_kill_job");
  ob->delete_temp("dtsl_job");
  
  JOBSYS_D->give_reward_gaolijob(ob);
  
  return ::die();
}
  

int clear()
{
  if(time()-query("last")<4000)
  return 0;
  if(!query("no_msg")){
  message_vision("$N�Ҵҵ����ˡ�\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}


int chat()
{
   object ob;
   if(clear())
   return 1;
   
   return ::chat();
}

int set_status(object ob)
{
   
   JOBNPC_D->set_gaolijob_killer(this_object(),ob);
   return 1;
}

void init()
{
   object ob;
   
   ob=this_player();
   
   if(!ob) return;
   
   if(ob->query("id")==query("target_id")){
      remove_call_out("do_action");
      call_out("do_action",1,ob);}
   return;
}

void do_action(object ob)
{
  if(!ob||
   environment(ob)!=environment())
   return;
  
  switch(random(2)){
  
  case 0:
     command("pei "+ob->query("id"));
    
     break;
  case 1:
     command("fear");
     random_move();
    }
  return;
}