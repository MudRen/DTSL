
inherit JOBNPC;

#include <job_money.h>


void create()
{
   
   
   set_name("����",({"xia ke","ke"}) );
   set("gender", "����" );
   
    
   set("long", "����һ�����͡�\n");       
   
   set("dex",20+random(10));
   set("str",20+random(10));     
   
   set_temp("apply/dodge",50+random(50));
   set_temp("apply/armor",50+random(50));
  
   setup();
  
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
   
   string *pfm;
   
   if(clear())
   return 1;
   
   pfm=query("can_perform");
   
   if(query("combat_exp")>=500000&&
      arrayp(pfm)&&is_fighting()&&random(100)>query("pfm_rate")){
     set("apply_points",250);
     command("perform "+pfm[random(sizeof(pfm))]);
     return 1;
   }
   
   return ::chat();
}

int set_status(object ob)
{
   JOBNPC_D->set_tjjyjob_killer(this_object(),ob);
   return 1;
}

void die()
{
   object ob;
   int i;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   
   if(ob->query("id")==query("target_id"))
   	   ob->set_temp("come_killer",1);
   
   return ::die();
}