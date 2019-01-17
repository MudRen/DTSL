
inherit JOBNPC;

#include <job_money.h>

void create()
{
        set_name("��ͷ", ({"bu tou","bu","tou"}));
        set("gender", "����");
        set("age", 34);
        set("long","����һ���Ĳ�ͷ��ר�ż���ɱ�˷���\n");
        set("str", 30);
        set("int", 30);
        set("dex", 30);
        set("con", 30);
 
        set("max_kee",3000);
        set("max_gin",3000);
        set("max_sen",3000);
        set("force",3000);
	set("max_force",3000);
        set("combat_exp",800000);
       
        set_temp("apply/dodge", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);
	set("chat_chance",40);
	set("chat_msg",({
	    (:random_move:),
	}));
	
	set_this_skills("high");
	set_all_skill(this_object(),200);
        setup();
       
		
}

void init()
{
	object *ob,here;
	int i;
	
	here=environment(this_object());
	if(!here) return;
	ob=all_inventory(here);
	
	for(i=0;i<sizeof(ob);i++)
	{
		if( (ob[i]->query("PKS")>=6||ob[i]->query("pker"))
		   &&!is_fighting() ){
		   	remove_call_out("kill_pker");
			call_out("kill_pker",1,ob[i]);
		}
	}
}

void kill_pker(object ob)
{
	if(!ob)
	return;
	if(environment(ob)!=environment(this_object()))
	return;
	
	command("heng "+ob->query("id"));
	command("say ��ɱ��̫���ˣ���������\n");
	set_leader(ob);
	kill_ob(ob);
	
}