
inherit JOBNPC;
#include <ansi.h>
#include <job_money.h>

void create()
{
   int flag;
   
   flag=random(2);
   
   if(flag==0)
    set_name("����",({ "shang lv","shang","lv" }) );
   else
    set_name("�ٱ�",({ "guan bing","guan","bing" }) );
    
   set("gender", "����" );
   set("age",35);
   
   if(flag==0)
   set("long", "����һ�����ã�����������Ǯ��\n");
   else
   set("long", "����һ���ٱ����������ѹ��˲�����֬��ࡣ\n");
             
   set("chat_chance",20);
   set("chat_msg",({
    (:random_move:),
    
   }));
   
   if(flag==0)
    set("job_type","��ɱ��");
   else
    set("job_type","ɱ��");
   
   setup();
  
}

string long()
{
  if(query("target_id")==this_player()->query("id")){
    command("say ��������������ҵ����⣡��\n");
    kill_ob(this_player());
    return "";
  }
  return query("long");
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
   
   set("combat_exp",ob->query("combat_exp"));
   if(ob->query("combat_exp")<150000)
    set_this_skills("low");
   else
   if(ob->query("combat_exp")<800000)
    set_this_skills("middle");
   else
    set_this_skills("high");
    
   set_all_skill(this_object(),ob->query("max_pot")-100);
   
   copy_hp_item(ob,this_object(),"gin");
   copy_hp_item(ob,this_object(),"kee");
   copy_hp_item(ob,this_object(),"sen");
   
   set("max_force",ob->query("max_force"));
   set("force",ob->query("max_force"));
   set("target_id",ob->query("id"));
   set("last",time()+600);
   
   if(query("job_type")=="ɱ��")
   return 1;
   else
   return 2;
}

void die()
{
  object ob;
  
  ob=query_temp("last_damage_from");
  if(!ob||ob->query("id")!=query("target_id"))
  return ::die();
  
  if(query("job_type")=="ɱ��"){
    tell_object(ob,"��ɹ��ش���˹ٱ���\n");
    JOBSYS_D->give_reward_mazei(ob);
    return ::die();
  }
  
  tell_object(ob,"\n�㱾�δ���ж�ʧ���ˣ���\n");
  ob->set("dtsl_quest_toutianjf_fail",1);
  ob->delete_temp("mazei_job");
  ob->delete_temp("dtsl_job");
  return ::die();
}

void unconcious()
{
   object ob;
  
  ob=query_temp("last_damage_from");
  if(!ob||ob->query("id")!=query("target_id"))
  return ::unconcious();
  
  if(query("job_type")=="ɱ��"
  ||ob->is_killing(query("id"))){
    return ::unconcious();
  }
  
  tell_object(ob,"��ɹ��ش����"+query("name")+"��\n");
  JOBSYS_D->give_reward_mazei(ob);
  
  message_vision("\n$Nһ�Ž�$n����$n�ŵ��������ˣ���\n",ob,this_object());
  if(query("job_type")!="ɱ��")
  destruct(this_object());
  return;
}