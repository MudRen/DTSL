
inherit JOBNPC;
#include <job_money.h>


void init()
{
	object *ob,here,me;
	int i;
	
	me=this_object();
	here=environment(me);
	if(!here) return;
	ob=all_inventory(here);
	
	for(i=0;i<sizeof(ob);i++)
	{
	
         if(ob[i]->query("killer")==me->query("guard"))
		call_out("kill_killer",1,ob[i],me);
	 else if(ob[i]->query("pker"))
	      call_out("kill_pker",0,ob[i],me);
	 else if((int)ob[i]->query("beipan",1)>=3)
		call_out("kill_pantu",1,ob[i],me);
	}
	return;
}

void kill_pantu(object ob,object ob2)
{
	if(!ob||!ob2
	  ||!environment(ob)
	  ||!environment(ob2)
	  ||environment(ob)!=environment(ob2))
	return;
	
	message_vision("\n$N��$n��Ц��:�������ֶ����������ͽ���������ߣ�\n\n",ob2,ob);
	if(!ob->is_busy())
         ob->start_busy(1);
        ob2->kill_ob(ob);
	
	return;
}
void kill_killer(object ob,object ob2)
{
	if(!ob||!ob2
	  ||!environment(ob)
	  ||!environment(ob2)
	  ||environment(ob)!=environment(ob2))
	return;
	
	message_vision("\n$N��$n��Ц��:�������������ߣ�\n\n",ob2,ob);
	if(!ob->is_busy())
         ob->start_busy(1);
        ob2->kill_ob(ob);
}

void kill_pker(object ob,object ob2)
{
	if(!ob||!ob2
	  ||!environment(ob)
	  ||!environment(ob2)
	  ||environment(ob)!=environment(ob2))
	return;
	
	message_vision("\n$N��$n��Ц��:ɱ�˷����������ߣ�\n\n",ob2,ob);
	if(!ob->is_busy())
  	ob->start_busy(3);
  
  ob2->kill_ob(ob);
}

int is_defence_guard()
{
	return 1;
}