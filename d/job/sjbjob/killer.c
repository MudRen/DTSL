
inherit JOBNPC;

#include <ansi.h>
#include <job_money.h>



void create()
{
  
   set_name("��ͽ",({"pan tu","pan","tu"}) );
   set("gender", "����" );
        
   set("age", 30+random(10));
   set("long", "�����μұ�����ͽ��\n");
   set("combat_exp", 800000);
   set("str", 30);
   set("max_gin",1500);
   set("max_kee",1500);
   set("max_sen",1500);
   set("max_force",1500);
   set("force",1500);
  
   set("chat_chance",30);
   set("chat_msg",({
    (:random_move:),
   }));
   setup();
   
}

void die()
{
  object ob;
  ob=this_object()->query_temp("last_damage_from");
  
  if(!objectp(ob)) return ::die();
  
  if(ob->query("id")!=query("target_id"))
  return ::die();
  
  ob->set_temp("song_kill_pantu_ok",1);
  return ::die();
}

int kill_object(object killer,object victim)
{
  message_vision("$N��Ц��������Ҳ��ץ�ң���������\n",killer);
  message_vision("$N����һ�Σ��ټ�������\n",killer);
  destruct(killer);
  return 1;
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
   
   JOBNPC_D->set_sjbptjob_killer(this_object(),ob);
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