
inherit F_MASTER;
inherit NPC;
#include <ansi.h>
#include <job_money.h>
string give_job();
string do_quest();
string move_room();
void create()
{
   set_name("祝玉妍",({ "zhu yuyan","zhu","yu","yan" }) );
        set("gender", "女性" );

        set("age", 42);
   set("long", "他是阴癸派的教主,她的武功在武林可是数一数二的。她的魔功更是独步天下!\n");

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
   create_family("阴癸派",1,"掌门");
   set("class","yin3");
   set("inquiry",([
	   "毒药":"你只可以在丹房炼制(lianzhi)毒龙散!\n",
	   "送信":(:give_job:),
	   "阴癸尊者":(:do_quest:),
	   "密室":(:move_room:),
	   ]));
   set("chat_chance_combat",50);
   set("chat_msg_combat",({
	   (:apply_action,"tianmo-jianfa",4,10:),
   }));
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();

}
void attempt_apprentice(object ob)
{

	if(ob->query("bellicosity")<200)
	{
		tell_object(ob,"祝玉妍冷笑道:像你这种正派人士,休想拜我为师!\n");
		return;
	}
	if((int)ob->query_skill("tianmo-dafa",1)<180)
	{
		tell_object(ob,"你的[天魔大法]火候还未到,怎能拜我为师?\n");
		return;
	}
	command("say 好,只要在阴癸派好好干,保证你将来啸傲江湖!\n");
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
	if(me->query_temp("zhu_sx")) return "你还是先送完手中的信吧!\n";
	if((string)me->query("family/family_name")=="慈航静斋")
	{
		ob->kill_ob(me);
		return "慈航静斋的人也敢来撒野!\n";
	}
	if(time()-me->query("busy_time")<=90)
		return "你还是先歇歇吧！\n";
	if(time()-ob->query_temp("interrupt")<15)
	 return "你先等一会，刚刚有人帮忙了。\n";
	me->set("busy_time",time());
	ob->set_temp("interrupt",time());
	letter=new(__DIR__"letter");
	letter->move(me);
	if((int)me->query("combat_exp",1)>=200000)
	   {	call_out("killer_come1",10,me);
            str="路上可要小心！\n";
	}
	else str="";
	switch(random(5))
	{
     case 0:me->set_temp("zhu_sx/1",1);return "好吧,你去把这封信送到洛阳上官龙手中,他可是我们在洛阳的耳目!\n"+str;
	 case 1:me->set_temp("zhu_sx/2",1);return "好吧,你去把这封信送到襄阳的白清儿手中,他可是我们在襄阳的耳目!\n"+str;
	 case 2: me->set_temp("zhu_sx/3",1);return "好吧,你去把这封信送到洛阳的郑石如手中,他可是我们在洛阳的耳目!\n"+str;
	 case 3: me->set_temp("zhu_sx/4",1);return "好吧,你去把这封信送到洛阳的荣姣姣手中,她可是我们在洛阳的耳目!\n"+str;
	 case 4: me->set_temp("zhu_sx/5",1);return "好吧,你去把这封信送到巴陵的季亦农手中,他可是我们在巴陵的耳目!\n"+str;
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
	tell_object(me,"剑客抢走了你的信!\n");}
	copy_object(killer,me);
	killer->create_name(killer);
	killer->delete("nickname");
	killer->delete("family");
	killer->delete("title");
	killer->move(environment(me));
	message_vision("$N大声道:邪教之人拿命来!\n",killer);
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
	tell_object(me,"剑客抢走了你的信!\n");}
	copy_object(killer,me);
	killer->create_name(killer);
	killer->move(environment(me));
	message_vision("$N大声道:邪教之人拿命来!\n",killer);
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
	message_vision("$N匆匆离去了！\n",killer);
	destruct(killer);
     remove_call_out("killer_go");return;
}
//force quest
string do_quest()
{
  object ob;
  ob=this_player();
  if(ob->query_skill("tianmo-dafa",1)<300)
  return "你的功夫太低了，现在还无法超越的！\n";
  if(ob->query("family_lingwu")=="yingui")
  return "长江后浪推前浪，你已经超越我了，还是快去领悟吧！\n";
  ob->set_temp("gage_zhu",1);
  return "好啊，你想成为阴癸尊者，必须先打赢我[fight zhu]\n";
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_zhu"))
   return 1;
   message_vision(HIR"$N仰天长笑道：我魔界终于后继有人了！\n"NOR,victim);
   message_vision(HIR"$N突然脸色一变，既然能打得过我，你就去我的密室学习吧！\n"NOR,victim);
   killer->set("family_lingwu","yingui");
   killer->set("title",HIR"阴癸尊者"NOR);
   killer->move(__DIR__"mishi");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_zhu"))
   return 1;
  message_vision("$N朝$n叹了口气，你还是回去再磨练磨练吧！\n",killer,victim);
  return 1;
}
string move_room()
{
  object ob;
  ob=this_player();
  ob->move(__DIR__"mishi");
  return "但愿你能让我们魔教纵横江湖，一统武林！\n";
}
