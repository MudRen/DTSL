
inherit JOBNPC;

#include <job_money.h>

void create()
{
   set_name("ɱ��",({ "killer" }) );
   set("gender", "����" );
   
   set("dex",20+random(10));
   set("str",20+random(10));
  
   set_temp("apply/dodge",50+random(50));
   set_temp("apply/armor",50+random(50));
  
   setup();
  
}


int set_status(object ob,int lev)
{
  
  JOBNPC_D->set_bsyquest_killer(this_object(),ob,lev);
  return 1;
}

void die()
{
   object ob;
   object killer;
   
   ob=query_temp("last_damage_from");
   if(!ob)
   return ::die();
   
   ob->add_temp("do_bsyquest_killer",1);
   ob->add_temp("do_bsyquest_lev",1);
   
   killer = new(__DIR__"killer");
   killer->set_status(ob,ob->query_temp("do_bsyquest_lev"));
   killer->move(environment(ob));
   message_vision("\n$N�ȵ����ù������������һ�£�\n\n",killer);
   killer->kill_ob(ob);
   
   return ::die();
}

int stop_kill(object killer,object victim)
{
	
	killer->remove_killer(victim);
	victim->remove_killer(killer);
	victim->set("kee",10);
	victim->set("eff_kee",10);
	victim->unconcious();
	return 1;	
	
}
