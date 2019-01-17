
inherit JOBNPC;
#include <ansi.h>
#include <job_money.h>

void create()
{
   set_name("����",({ "jian ke","jian","ke","fu" }) );
   set("gender", "Ů��" );
   set("long", "����һλŮ���͡�\n");
       
   set("combat_exp",50000);
   set("str", 25);
   set("per", 25);
 
   set("gin",300);
   set("eff_gin",300);
   set("kee",300);
   set("eff_kee",300);
   set("sen",300);
   set("eff_sen",300);
   set("force",300);
   set("max_force",300);
  
   setup();
   
}

int set_status(object me)
{
	
JOBNPC_D->set_ygjob_killer(this_object(),me);
	
}

int kill_object(object killer,object victim)
{
 if(killer->query("target_id")==victim->query("id"))
{
 message_vision("$Nһ����Ц������аħ�������������Ҳ�ǻ�ã�\n",killer);
 victim->delete_temp("zhu_sx");
 return 1;
}
return 1;
}

void die()
{
   object ob;
   ob=query_temp("last_damage_from");
   if(ob)
   if(query("target_id")==ob->query("id"))
     ob->add_temp("need_killer_flags",1);
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
  
   if(clear())
   return 1;
   
   return ::chat();
}

