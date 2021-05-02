
inherit NPC;

void create()
{
   set_name("不喷",({ "bu pen","bu","pen"}));
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是净念禅院的四大护法金刚之一。\n");
   set("class","bonze");
   set("combat_exp", 400000);
   set("str", 28);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("dodge",80);
   set_skill("parry",90);
   set_skill("staff",90);
   set_skill("blade",150);
   set_skill("force",150);
   set_skill("chanzong-fofa",150);
   // set_skill("jinguang-daofa",150);
   // set_skill("wuxiang-zhangfa",90);
   set("staff",({"wuxiang-zhangfa"}));
   set_skill("liuyun",150);
   set("dodge",({"liuyun"}));
    create_family("静念禅院",4,"护法");
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
	if(present("heshi bi",ob))
		call_out("kill_thief",1,ob,ob2);
	call_out("welcome",1,ob,ob2);

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
