
inherit JOBNPC;
#include <ansi.h>
#include <job_money.h>



void create()
{
  
   set_name("����",({"hu wei","hu","wei"}));
   set("gender", "����" );
   set("nickname","����");
   set("age", 32);
   set("long", "����һ���ܹ��ڱ�����Ļ�����\n");
   set("combat_exp", 800000);
   set("str", 20);
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("max_force",1000);
   set("force",1000);
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
  if(query("target_id")!=ob->query("id"))
  return ::die();
  ob->set_temp("have_killed_killer",1);
  return ::die();
}

int kill_object(object killer,object victim)
{
  message_vision("$N��ƾ��Ҳ�������ˣ����ǿ�Ц����\n",killer);
  message_vision("$N����һ�Σ��ټ�������\n",killer);
  destruct(killer);
  return 1;
}

int set_status(object ob)
{
   
 JOBNPC_D->set_dmszjob_killer(this_object(),ob);  
 return 1;
}

int clear()
{
  if(time()-query("last")<4000)
  return 0;
  if(!query("no_msg")){
  message_vision("$N̾����û��˼��ȥ��ط�תת��\n",this_object());
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
   
   if(clear())
   return 1;
   
   return ::chat();
}