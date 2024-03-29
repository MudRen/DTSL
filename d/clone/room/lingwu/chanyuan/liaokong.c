
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string do_quest();
string give_key();
void create()
{
   set_name("了空",({ "liao kong","liao","kong"}));
        set("gender", "男性" );
        set("age", 52);
   set("long", "他就是净念禅院的主持了空大师。\n");
   set("class","bonze");
   set("combat_exp",4000000);
   set("str", 28);
   set("per", 22);
  set("attitude", "peaceful");
   set_skill("dodge",300);
   set_skill("parry",300);
   set_skill("staff",300);
   set_skill("unarmed",300);
   set_skill("tiangang-quan",300);
   set_skill("cuff",300);
   set_skill("dujie-zhi",300);
   set_skill("finger",300);
   set_skill("literate",300);
   set_skill("chanzong-fofa",300);
   set_skill("force",300);
   set_skill("liuyun",300);
   set_skill("bikouchan",300);
  //  set_skill("wuxiang-zhangfa",300);
   set_skill("blade",300);
  //  set_skill("jinguang-daofa",300);
  //  set("staff",({"wuxiang-zhangfa"}));
   set("dodge",({"liuyun"}));
   set("hand",({"tiangang-quan","dujie-zhi"}));
   set("jiali",30);
   set("gin",6000);
   set("max_gin",6000);
   set("kee",6000);
   set("max_kee",6000);
   set("sen",6000);
   set("max_sen",6000);
   set("force",6000);
   set("max_force",6000);
   create_family("静念禅院",3,"掌门");
   set("chat_chance_combat",50);
   set("chat_msg_combat",({
	   (:apply_action,"wuxiang-zhangfa",1,9:),
	   (:apply_action,"wuxiang-zhangfa",3,9:),
	   (:apply_action,"tiangang-quan",3,9:),
	   (:apply_action,"dujie-zhi",3,9:),
	   (:perform_action,"fumo":),
	   (:perform_action,"dujie":),
	   (:perform_action,"pomo":),
   }));
   set("inquiry",([
     "超越":(:do_quest:),
     "密室":(:give_key:),
     ]));
   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();

}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())) return;
	if(!wizardp(ob)&&ob->query("family/family_name")!="静念禅院")
		call_out("kill_thief",1,ob,ob2);
	else call_out("welcome",1,ob,ob2);

}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())) return;
	switch(random(2))
	{
	case 0: message_vision("$N低声诵道：阿弥陀佛!\n",ob2);break;
	case 1: message_vision("$N对$n道：佛渡有缘人。\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}

void kill_thief(object ob,object ob2)
{
	if(!ob||!present(ob,environment())) return;
	message_vision("$N朝$n大声说道：施主为和要来搅这汤混水呢!\n",ob2,ob);
	ob2->kill_ob(ob);
	remove_call_out("kill_thief");
}

void attempt_apprentice(object ob)
{
	string name,new_name;
	if(ob->query("family"))
		if(ob->query("family/family_name")!="静念禅院")
		{tell_object(ob,"你已经其他门派的人了!\n");return;}
	if(ob->query("gender")=="女性")
	{
		tell_object(ob,"了空笑道:我们禅院只收男弟子的,施主如果一心向佛,可以去慈航静斋.\n");
		return;
	}
	if((int)ob->query("PKS",1)>=5)
	{
		tell_object(ob,"了空双手合十道:施主,你的杀气太重,我怎么收你呢?\n");
		return;
	}
	if((int)ob->query_skill("bikouchan",1)<150)
	{
		tell_object(ob,"施主你的[闭口禅]火侯未到,叫我如何收你?\n");
		return;
	}
	name=ob->query("name");
	new_name="了"+name[2..3];
	ob->set("name",new_name);
	command("say 阿弥陀佛!希望施主今后能超度世人的苦恼,成为一代高僧,光大佛法!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
}

string do_quest()
{
  object ob;
  ob=this_player();
  if(ob->query_skill("bikouchan",1)<300)
  return "你的功夫太低了，现在还无法超越的！\n";
  if(ob->query("family_lingwu")=="chanyuan")
  return "长江后浪推前浪，你已经超越我了，还是快去领悟吧！\n";
  ob->set_temp("gage_liaokong",1);
  return "好小子，有骨气，不过你要想超越我，就必须赢我[fight liao]\n";
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_liaokong"))
   return 1;
   message_vision(YEL"$N拍了拍$n的肩膀，我佛终于后代有人了！我告诉你一个秘密！\n"NOR,victim,killer);
   tell_object(killer,"了空凑到你的跟前，对你耳语道：我佛前辈曾留下一个密室，现在就看你的造化了！\n");
   ob=new(__DIR__"key");
   ob->move(killer);
   killer->set("family_lingwu","chanyuan");
   killer->set("title",HIY"静念圣僧"NOR);
   tell_object(killer,"了空给了你一个黄金钥匙。\n");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_liaokong"))
   return 1;
  message_vision("$N朝$n叹了口气，你还是回去再磨练磨练吧！\n",killer,victim);
  return 1;
}
string give_key()
{
  object ob,key;
  ob=this_player();
  if(ob->query("family_lingwu")!="chanyuan")
  return "你在说什么，贫僧可是一点都不懂啊！\n";
  if(objectp(key=present("key",ob)))
    if(key->query("unique"))
    return "你已经有钥匙了，快去学习吧！\n";
  key=new(__DIR__"key");
  key->move(ob);
  tell_object(ob,"了空给了你一个黄金钥匙。\n");
  return "希望你能光大佛法，造福百姓！\n";
}
