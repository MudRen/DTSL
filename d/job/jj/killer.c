
inherit JOBNPC;

#include <ansi.h>
#include <job_money.h>




void create()
{   
   set_name("����",({"dao zei","zei"}));
   set("gender","����");
   set("age",30);
   set("long","����һ��������\n");
       
   set("combat_exp",50000);
   set("str", 25);
   set("per", 25);
   set("dex",30);
      
   set("gin",300);
   set("eff_gin",300);
   set("kee",300);
   set("eff_kee",300);
   set("sen",300);
   set("eff_sen",300);
   set("force",300);
   set("max_force",300);
   set("chat_chance",30);
   set("chat_msg",({
    (:random_move:),
   }));
   
  setup();
  
}

void die()
{
   object ob,book;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   
   if(ob->query("id")!=query("target_id"))
    return ::die();
   
   book=new(__DIR__"obj/jingshu");
   book->move(ob);
   tell_object(ob,"���"+query("name")+"�������ѵ��˱����顣\n");
    
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
   
   JOBNPC_D->set_cyjsjob_killer(this_object(),ob);   
   
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