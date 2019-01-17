
inherit F_MASTER;
inherit NPC;
#include <job_money.h>
string give_job();
string do_quest();
string move_room();
void create()
{
   set_name("ף����",({ "zhu yuyan","zhu","yu","yan" }) );
        set("gender", "Ů��" );
		
        set("age", 42);
   set("long", "���������ɵĽ���,�����书�����ֿ�����һ�����ġ�����ħ�����Ƕ�������!\n");
       
   set("combat_exp",2000000);
   set("str", 25);
   set("per", 28);
   set("attitude", "peaceful");
   set_skill("unarmed",300);
   set_skill("dodge",300);
   set_skill("parry",300);
   set_skill("force",300);
   set_skill("sword",300);
   set_skill("strike",300);
   set_skill("cuff",300);
   set_skill("literate",300);
   set_skill("jiutian-huanzhang",300);
   set_skill("linglong-yuquan",300);
   set_skill("tianmo-dafa",300);
   set_skill("tianmo-jianfa",300);
   set_skill("tianmo-huanzong",300);
   set_skill("tianmo-dai",300);
   set("hand",({"tianmo-dai","jiutian-huanzhang","linglong-yuquan"}));
   set("dodge",({"tianmo-huanzong"}));
   set("force_skill",({"tianmo-dafa"}));
   set("sword",({"tianmo-jianfa"}));
   set("gin",6000);
   set("max_gin",6000);
   set("kee",6000);
   set("max_kee",6000);
   set("sen",6000);
   set("max_sen",6000);
   set("force",6000);
   set("max_force",6000);
   create_family("������",1,"����");
   set("class","yin3");
   set("inquiry",([
	   "��ҩ":"��ֻ�����ڵ�������(lianzhi)����ɢ!\n",
	   "����":(:give_job:),
	   "��������":(:do_quest:),
	   "����":(:move_room:),
	   ]));
   set("chat_chance_combat",50);
   set("chat_msg_combat",({
	   (:apply_action,"tianmo-jianfa",4,10:),
   }));
   setup();
   carry_object(__DIR__"caiyi")->wear();
   carry_object(__DIR__"changjian")->wield();
  
}
void attempt_apprentice(object ob)
{
	
	if(ob->query("bellicosity")<200)
	{
		tell_object(ob,"ף������Ц��:��������������ʿ,�������Ϊʦ!\n");
		return;
	}
	if((int)ob->query_skill("tianmo-dafa",1)<180)
	{
		tell_object(ob,"���[��ħ��]���δ��,���ܰ���Ϊʦ?\n");
		return;
	}
	command("say ��,ֻҪ�������ɺúø�,��֤�㽫��Х������!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin3");
}

string give_job()
{
	object me,ob,letter;string str;
	me=this_player();ob=this_object();
	if(me->query_temp("zhu_sx")) return "�㻹�����������е��Ű�!\n";
	if((string)me->query("family/family_name")=="�Ⱥ���ի")
	{
		ob->kill_ob(me);
		return "�Ⱥ���ի����Ҳ������Ұ!\n";
	}
	if(time()-me->query("busy_time")<=90)
		return "�㻹����ЪЪ�ɣ�\n";
	if(time()-ob->query_temp("interrupt")<15)
	 return "���ȵ�һ�ᣬ�ո����˰�æ�ˡ�\n";
	me->set("busy_time",time());
	ob->set_temp("interrupt",time());
	letter=new(__DIR__"letter");
	letter->move(me);
	if((int)me->query("combat_exp",1)>=200000)
	   {	call_out("killer_come1",10,me);
            str="·�Ͽ�ҪС�ģ�\n";
	}
	else str="";
	switch(random(5))
	{
     case 0:me->set_temp("zhu_sx/1",1);return "�ð�,��ȥ��������͵������Ϲ�������,�����������������Ķ�Ŀ!\n"+str;
	 case 1:me->set_temp("zhu_sx/2",1);return "�ð�,��ȥ��������͵������İ��������,�����������������Ķ�Ŀ!\n"+str;
	 case 2: me->set_temp("zhu_sx/3",1);return "�ð�,��ȥ��������͵�������֣ʯ������,�����������������Ķ�Ŀ!\n"+str;
	 case 3: me->set_temp("zhu_sx/4",1);return "�ð�,��ȥ��������͵���������������,�����������������Ķ�Ŀ!\n"+str;
	 case 4: me->set_temp("zhu_sx/5",1);return "�ð�,��ȥ��������͵�����ļ���ũ����,�����������ڰ���Ķ�Ŀ!\n"+str;
	}
	 
}

void killer_come1(object me)
{
	object killer,letter1,letter2;
	object weapon;
	int exp;
	if(!objectp(me)||!me->query_temp("zhu_sx")) {remove_call_out("killer_come1");return;}
	if(!objectp(weapon=me->query_temp("weapon")))
	killer=new(__DIR__"killer");
	else {killer=new(__DIR__"killer"+weapon->query("skill_type"));
	      }
	letter1=new(__DIR__"letter");
	if(objectp(letter2=present("letter",me))){
	destruct(letter2);
	letter1->move(killer);
	tell_object(me,"���������������!\n");}
	copy_object(killer,me);
	killer->create_name(killer);
	killer->delete("nickname");
	killer->delete("family");
	killer->delete("title");
	killer->move(environment(me));
	message_vision("$N������:а��֮��������!\n",killer);
	killer->kill_ob(me);
	killer->set_leader(me);
	call_out("killer_go",180,killer);
	remove_call_out("killer_come1");
	if(me->query("combat_exp")>500000)
	call_out("killer_come2",80,me);
	return;
}

void killer_come2(object me)
{
	object killer,letter1,letter2;
	object weapon;
	int exp;
	if(!objectp(me)||!me->query_temp("zhu_sx")) {remove_call_out("killer_come1");return;}
	if(!objectp(weapon=me->query_temp("weapon")))
	killer=new(__DIR__"killer");
	else {killer=new(__DIR__"killer"+weapon->query("skill_type"));
	      }
	letter1=new(__DIR__"letter");
	if(objectp(letter2=present("letter",me))){
	destruct(letter2);
	letter1->move(killer);
	tell_object(me,"���������������!\n");}
	copy_object(killer,me);
	killer->create_name(killer);
	killer->move(environment(me));
	message_vision("$N������:а��֮��������!\n",killer);
	killer->kill_ob(me);
	killer->set_leader(me);
	call_out("killer_go",120,killer);
	remove_call_out("killer_come2");
	
	return;
}

void killer_go(object killer)
{
	if(!objectp(killer))
	{ remove_call_out("killer_go");return;}
	message_vision("$N�Ҵ���ȥ�ˣ�\n",killer);
	destruct(killer);
     remove_call_out("killer_go");return;
}
//force quest
string do_quest()
{
  object ob;
  ob=this_player();
  if(ob->query_skill("tianmo-dafa",1)<300)
  return "��Ĺ���̫���ˣ����ڻ��޷���Խ�ģ�\n";
  if(ob->query("family_lingwu")=="yingui")
  return "����������ǰ�ˣ����Ѿ���Խ���ˣ����ǿ�ȥ����ɣ�\n";
  ob->set_temp("gage_zhu",1);
  return "�ð��������Ϊ�������ߣ������ȴ�Ӯ��[fight zhu]\n";
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_zhu"))
   return 1;
   message_vision(HIR"$N���쳤Ц������ħ�����ں�������ˣ�\n"NOR,victim);
   message_vision(HIR"$NͻȻ��ɫһ�䣬��Ȼ�ܴ�ù��ң����ȥ�ҵ�����ѧϰ�ɣ�\n"NOR,victim); 
   killer->set("family_lingwu","yingui");
   killer->set("title",HIR"��������"NOR);
   killer->move(__DIR__"mishi");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_zhu"))
   return 1;
  message_vision("$N��$n̾�˿������㻹�ǻ�ȥ��ĥ��ĥ���ɣ�\n",killer,victim);
  return 1;
}
string move_room()
{
  object ob;
  ob=this_player();
  ob->move(__DIR__"mishi");
  return "��Ը����������ħ���ݺὭ����һͳ���֣�\n";
}