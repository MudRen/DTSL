
inherit NPC;
#include <job_money.h>
#include <ansi.h>
#include "npc_list.h"
string give_job();
void create()
{
   set_name("�Ų���",({ "wen caiting","wen" }) );
        set("gender", "Ů��" );
		
        set("age", 32);
   set("long", "���������ɵ��Ų��ã�����ħ���ڽ�����Ҳ�Ƿǳ�������\n");
       
   set("combat_exp",500000);
   set("str", 25);
   set("per", 25);
   set("attitude", "peaceful");
   set_skill("unarmed",170);
   set_skill("dodge",170);
   set_skill("parry",170);
   set_skill("force",170);
   set_skill("sword",170);
   set_skill("strike",170);
   set_skill("cuff",170);
   set_skill("literate",170);
   set_skill("jiutian-huanzhang",170);
   set_skill("tianmo-dafa",170);
   set_skill("tianmo-jianfa",170);
   set_skill("tianmo-huanzong",170);
   set_skill("tianmo-dai",170);  
   set("gin",3000);
   set("max_gin",3000);
   set("kee",3000);
   set("max_kee",3000);
   set("sen",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   create_family("������",2,"����");
   set("class","yin3");
   set("inquiry",([
	
	   "����":(:give_job:),
	 
	   ]));  
   setup();
  
}

string give_job()
{
	object me,letter;string str;
	string *npc_home;
	int i;
	
	me=this_player();
	if(me->query_temp("zhu_sx")) return "�㻹�����������е��Ű�!\n";
	if((string)me->query("family/family_name")=="�Ⱥ���ի")
        {
	      return "�Ⱥ���ի���������ǲ������ģ�\n";
	}
	if(time()-me->query("busy_time")<=120)
		return "�㻹����ЪЪ�ɣ�\n";
	if(me->query_temp("dtsl_job"))
	return "���������������񣬻�����æ�����İɣ�\n";	
        npc_home=keys(npc_list);
        i=random(sizeof(npc_home));
	letter=new(__DIR__"letter");
	letter->set("npc_home",npc_home[i]);
	letter->set("long","����һ���͸�"+HIC+npc_list[npc_home[i]]+NOR+"���š�\n");
	letter->set("owner",me);
	letter->move(me);
	me->set_temp("zhu_sx",1);
	me->set_temp("dtsl_job","������������");
	if((int)me->query("combat_exp",1)>=200000)
	   {	call_out("killer_come1",10,me);
            str="·�Ͽ�ҪС�ģ�\n";
	}
	else str="";
	tell_object(me,query("name")+"����һ��"+letter->query("name")+"��\n");
	return "�ðɣ��鷳����Ұ����"+letter->query("name")+CYN+"�͸�"+npc_list[npc_home[i]]+"��ǧ��Ҫ��©����Ϣ��\n"+
	       str;
	
	 
}

void killer_come1(object me)
{
	object killer,letter;
	object weapon;
	int exp;
	if(!objectp(me)||!me->query_temp("zhu_sx")) {return;}
	if(!objectp(weapon=me->query_temp("weapon")))
	killer=new(__DIR__"killer");
	else {killer=new(__DIR__"killer"+weapon->query("skill_type"));
	      }
	if(objectp(letter=present("letter",me))){	
	letter->move(killer);
	tell_object(me,HIW"���������������!\n"NOR);}
	copy_object(killer,me);
	killer->create_name(killer);
	killer->delete("nickname");
	killer->delete("family");
	killer->delete("title");
	killer->set_temp("apply/armor",50+random(50));
	killer->move(environment(me));
	message_vision("$N������:а��֮��������!\n",killer);
	killer->kill_ob(me);
    killer->set("target_id",me->query("id"));
	killer->set_leader(me);
	call_out("killer_go",180,killer);
	
	if(me->query("combat_exp")>500000)
	call_out("killer_come2",80,me);
	return;
}

void killer_come2(object me)
{
	object killer,letter;
	object weapon;
	int exp;
	if(!objectp(me)||!me->query_temp("zhu_sx")) {return;}
	if(me->is_ghost()) return;
	if(!objectp(weapon=me->query_temp("weapon")))
	killer=new(__DIR__"killer");
	else {killer=new(__DIR__"killer"+weapon->query("skill_type"));
	      }
	if(objectp(letter=present("letter",me))){
	letter->move(killer);
	tell_object(me,HIW"���������������!\n"NOR);}
	copy_object(killer,me);
	killer->create_name(killer);
	killer->delete("nickname");
	killer->delete("family");
	killer->delete("title");
	killer->set_temp("apply/armor",50+random(50));
	killer->move(environment(me));
	message_vision("$N������:а��֮��������!\n",killer);
	killer->kill_ob(me);
    killer->set("target_id",me->query("id"));
	killer->set_leader(me);
	call_out("killer_go",120,killer);
	
	return;
}

void killer_go(object killer)
{
	if(!objectp(killer))
	{ return;}
	message_vision("$N�Ҵ���ȥ�ˣ�\n",killer);
	destruct(killer);
     return;
}
